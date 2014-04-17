/***********************************************************************************

    Filename:    simple_hid_dongle.c

    Description: Main program of HID dongle.

***********************************************************************************/

/***********************************************************************************
* INCLUDES
*/
#include "hal_defs.h"
#include "../common/mrfi_link.h"
#include "hal_board.h"
#include "hal_led.h"
#include "usb_hid.h"
#include "simple_hid.h"


/***********************************************************************************
* LOCAL VARIABLES
*/
static uint8 pRfData[MAX_DATA_SIZE];



/***********************************************************************************
* @fn          main
*
* @brief       This is the main entry of the RF HID application. It sets
*              distinct short addresses for the nodes, initalises and runs
*              receiver and sender tasks sequentially in an endless loop.
*
* @return      none
*/
void main(void)
{

    // Initialise board peripherals
    halBoardInit();

    // Initialise USB
    usbHidInit();

    // Initialize MRFI
    mrfiLinkInit(DONGLE_ADDRESS,EB_ADDRESS,MRFI_CHANNEL);

    // Indicate that the device is initialised
    halLedSet(1);

    //  Main processing loop
    while (TRUE) {

        // Process USB standard requests
        usbHidProcessEvents();

        // Process incoming radio traffic from HID devices
        if (mrfiLinkDataRdy()) {

            uint8 numBytes;

            // Receive RF packet
            numBytes = mrfiLinkRecv(pRfData);

            // If reception successful, ACK it and send packet to host over USB
            if(numBytes>0) {

                if (pRfData[0]==KEYBOARD_DATA_ID && numBytes==KEYBOARD_DATA_SIZE) {
                    // Process keyboard data
                    usbHidProcessKeyboard(pRfData);
                    halLedToggle(1);
                }

                if (pRfData[0]==MOUSE_DATA_ID && numBytes==MOUSE_DATA_SIZE) {
                    // Process mouse data
                    usbHidProcessMouse(pRfData);
                    halLedToggle(1);
                }

            }

        }

    }

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





