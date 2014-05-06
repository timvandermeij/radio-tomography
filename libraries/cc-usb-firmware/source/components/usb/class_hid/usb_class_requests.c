/***********************************************************************************

    Filename:		usb_class_request.c

    Description:	USB class request handler.

***********************************************************************************/


/***********************************************************************************
* INCLUDES
*/
#include "usb_class_requests.h"
#include "usb_hid_reports.h"
#include "usb_framework.h"


/***********************************************************************************
* @fn          usbcrSetReport
*
* @brief       Implements support for the HID class request SET_REPORT.
*
* @return      none
*/
void usbcrSetReport(void)
{
    // Received setup header?
    if (usbfwData.ep0Status == EP_IDLE) {

        // Sanity check the incoming setup header:
        // Only accept output report for keyboard LED status
        if ((HI_UINT16(usbSetupHeader.value) == HID_REP_TYPE_OUTPUT) &&
            (usbSetupHeader.index == KEYBOARD_INDEX) &&
            (usbSetupHeader.length == sizeof(KEYBOARD_OUT_REPORT))) {

            // Prepare to receive the data
            usbfwData.ep0Status = EP_RX;
            usbSetupData.pBuffer = (uint8 *) &hidData.keyboardOutReport.ledStatus;
            usbSetupData.bytesLeft = usbSetupHeader.length;
            return;

        } else {

            // Unsupported: Stall the request
            usbfwData.ep0Status = EP_STALL;
            return;
        }

    // Received data?
    } else if (usbfwData.ep0Status == EP_RX) {

        // The USB firmware library will return here after the data has been
        // received. This USB example only implements one-way RF link protocol
        // (i.e. keyboard device -> USB device), but can optionally be extended
        // by transmitting the received LED status (now stored in
        // hidData.keyboardOutReport.ledStatus) back to keyboard for it to
        // update itself.

    }

} // usbcrSetReport


/***********************************************************************************
* @fn          usbcrGetReport
*
* @brief       Implements support for the HID class request GET_REPORT.
*
* @return      none
*/
void usbcrGetReport(void)
{
    // Received setup header?
    if (usbfwData.ep0Status == EP_IDLE) {

        // Asking for our keyboard report?
        if ((HI_UINT16(usbSetupHeader.value) == HID_REP_TYPE_INPUT) &&
                (usbSetupHeader.index == KEYBOARD_INDEX) &&
                (usbSetupHeader.length == sizeof(KEYBOARD_IN_REPORT))) {

            // Prepare to send the data
            usbfwData.ep0Status = EP_TX;
            usbSetupData.pBuffer = (uint8 *) &hidData.keyboardInReport;
            usbSetupData.bytesLeft = usbSetupHeader.length;
            return;

        // Asking for our mouse report?
        } else if ((HI_UINT16(usbSetupHeader.value) == HID_REP_TYPE_INPUT) &&
                    (usbSetupHeader.index == MOUSE_INDEX) &&
                    (usbSetupHeader.length == sizeof(MOUSE_IN_REPORT))) {

            // Prepare to send the data
            usbfwData.ep0Status = EP_TX;
            usbSetupData.pBuffer = (uint8 *) &hidData.mouseInReport;
            usbSetupData.bytesLeft = usbSetupHeader.length;
            return;

        } else {

            // Unsupported: Stall the request
            usbfwData.ep0Status = EP_STALL;
            return;
        }

    // Data transmitted?
    } else if (usbfwData.ep0Status == EP_TX) {

        // The USB firmware library will return here after the keyboard/mouse
        // report has been transmitted, but there is nothing for us to do here.
    }

} // usbcrGetReport


/***********************************************************************************
* @fn          usbcrSetProtocol
*
* @brief       Implements support for the HID class request SET_PROTOCOL.
*              This request is only required for HID devices in the "boot" subclass.
*
* @return      none
*/
void usbcrSetProtocol(void)
{
    // Received setup header?
    if (usbfwData.ep0Status == EP_IDLE) {

        // Sanity check setup request parameters
        if ((usbSetupHeader.value & 0xFFFE) ||
            (usbSetupHeader.length != 0) ||
            (usbSetupHeader.index > MOUSE_INDEX)) {

            // Unsupported: Stall the request
            usbfwData.ep0Status = EP_STALL;
            return;

        } else {
            // Check which interface is addressed and store the new protocol
            switch (LO_UINT16(usbSetupHeader.index)) {

            case KEYBOARD_INDEX:
                hidData.keyboardProtocol = LO_UINT16(usbSetupHeader.value);
                break;
            case MOUSE_INDEX:
                hidData.mouseProtocol = LO_UINT16(usbSetupHeader.value);
                break;
            default:
                break;
            }

            // This request has only a setup stage (no data stage)
            return;
        }
    }

} // usbcrSetProtocol


/***********************************************************************************
* @fn          usbcrGetProtocol
*
* @brief       Implements support for the HID class request GET_PROTOCOL.
*              This request is only required for HID devices in the "boot" subclass.
*
* @return      none
*/
void usbcrGetProtocol(void)
{
    // Received setup header?
    if (usbfwData.ep0Status == EP_IDLE) {

        // Sanity check setup request parameters
        if ((usbSetupHeader.value != 0) ||
            (usbSetupHeader.length != 1) ||
            (usbSetupHeader.index > MOUSE_INDEX)) {

            // Unsupported: Stall the request
            usbfwData.ep0Status = EP_STALL;
            return;

        } else {
            // Check which interface is addressed and prepare to send the data
            switch (LO_UINT16(usbSetupHeader.index)) {

            case KEYBOARD_INDEX:
                usbSetupData.pBuffer = &hidData.keyboardProtocol;
                break;
            case MOUSE_INDEX:
                usbSetupData.pBuffer = &hidData.mouseProtocol;
                break;
            default:
                break;
            }
            usbSetupData.bytesLeft = 1;
            usbfwData.ep0Status = EP_TX;
            return;
        }

    // Data transmitted?
    } else if (usbfwData.ep0Status == EP_TX) {

        // The USB firmware library will return here after the protocol data
        // has been transmitted, but there is no need for us to do anything here.
    }

} // usbcrGetProtocol


/***********************************************************************************
* @fn          usbcrSetIdle
*
* @brief       Implements support for the HID class request SET_IDLE.
*              This request is optional for mouse devices, but required by keyboards.
*
* @return      none
*/
void usbcrSetIdle(void)
{
    // Received setup header?
    if (usbfwData.ep0Status == EP_IDLE) {

        // Sanity check setup request parameters
        if ((usbSetupHeader.length != 0) ||
            (usbSetupHeader.index > MOUSE_INDEX)) {

            // Unsupported: Stall the request
            usbfwData.ep0Status = EP_STALL;
            return;

        } else {
            // Check which interface is addressed and save the new idle rate
            switch (LO_UINT16(usbSetupHeader.index)) {

            case KEYBOARD_INDEX:
                hidData.keyboardIdleRate = usbSetupHeader.value;
                break;
            case MOUSE_INDEX:
                hidData.mouseIdleRate = usbSetupHeader.value;
                break;
            default:
                break;
            }

            // This request has only a setup stage (no data stage)
            return;
        }
    }

} // usbcrSetIdle


/***********************************************************************************
* @fn          usbcrGetIdle
*
* @brief       Implements support for the HID class request GET_IDLE.
*              This request is optional for mouse devices, but required by keyboards.
*
* @return      none
*/
void usbcrGetIdle(void)
{
    // Received setup header?
    if (usbfwData.ep0Status == EP_IDLE) {

        // Sanity check setup request parameters
        if ((usbSetupHeader.length != 1) ||
            (usbSetupHeader.index > MOUSE_INDEX)) {

            // Unsupported: Stall the request
            usbfwData.ep0Status = EP_STALL;
            return;

        } else {
            // Check which interface is addressed and prepare to send the data
            switch (LO_UINT16(usbSetupHeader.index)) {

            case KEYBOARD_INDEX:
                usbSetupData.pBuffer = LOBYTEPTR(hidData.keyboardIdleRate);
                break;
            case MOUSE_INDEX:
                usbSetupData.pBuffer = LOBYTEPTR(hidData.mouseIdleRate);
                break;
            default:
                break;
            }
            usbSetupData.bytesLeft = 1;
            usbfwData.ep0Status = EP_TX;
            return;
        }

    // Data transmitted?
    } else if (usbfwData.ep0Status == EP_TX) {

        // The USB firmware library will return here after the idle data
        // has been transmitted, but there is no need for us to do anything here.
    }

} // usbcrGetIdle

