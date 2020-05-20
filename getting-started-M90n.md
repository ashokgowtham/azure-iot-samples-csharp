---
platform: Windows 7
device: ThinkCentre M90n Nano IoT
language: c
---

Connect ThinkCentre M90n Nano IoT device to your Azure IoT Central Application
===

---
# Table of Contents

-   [Introduction](#Introduction)
-   [Features implemented](#FeaturesImplemented)
-   [Prerequisites](#Prerequisites)
-   [Prepare the Device](#preparethedevice)
-   [Integration with IoT Central](#IntegrationwithIoTCentral)
-   [Additional Links](#AdditionalLinks)

<a name="Introduction"></a>

# Introduction 

**About this document**

This document describes how to connect ThinkCentre M90n Nano IoT to Azure IoT Central application using the IoT plug and Play model. Plug and Play simplifies IoT by allowing solution developers to integrate devices without writing any device code. Using Plug and Play, device manufacturers will provide a model of their device to cloud developers to be integrated quickly into IoT Central or any solution built on the Azure IoT platform. IoT Plug and Play will be open to the community by way of a definition language and SDKs.

**About ThinkCentre M90n IoT**

Thanks to 8th Gen Intel® processors, the ThinkCentre M90n IoT performs as fast and reliable as a regular PC—but is only a fraction of the size. It’s also compatible with ThinkCentre Tiny-in-One monitors, enabling you to create the perfect all-in-one. With the USB-C port, you have expansion options, too. Being fanless, the ThinkCentre M90n IoT is far quieter than most PCs. You can tuck it almost anywhere. What’s more, it meets the most stringent of durability tests (including military standards) and can withstand the harshest of work environments, such as a desert or high altitude. Why rip out legacy systems, when an I/O box can breathe new life into them? In addition, you can affix the ThinkCentre M90n IoT to a VESA mount, industrial DIN rail, or any type of bracket in a flash. Designed with the ever-expanding IoT network in mind, the ThinkCentre M90n IoT has been certified for Windows 10 IoT Enterprise, Microsoft Azure IoT Edge, AWS GreenGrass, and Ubuntu. It also supports 4G LTE technology, enabling it to communicate faster with your network. Each ThinkCentre M90n IoT is hardwired with the Trusted Platform Module (TPM) chipset, an international standard for safeguarding data.

<a name="FeaturesImplemented"></a>

# Features implemented

-   Azure IoT plug and play
-   Register device by IoT Hub Device Provisioning Service base on an X.509 digital certificate
-   Telemetry data sent for basic machine information


<a name="Prerequisites"></a>
# Prerequisites

You should have the following items ready before beginning the process: 

-   [Azure Account](https://portal.azure.com)
-   [Azure IoT Hub Instance](https://docs.microsoft.com/en-us/azure/iot-hub/about-iot-hub)
-   [Azure IoT Hub Device Provisioning Service](https://docs.microsoft.com/en-us/azure/iot-dps/about-iot-dps)
-   Provide Network connectivity (Wifi, LAN) supported by the device
-   Its mandatory that the device code/software image is preinstalled in device to enable Plug and Play
-   Device side C source code: https://github.com/ashokgowtham/azure-iot-samples-csharp/tree/master/DPSLenWorks

**Note:** If the device code is not preinstalled following are the [options](#preparethedevice) to choose to enable the plug and play device.

<a name="preparethedevice"></a>
# Prepare the Device.

**Hardware Environmental setup**

-   Please include how to setup and connect the device. Include external links for any software required for Hardware setup

**Software Environmental Setup**

-   Device side Plug and Play device code can be obtained from https://github.com/ashokgowtham/azure-iot-samples-csharp/tree/master/DPSLenWorks
-   Build instructions are available at https://github.com/ashokgowtham/azure-iot-samples-csharp/blob/master/DPSLenWorks/README.md. Follow this documentation to compile the device code.

<a name="IntegrationwithIoTCentral"></a>
# Integration with IoT Central

Run the compiled device code:
-   The compiled device code would have resulted in a binary executable named `DPSLenWorks`
-   It needs to be run with arguments provided to it like shown below
-   `DPSLenWorks [Device ID] [DPS ID Scope] [DPS symmetric key]`

<a name="AdditionalLinks"></a>
# Additional Links

Please refer to the below link for additional information for Plug and Play 

-    [Blog](https://azure.microsoft.com/en-us/blog/iot-plug-and-play-is-now-available-in-preview/)
-    [FAQ](TBD) 
-    [Plug and Play C SDK](https://github.com/Azure/azure-iot-sdk-c/tree/public-preview) 
-    [Plug and Play Node SDK](https://github.com/Azure/azure-iot-sdk-node/tree/digitaltwins-preview)
-    [Plug and Play Definitions](https://github.com/Azure/IoTPlugandPlay)

