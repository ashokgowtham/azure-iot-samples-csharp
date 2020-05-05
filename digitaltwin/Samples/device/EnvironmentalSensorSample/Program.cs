// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

using System;

using Microsoft.Azure.Devices.Client;
using Microsoft.Azure.Devices.DigitalTwin.Client;
using Microsoft.Azure.Devices.Provisioning.Client;
using Microsoft.Azure.Devices.Provisioning.Client.Samples;
using Microsoft.Azure.Devices.Provisioning.Client.Transport;
using Microsoft.Azure.Devices.Shared;
using System;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace EnvironmentalSensorSample
{
    class Program
    {

        // The Provisioning Hub IDScope.

        // For this sample either:
        // - pass this value as a command-prompt argument
        // - set the DPS_IDSCOPE environment variable 
        // - create a launchSettings.json (see launchSettings.json.template) containing the variable
        private static string s_idScope = Environment.GetEnvironmentVariable("DPS_IDSCOPE");

        // In your Device Provisioning Service please go to "Manage enrollments" and select "Individual Enrollments".
        // Select "Add individual enrollment" then fill in the following:
        // Mechanism: Symmetric Key
        // Auto-generate keys should be checked
        // DeviceID: iothubSymmetricKeydevice1

        // Symmetric Keys may also be used for enrollment groups.
        // In your Device Provisioning Service please go to "Manage enrollments" and select "Enrollment Groups".
        // Select "Add enrollment group" then fill in the following:
        // Group name: <your  group name>
        // Attestation Type: Symmetric Key
        // Auto-generate keys should be checked
        // You may also change other enrollment group parameters according to your needs

        private const string GlobalDeviceEndpoint = "global.azure-devices-provisioning.net";

        //These are the two keys that belong to your enrollment group. 
        // Leave them blank if you want to try this sample for an individual enrollment instead
        private const string enrollmentGroupPrimaryKey = "";
        private const string enrollmentGroupSecondaryKey = "";

        //registration id for enrollment groups can be chosen arbitrarily and do not require any portal setup. 
        //The chosen value will become the provisioned device's device id.
        //
        //registration id for individual enrollments must be retrieved from the portal and will be unrelated to the provioned
        //device's device id
        //
        //This field is mandatory to provide for this sample
        private static string registrationId = "";

        //These are the two keys that belong to your individual enrollment. 
        // Leave them blank if you want to try this sample for an individual enrollment instead
        private const string individualEnrollmentPrimaryKey = "";
        private const string individualEnrollmentSecondaryKey = "";

        public static int Main(string[] args)
        {
            if (args.Length < 3)
            {
                Console.WriteLine("ProvisioningDeviceClientSymmetricKey <IDScope> <Secret> <registration>");
                return 1;
            }

            s_idScope = args[0];
            individualEnrollmentPrimaryKey = individualEnrollmentSecondaryKey = args[1];
            registrationId = args[2];

            string primaryKey = "";
            string secondaryKey = "";
            if (!String.IsNullOrEmpty(registrationId) && !String.IsNullOrEmpty(enrollmentGroupPrimaryKey) && !String.IsNullOrEmpty(enrollmentGroupSecondaryKey))
            {
                //Group enrollment flow, the primary and secondary keys are derived from the enrollment group keys and from the desired registration id
                primaryKey = ComputeDerivedSymmetricKey(Convert.FromBase64String(enrollmentGroupPrimaryKey), registrationId);
                secondaryKey = ComputeDerivedSymmetricKey(Convert.FromBase64String(enrollmentGroupSecondaryKey), registrationId);
            }
            else if (!String.IsNullOrEmpty(registrationId) && !String.IsNullOrEmpty(individualEnrollmentPrimaryKey) && !String.IsNullOrEmpty(individualEnrollmentSecondaryKey))
            {
                //Individual enrollment flow, the primary and secondary keys are the same as the individual enrollment keys
                primaryKey = individualEnrollmentPrimaryKey;
                secondaryKey = individualEnrollmentSecondaryKey;
            }
            else
            {
                Console.WriteLine("Invalid configuration provided, must provide group enrollment keys or individual enrollment keys");
                return -1;
            }


            using (var _security = new SecurityProviderSymmetricKey(registrationId, primaryKey, secondaryKey))
            // Select one of the available transports:
            // To optimize for size, reference only the protocols used by your application.
            using (var transport = new ProvisioningTransportHandlerAmqp(TransportFallbackType.TcpOnly))
            // using (var transport = new ProvisioningTransportHandlerHttp())
            // using (var transport = new ProvisioningTransportHandlerMqtt(TransportFallbackType.TcpOnly))
            // using (var transport = new ProvisioningTransportHandlerMqtt(TransportFallbackType.WebSocketOnly))
            {
                ProvisioningDeviceClient _provClient =
                    ProvisioningDeviceClient.Create(GlobalDeviceEndpoint, s_idScope, security, transport);

                Console.WriteLine($"RegistrationID = {_security.GetRegistrationID()}");
                VerifyRegistrationIdFormat(_security.GetRegistrationID());

                Console.Write("ProvisioningClient RegisterAsync . . . ");
                DeviceRegistrationResult result = await _provClient.RegisterAsync().ConfigureAwait(false);

                Console.WriteLine($"{result.Status}");
                Console.WriteLine($"ProvisioningClient AssignedHub: {result.AssignedHub}; DeviceID: {result.DeviceId}");

                if (result.Status != ProvisioningRegistrationStatusType.Assigned) return;

                IAuthenticationMethod auth;
                if (_security is SecurityProviderTpm)
                {
                    Console.WriteLine("Creating TPM DeviceClient authentication.");
                    auth = new DeviceAuthenticationWithTpm(result.DeviceId, _security as SecurityProviderTpm);
                }
                else if (_security is SecurityProviderX509)
                {
                    Console.WriteLine("Creating X509 DeviceClient authentication.");
                    auth = new DeviceAuthenticationWithX509Certificate(result.DeviceId, (_security as SecurityProviderX509).GetAuthenticationCertificate());
                }
                else if (_security is SecurityProviderSymmetricKey)
                {
                    Console.WriteLine("Creating Symmetric Key DeviceClient authenication");
                    auth = new DeviceAuthenticationWithRegistrySymmetricKey(result.DeviceId, (_security as SecurityProviderSymmetricKey).GetPrimaryKey());
                }
                else
                {
                    throw new NotSupportedException("Unknown authentication type.");
                }

                // using (var deviceClient = DeviceClient.CreateFromConnectionString(deviceConnectionString, transportType))
                using (DeviceClient iotClient = DeviceClient.Create(result.AssignedHub, auth, TransportType.Amqp))
                {
                    //
                    DigitalTwinClient digitalTwinClient = new DigitalTwinClient(deviceClient);

                    if (digitalTwinClient == null)
                    {
                        Console.WriteLine("Failed to create DeviceClient!");
                        return 1;
                    }

                    var sample = new DigitalTwinClientSample(digitalTwinClient);
                    sample.RunSampleAsync().GetAwaiter().GetResult();

                    Console.WriteLine("Waiting to receive updates from cloud...");
                    Console.WriteLine("Press any key to exit");
                    Console.ReadLine();
                }
            }
            return 0;
        }
    }
}
