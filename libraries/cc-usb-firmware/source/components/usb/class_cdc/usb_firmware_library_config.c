/***********************************************************************************

    Filename:     usb_firmware_library_config.c

    Description:  USB library configuration.

***********************************************************************************/

/// \addtogroup module_usb_firmware_library_config
/// @{
#define USBFIRMWARELIBRARYCONFIG_C ///< Modifies the behavior of "EXTERN" in usb_interrupt.h
#include "usb_firmware_library_headers.h"

// Device descriptor
uint8 deviceDesc[] = {
    18, // deviceDescEnd - deviceDesc
    0x01, // bDescriptorType
    0x10, 0x01, // bcdUsb
    0x02, // bDeviceClass
    0x00, // bDeviceSubClass
    0x00, // bDeviceProtocol
    32, // Maximum data packet size for endpoint 0
    0x51, 0x04, // idVendor Texas Instruments
    0xA8, 0x16, // idProduct CC2531
    0x09, 0x00, // bcdDevice
    0x01, // iManufacturer
    0x02, // iProduct
    0x03, // iSerialNumber
    0x01 // bNumConfigurations
};

// Configuration descriptor
uint8 configDesc[] = {
    9, // configDescEnd - configDesc
    0x02, // bDescriptorType
    67, 0x00, // config1LengthEnd - config1LengthStart
    0x02, // numInterfaces
    0x01, // bConfigurationValue
    0x00, // iConfiguration
    0x80, // bmAttributes
    25 // maxPower
};

// Interface 0 descriptor
uint8 interface0Desc[] = {
    // Interface descriptor
    9, // interface0DescEnd - interface0Desc
    0x04, // bDescriptorType
    0x00, // bInterfaceNumber
    0x00, // bAlternateSetting
    0x01, // bNumEndpoints
    0x02, // bInterfaceClass
    0x02, // bInterfaceSubClass
    0x01, // bInterfaceProtocol
    0x00, // iInterface

    // Header functional descriptor
    5, // headerFunctionalDescEnd - headerFunctionalDesc
    0x24,
    0x00,
    0x10, 0x01,
    
    // Abstract control management functional descriptor
    4, // absCtrlManFuncDescEnd - absCtrlManFuncDesc
    0x24,
    0x02, // ACM (abstract control management)
    0x02, // Set the supported class requests

    // Union functional descriptor
    5, // unionFunctionalDescEnd - unionFunctionalDesc
    0x24,
    0x06,
    0x00,
    0x01,

    // Call management functional descriptor
    5, // callMngFuncDescEnd - callMngFuncDesc
    0x24,
    0x01,
    0x00,
    0x01,

    // Endpoint descriptor (EP2 IN)
    7, // endpoint0DescEnd - endpoint0Desc
    0x05, // bDescriptorType
    0x82, // bEndpointAddress
    0x03, // bmAttributes
    0x40, 0x00, // wMaxPacketSize
    0x40 // bInterval
};

// Interface 1 descriptor
uint8 interface1Desc[] = { 
    // Interface descriptor
    9, // interfaceDesc1End - interface1Desc
    0x04, // Interface descriptor type
    0x01, // Interface number
    0x00, // Alternate setting number
    0x02, // Number of endpoints in this intf
    0x0A, // Class code
    0x00, // Subclass code
    0x00, // Protocol code
    0x00, // Interface string index

    // Endpoint descriptor (EP4 OUT)
    7, // endpoint1DescEnd - endpoint1Desc
    0x05, // bDescriptorType
    0x84, // bEndpointAddress
    0x02, // bmAttributes
    0x40, 0x00, // wMaxPacketSize
    0x01, // bInterval

    // Endpoint descriptor (EP4 IN)
    7, // endpoint2DescEnd - endpoint2Desc
    0x05, // bDescriptorType
    0x04, // bEndpointAddress
    0x02, // bmAttributes
    0x40, 0x00, // wMaxPacketSize
    0x01 // bInterval
};

// String 0 descriptor: language ID
uint8 string0Desc[] = {
    4, // string0DescEnd - string0Desc
    0x03, // bDescriptorType
    0x09, // US-EN
    0x04
};

// String 1 descriptor: manufacturer
uint8 string1Desc[] = {
    36, // string1DescEnd - string1Desc
    0x03, // bDescriptorType
    'T', 0,
    'e', 0,
    'x', 0,
    'a', 0,
    's', 0,
    ' ', 0,
    'I', 0,
    'n', 0,
    's', 0,
    't', 0,
    'r', 0,
    'u', 0,
    'm', 0,
    'e', 0,
    'n', 0,
    't', 0,
    's', 0
};

// String 2 descriptor: product
uint8 string2Desc[] = {
    30, // string2DescEnd - string2Desc
    0x03, // bDescriptorType
    'C', 0,
    'C', 0,
    '2', 0,
    '5', 0,
    '3', 0,
    '1', 0,
    ' ', 0,
    'U', 0,
    'S', 0,
    'B', 0,
    ' ', 0,
    'C', 0,
    'D', 0,
    'C', 0
};

// String 3 descriptor: serial number
uint8 string3Desc[] = {
    8, // string3DescEnd - string3Desc
    0x03, // bDescriptorType
    0x00, 0,
    0x00, 0,
    0x01, 0
};

uint8 empty[] = { 0 };
uint8 empty2[] = { 0 };

// Look-up table for double buffer settings
uint8 __xdata* usbDblbufLut2[] = {
    interface0Desc,
    0,
    interface1Desc,
    0
};

// Declaration of global USB descriptor pointers
USB_DESCRIPTOR_MARKER usbDescriptorMarker= {
    (uint8 __xdata *)&deviceDesc,
    (uint8 __xdata *)&empty,
    (DESC_LUT_INFO __xdata *) &empty,
    (DESC_LUT_INFO __xdata *) &empty,
    (DBLBUF_LUT_INFO __xdata *) &usbDblbufLut2,
    (DBLBUF_LUT_INFO __xdata *) &empty2
};

/// @}


/*
+------------------------------------------------------------------------------
|  Copyright 2004-2007 Texas Instruments Incorporated. All rights reserved.
|
|  IMPORTANT: Your use of this Software is limited to those specific rights
|  granted under the terms of a software license agreement between the user who
|  downloaded the software, his/her employer (which must be your employer) and
|  Texas Instruments Incorporated (the "License"). You may not use this Software
|  unless you agree to abide by the terms of the License. The License limits
|  your use, and you acknowledge, that the Software may not be modified, copied
|  or distributed unless embedded on a Texas Instruments microcontroller or used
|  solely and exclusively in conjunction with a Texas Instruments radio
|  frequency transceiver, which is integrated into your product. Other than for
|  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
|  works of, modify, distribute, perform, display or sell this Software and/or
|  its documentation for any purpose.
|
|  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
|  PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
|  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
|  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
|  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
|  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
|  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING
|  BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
|  CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
|  SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
|  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
|
|  Should you have any questions regarding your right to use this Software,
|  contact Texas Instruments Incorporated at www.TI.com.
|
+------------------------------------------------------------------------------
*/
