/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 05/04/2020
 ***********************************************************************************************/

#ifndef DIGITALTWIN_SERIALIZER
#define DIGITALTWIN_SERIALIZER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "azure_c_shared_utility/xlogging.h"
#include "parson.h"

#include "../azure_pnp_dcm_impl.h"

#ifdef __cplusplus
extern "C"
{
#endif

bool Lenworks_interface_a_SerializeTemperatureTelemetry(char * payloadBuffer, int size);

bool Lenworks_interface_a_SerializeMagnetometerTelemetry(char * payloadBuffer, int size);

bool Lenworks_interface_a_SerializeNameProperty(char * payloadBuffer, int size);

bool Lenworks_interface_a_SerializeBlinkCommandResponse(LENWORKS_INTERFACE_A_BLINK_blinkResponse* response, char* payloadBuffer, int size);

bool DeviceInfo_SerializeManufacturerProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeModelProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeSwVersionProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeOsNameProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeProcessorArchitectureProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeProcessorManufacturerProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeTotalStorageProperty(char * payloadBuffer, int size);

bool DeviceInfo_SerializeTotalMemoryProperty(char * payloadBuffer, int size);

#ifdef __cplusplus
}
#endif

#endif // DIGITALTWIN_SERIALIZER
