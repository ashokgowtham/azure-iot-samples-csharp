/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 05/04/2020
 ***********************************************************************************************/

#ifndef LENWORKS_INTERFACE_A_INTERFACE_H
#define LENWORKS_INTERFACE_A_INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "digitaltwin_interface_client.h"
#include "azure_c_shared_utility/xlogging.h"
#include "azure_c_shared_utility/threadapi.h"

#include "digitaltwin_client_helper.h"
#include "digitaltwin_serializer.h"
#include "parson.h"
#include "../azure_pnp_dcm_impl.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum LENWORKS_INTERFACE_A_TELEMETRY_TAG
{
    Lenworks_interface_a_TEMPERATURE_TELEMETRY,
    Lenworks_interface_a_MAGNETOMETER_TELEMETRY
} LENWORKS_INTERFACE_A_TELEMETRY;

typedef enum LENWORKS_INTERFACE_A_READONLY_PROPERTY_TAG
{
    Lenworks_interface_a_NAME_PROPERTY,
    Lenworks_interface_a_FANSPEED_PROPERTY
} LENWORKS_INTERFACE_A_PROPERTY;

// DigitalTwin interface name from service perspective.
static const char Lenworks_interface_aInterfaceId[] = "urn:lenworks:azure_pnp:1";
static const char Lenworks_interface_aInterfaceInstanceName[] = "lenworks_interface_a";

// Telemetry names for this interface.

static const char Lenworks_interface_aInterface_TemperatureTelemetry[] = "temperature";

static const char Lenworks_interface_aInterface_MagnetometerTelemetry[] = "magnetometer";

// Property names for this interface.

#define Lenworks_interface_aInterface_NameProperty "name"

#define Lenworks_interface_aInterface_FanSpeedProperty "fanSpeed"

// Command names for this interface

#define Lenworks_interface_aInterface_BlinkCommand "blink"

// Methods
DIGITALTWIN_INTERFACE_CLIENT_HANDLE Lenworks_interface_aInterface_Create();

void Lenworks_interface_aInterface_Close(DIGITALTWIN_INTERFACE_CLIENT_HANDLE digitalTwinInterfaceClientHandle);

DIGITALTWIN_CLIENT_RESULT Lenworks_interface_aInterface_Telemetry_SendAll();

DIGITALTWIN_CLIENT_RESULT Lenworks_interface_aInterface_Property_ReportAll();

DIGITALTWIN_CLIENT_RESULT Lenworks_interface_aInterface_Property_ReportName();

#ifdef __cplusplus
}
#endif

#endif  // LENWORKS_INTERFACE_A_INTERFACE_H
