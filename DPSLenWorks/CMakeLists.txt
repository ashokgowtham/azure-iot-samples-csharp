#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

#this is CMakeLists.txt for DPSLenWorks

#Compile As C99
if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
        set (CMAKE_C_FLAGS "--std=c99 /DWIN32 /D_WINDOWS /W3")
        if (NOT IN_OPENWRT)
            set (CMAKE_CXX_FLAGS "--std=c++11 /DWIN32 /D_WINDOWS /W3 /GR /EHsc")
        endif()
    endif()
else()
    set (CMAKE_C_STANDARD 99)
    set (CMAKE_CXX_STANDARD 11)
endif()

cmake_minimum_required(VERSION 2.8)

set(DPSLenWorks_h_files
    ./utilities/lenworks_interface_a_interface.h
    ./utilities/deviceinfo_interface.h
    ./utilities/digitaltwin_client_helper.h
    ./utilities/digitaltwin_serializer.h
    ./azure_pnp_dcm_impl.h
    ./pnp_device.h
)

set(DPSLenWorks_c_files
    ./utilities/lenworks_interface_a_interface.c
    ./utilities/deviceinfo_interface.c
    ./utilities/digitaltwin_client_helper.c
    ./utilities/digitaltwin_serializer.c
    ./azure_pnp_dcm_impl.c
    ./pnp_device.c
    ./main.c
)

include_directories(.)

add_executable(DPSLenWorks ${DPSLenWorks_c_files} ${DPSLenWorks_h_files})

# Find azure_iot_sdks Vcpkg package
find_package(azure_iot_sdks REQUIRED)

target_link_libraries(DPSLenWorks
parson
iothub_client_mqtt_transport
iothub_client
digitaltwin_client
prov_device_ll_client
prov_mqtt_transport
prov_auth_client
aziotsharedutil
umqtt
)