/***********************************************************************************

    Filename:     usb_firmware_library_config.c

    Description:  USB library configuration.

***********************************************************************************/

/// \addtogroup module_usb_firmware_library_config
/// @{
#define USBFIRMWARELIBRARYCONFIG_C ///< Modifies the behavior of "EXTERN" in usb_interrupt.h
#include "usb_firmware_library_headers.h"

//-----------------------------------------------------------------------------
// READ THIS!!
//
// This file configures the USB Firmware Library.
// To use the library, make a copy of this file, rename it to "usb_firmware_library_config.c", and
// put it in the project catalog. Then edit the code below as needed:
//-----------------------------------------------------------------------------

uint8 deviceDesc[] = { 18,
    0x01, 0x10, 0x01, 0x02, 0x00, 0x00, 32, 0x51,
    0x04, 0xA8, 0x16, 0x09, 0x00, 0x01, 0x02, 0x03,
    0x01 };
uint8 configDesc[] = { 9,
    0x02, 67, 0x00, 0x02, 0x01, 0x00, 0x80, 25 };
uint8 interface0Desc[] = { 9,
    0x04, 0x00, 0x00, 0x01, 0x02, 0x02, 0x01, 0x00,

    5, 0x24, 0x00, 0x10, 0x01,
    4, 0x24, 0x02, 0x02,
    5, 0x24, 0x06, 0x00, 0x01,
    5, 0x24, 0x01, 0x00, 0x01,
    7, 0x05, 0x82, 0x03, 0x40, 0x00, 0x40 };
uint8 interface1Desc[] = { 9,
    0x04, 0x01, 0x00, 0x02, 0x0a, 0x00, 0x00, 0x00,

    7, 0x05, 0x84, 0x02, 0x40, 0x00, 0x01,
    7, 0x05, 0x04, 0x02, 0x40, 0x00, 0x01 };
uint8 string0Desc[] = {
    4, 0x03, 0x09, 0x04 };
uint8 string1Desc[] = { 12,
    0x03, 'H',0, 'e',0, 'l',0, 'l',0, 'o',0 };
uint8 string2Desc[] = { 12,
    0x03, 'w',0, 'o',0, 'r',0, 'l',0, 'd',0 };
uint8 string3Desc[] = { 8,
    0x03, 0x00,0, 0x00,0, 0x01,0 };
uint8 dummy[] = { 0 };
uint8 __xdata* usbDblbufLut2[] = { interface0Desc, 0, interface1Desc, 0 };
uint8 dummy2[] = { 0 };

// Declaration of global USB descriptor pointers
USB_DESCRIPTOR_MARKER usbDescriptorMarker= {
    (uint8 __xdata *)&deviceDesc,
    (uint8 __xdata *)&dummy,
    (DESC_LUT_INFO __xdata *) &dummy,
    (DESC_LUT_INFO __xdata *) &dummy,
    (DBLBUF_LUT_INFO __xdata *) &usbDblbufLut2,
    (DBLBUF_LUT_INFO __xdata *) &dummy2
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
