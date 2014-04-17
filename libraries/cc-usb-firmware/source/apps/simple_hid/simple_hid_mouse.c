/***********************************************************************************

    Filename:		simple_hid_mouse.c

    Description:	HID mouse task for SmarftRF04EB.

***********************************************************************************/


/***********************************************************************************
* INCLUDES
*/
#include "hal_defs.h"
#include "hal_button.h"
#include "hal_joystick.h"
#include "simple_hid.h"



/***********************************************************************************
* GLOBAL FUNCTIONS
*/

/***********************************************************************************
* @fn          mouseTask
*
* @brief       This function pools the EB joystick and buttons and generates
*              a HID mouse reports if any activity is detected. The joystick is used
*              to generate mouse movements, joystick pushed emulates left click and
*              the 'S1'-button emulates right-click. Note that the mouse movement
*              accelerates when keeping the joystick pushed in the same direction
*
* @return      Number of bytes to send.
*/
uint8 mouseTask(uint8 *pHidData)
{
    static uint8 sameDirectionCount = 0; // used to get acceleration on the mouse movements
    uint8 fPushed;
    uint8 fDataUpdated;

    fDataUpdated= FALSE;

    // Initialise mouse report
    pHidData[0] = MOUSE_DATA_ID;    // 0: Identifier
    // 1: button state
    // 2: X direction
    // 3: Y direction
    pHidData[4] = 0;                // 4: Z direction (scroll-wheel) not used

    // Check mouse movement (joystick)
    switch (halJoystickGetDir())
    {
    case HAL_JOYSTICK_EVT_UP :
        if(pHidData[3] > 0x80) {
            sameDirectionCount++;
        } else {
            sameDirectionCount = 0;
        }
        pHidData[3] = 0xFF - (sameDirectionCount >> 4);
        fDataUpdated = TRUE;
        break;
    case HAL_JOYSTICK_EVT_DOWN :
        if((pHidData[3] < 0x80) && (pHidData[3] != 0)) {
            sameDirectionCount++;
        } else {
            sameDirectionCount = 0;
        }
        pHidData[3] = 0x01 + (sameDirectionCount >> 4);
        fDataUpdated = TRUE;
        break;
    case HAL_JOYSTICK_EVT_LEFT :
        if(pHidData[2] > 0x80) {
            sameDirectionCount++;
        } else {
            sameDirectionCount = 0;
        }
        pHidData[2] = 0xFF - (sameDirectionCount >> 4);
        fDataUpdated = TRUE;
        break;
    case HAL_JOYSTICK_EVT_RIGHT :
        if((pHidData[2] < 0x80) && (pHidData[2] != 0) ) {
            sameDirectionCount++;
        } else {
            sameDirectionCount = 0;
        }
        pHidData[2] = 0x01 + (sameDirectionCount >> 4);
        fDataUpdated = TRUE;
        break;
    default:
        // Center: reset X and Y data
        if (pHidData[2] !=0) {
            pHidData[2]= 0;
            fDataUpdated = TRUE;
        }
        if (pHidData[3] !=0) {
            pHidData[3]= 0;
            fDataUpdated = TRUE;
        }
        break;
    }


    // Poll "left mouse button"
    fPushed= halJoystickPushed();

    if (fPushed) {
        // Button pressed
        pHidData[1] |= 0x01;
        fDataUpdated = TRUE;
    }

    if ( !fPushed && (pHidData[1] & 0x01) ) {
        // Button released
        pHidData[1] &= ~0x01;
        fDataUpdated = TRUE;
    }

    // Poll "right mouse button"
    fPushed= halButtonPushed()==HAL_BUTTON_1;

    if (fPushed) {
        // Button pressed
        pHidData[1] |= 0x02;
        fDataUpdated = TRUE;
    }

    if  (!fPushed && (pHidData[1] & 0x02) ) {
        // Button released
        pHidData[1] &= ~0x02;
        fDataUpdated = TRUE;
    }

    return fDataUpdated ? MOUSE_DATA_SIZE : 0;

}


/*
+------------------------------------------------------------------------------
|  Copyright 2004-2009 Texas Instruments Incorporated. All rights reserved.
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





