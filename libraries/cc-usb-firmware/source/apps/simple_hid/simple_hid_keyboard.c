/***********************************************************************************

    Filename:		simple_hid_keyboard.c

    Description:	HID keyboard task for SmartRF04EB and SmartRF05EB.

***********************************************************************************/

/***********************************************************************************
* INCLUDES
*/
#include "hal_button.h"
#include "hal_joystick.h"
#include "simple_hid.h"


/***********************************************************************************
* LOCAL CONSTANTS AND MACROS
*/

// HID keyboard codes (subset of the codes available in the HID specification)
#define HID_A            4
#define HID_B            5
#define HID_C            6
#define HID_D            7
#define HID_E            8
#define HID_F            9
#define HID_G            10
#define HID_H            11
#define HID_I            12
#define HID_J            13
#define HID_K            14
#define HID_L            15
#define HID_M            16
#define HID_N            17
#define HID_O            18
#define HID_P            19
#define HID_Q            20
#define HID_R            21
#define HID_S            22
#define HID_T            23
#define HID_U            24
#define HID_V            25
#define HID_W            26
#define HID_X            27
#define HID_Y            28
#define HID_Z            29
#define HID_RETURN       40
#define HID_TAB          43
#define HID_SPACEBAR     44
#define HID_CAPS_LOCK    57
#define HID_LEFT_SHIFT   225
#define HID_LEFT_ALT     226

#define HID_MODKEY_LEFTSHIFT     0x02



/***********************************************************************************
* GLOBAL FUNCTIONS
*/


/***********************************************************************************
* @fn          keyboardTask
*
* @brief       This function pools the EB joystick and buttons and generates
*              a HID keyboard reports if any activity is detected. All operations
*              generate one key hit, see comments in the code below for details.
*              Note that all characters will be interpreted as capital letters due
*              to the HID_MODKEY_LEFTSHIFT key modifier.
*
* @return      Number of bytes to send.
*/
uint8 keyboardTask(uint8 *pHidData)
{
    uint8 c, nBytes;

    c= 0;

    // Build keyboard report
    pHidData[0] = KEYBOARD_DATA_ID;
    pHidData[1] = HID_MODKEY_LEFTSHIFT;  // Modifiers - makes letter uppercase
    pHidData[2] = 0;                     // Reserved

    // Check mouse movement (joystick)
    switch (halJoystickGetDir())
    {
    case HAL_JOYSTICK_EVT_UP:
        c= HID_U;               // Letter 'U'
        break;
    case HAL_JOYSTICK_EVT_DOWN:
        c= HID_D;               // Letter 'D'
        break;
    case HAL_JOYSTICK_EVT_RIGHT:
        c= HID_R;               // Letter 'R'
        break;
    case HAL_JOYSTICK_EVT_LEFT:
        c= HID_L;               // Letter 'L'
        break;
    default:
        // Center
        break;
    }

    if (halJoystickPushed()) {
        c= HID_P;               // Letter 'P'
    }


    if (halButtonPushed()) {
        c= HID_B;               // Letter 'B'
    }

    if (c != 0) {

        // A 'key' has been hit
        pHidData[3] = c;             // keyCodes[0]
        pHidData[4] = 0;             // keyCodes[1]
        pHidData[5] = 0;             // keyCodes[2]
        pHidData[6] = 0;             // keyCodes[3]
        pHidData[7] = 0;             // keyCodes[4]
        pHidData[8] = 0;             // keyCodes[5]

        nBytes= KEYBOARD_DATA_SIZE;
    } else {

        // No activity
        nBytes= 0;
    }

    return nBytes;
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





