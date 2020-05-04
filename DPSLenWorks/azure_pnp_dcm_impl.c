/*******************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 *
 * You need to add your implementation here to:
 *    - get telemetry data from device/sensor
 *    - set read-only property data
 *    - handle read-write property callback
 *    - process device command
 *
 * Generated Date: 05/04/2020
 *******************************************************************************************/

#include "azure_pnp_dcm_impl.h"
#include "utilities/digitaltwin_serializer.h"
#include "utilities/lenworks_interface_a_interface.h"
#include "utilities/deviceinfo_interface.h"

#define Payload_Buffer_Size 256

void SendTelemetry_Succeeded_Callback(const char* interfaceName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on success.

    LogInfo("DigitalTwin successfully delivered telemetry message for component %s", interfaceName);
}

void SendTelemetry_Error_Callback(const char* interfaceName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on failure.

    LogInfo("DigitalTwin failed to deliver telemetry message for %s", interfaceName);
}

void ReportProperty_Succeeded_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback reporting property on success.

    LogInfo("DigitalTwin successfully report writable property for %s::%s", interfaceName, propertyName);
}

void ReportProperty_Error_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback of reporting property on failure.

    LogInfo("DigitalTwin failed to report writable property for %s::%s", interfaceName, propertyName);
}

double Lenworks_interface_a_Telemetry_ReadTemperature()
{
    // TODO: provide implementation here
    return 0.0;
}

void Lenworks_interface_a_Telemetry_ReadMagnetometer(LENWORKS_INTERFACE_A_MAGNETOMETER * magnetometer)
{
    // TODO: provide implementation here

    magnetometer->x = 0;

    magnetometer->y = 0;

    magnetometer->z = 0;

}

char* Lenworks_interface_a_Property_GetName()
{
    // TODO: provide implementation here
    return "abc";
}

bool Lenworks_interface_a_Property_FanSpeedCallback(double fanSpeed)
{
    // TODO: provide implementation here
    LogInfo("FanSpeed property new value: %f", fanSpeed);
    return true;
}

DIGITALTWIN_COMMAND_RESULT Lenworks_interface_a_Command_Blink(long interval, LENWORKS_INTERFACE_A_BLINK_blinkResponse* response, unsigned int* statusCode)
{
    // TODO: provide implementation here
    // You need to process the device command, and set the command response and statusCode correspondingly.
    // Finally, return DIGITALTWIN_COMMAND_OK if the command execution succeeded, or 'DIGITALTWIN_COMMAND_ERROR' on failure.

    LogInfo("Parameter: interval = %ld", interval);

    // Set command response and status code

    response->description = "abc";

    *statusCode = 200;
    LogInfo("Device executed 'blink' command successfully");
    return DIGITALTWIN_COMMAND_OK;
}

char* DeviceInfo_Property_GetManufacturer()
{
    // TODO: provide implementation here
    return "abc";
}

char* DeviceInfo_Property_GetModel()
{
    // TODO: provide implementation here
    return "abc";
}

char* DeviceInfo_Property_GetSwVersion()
{
    // TODO: provide implementation here
    return "abc";
}

char* DeviceInfo_Property_GetOsName()
{
    // TODO: provide implementation here
    return "abc";
}

char* DeviceInfo_Property_GetProcessorArchitecture()
{
    // TODO: provide implementation here
    return "abc";
}

char* DeviceInfo_Property_GetProcessorManufacturer()
{
    // TODO: provide implementation here
    return "abc";
}

long DeviceInfo_Property_GetTotalStorage()
{
    // TODO: provide implementation here
    return 0L;
}

long DeviceInfo_Property_GetTotalMemory()
{
    // TODO: provide implementation here
    return 0L;
}
