/***********************************************************************************

  Filename:		usb_hid_reports.h

  Description:	Implementation of HID reports

***********************************************************************************/

#include "usb_firmware_library_headers.h"
#include "usb_class_requests.h"
#include "usb_hid_reports.h"
#include "hal_int.h"


HID_DATA __data hidData = {
    .keyboardOutReport.ledStatus= 0,
    .keyboardInReport           = {0},
    .mouseInReport              = {0},
    .keyboardProtocol           = HID_PROTOCOL_REPORT,  // Default, as suggested by HID spec
    .mouseProtocol              = HID_PROTOCOL_REPORT,
    .keyboardIdleRate           = HID_IDLE_NOT_SET,     // Use this as init value, until it is set by USB host
    .mouseIdleRate              = HID_IDLE_NOT_SET,
};

uint8 hidSendKeyboardInReport(void)
{
    uint8 result;
    uint8 ea;

    result= FALSE;
    ea = halIntLock();

    USBFW_SELECT_ENDPOINT(1);
    if (!(USBCSIL & USBCSIL_INPKT_RDY)) {
        // Send the report
        usbfwWriteFifo(&USBF1, sizeof(KEYBOARD_IN_REPORT), &hidData.keyboardInReport);
        USBCSIL |= USBCSIL_INPKT_RDY;
        result = TRUE;
    }
    halIntUnlock(ea);

    return result;
}


uint8 hidSendMouseInReport(void)
{
    uint8 result;
    uint8 ea;

    result= FALSE;
    ea = halIntLock();

    USBFW_SELECT_ENDPOINT(2);
    if (!(USBCSIL & USBCSIL_INPKT_RDY)) {

        // Send the report
        usbfwWriteFifo(&USBF2, sizeof(MOUSE_IN_REPORT), &hidData.mouseInReport);
        USBCSIL |= USBCSIL_INPKT_RDY;
        result = TRUE;
    }
    halIntUnlock(ea);

    return result;
}




void hidUpdateKeyboardInReport(KEYBOARD_IN_REPORT __data *pNewReport)
{
    uint8 ea;

    ea = halIntLock();
    hidData.keyboardInReport.modifiers = pNewReport->modifiers;
    hidData.keyboardInReport.pKeyCodes[0] = pNewReport->pKeyCodes[0];
    hidData.keyboardInReport.pKeyCodes[1] = pNewReport->pKeyCodes[1];
    hidData.keyboardInReport.pKeyCodes[2] = pNewReport->pKeyCodes[2];
    hidData.keyboardInReport.pKeyCodes[3] = pNewReport->pKeyCodes[3];
    hidData.keyboardInReport.pKeyCodes[4] = pNewReport->pKeyCodes[4];
    hidData.keyboardInReport.pKeyCodes[5] = pNewReport->pKeyCodes[5];
    halIntUnlock(ea);
}




void hidUpdateMouseInReport(MOUSE_IN_REPORT __data *pNewReport)
{
    uint8 ea;

    ea = halIntLock();

    // Buttons are updated
    hidData.mouseInReport.buttons = pNewReport->buttons;

    // Movements are updated
    hidData.mouseInReport.dX = pNewReport->dX;
    hidData.mouseInReport.dY = pNewReport->dY;
    hidData.mouseInReport.dZ = pNewReport->dZ;
    halIntUnlock(ea);
}
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

