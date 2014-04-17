/***********************************************************************************

    Filename:    simple_hid_eb.c

    Description: Main program of HID EB (keyboard/mouse) sample application. The
                 application runs in one the following modes (sub-applications):

                 1) Mouse function by operating the joystick.
                    Mouse buttons are operated by joystick push and S1.

                 2) Keyboard operation: joystick and button operations
                    write plain ASCII text to the PC.


***********************************************************************************/

/***********************************************************************************
* INCLUDES
*/
#include "hal_defs.h"
#include "../common/mrfi_link.h"
#include "hal_board.h"
#include "hal_button.h"
#include "hal_joystick.h"
#include "hal_led.h"
#include "hal_lcd.h"
#include "simple_hid.h"
#include "util_lcd.h"


/***********************************************************************************
* LOCAL CONSTANTS AND MACROS
*/
#define APP_MODE_MOUSE              0
#define APP_MODE_KEYBOARD           1


/***********************************************************************************
* LOCAL DATA TYPES
*/
typedef uint8 (*appTaskFn_t)(uint8 *pData);



/***********************************************************************************
* LOCAL VARIABLES
*/

static uint8 pHidData[KEYBOARD_DATA_SIZE];
static appTaskFn_t pFnTask;


// Mode menu
static const menuItem_t pRole[]= {
    "     MOUSE  ",      APP_MODE_MOUSE,
    "    KEYBOARD ",     APP_MODE_KEYBOARD,
};


static const menu_t pRoleMenu =
{
    pRole,
    N_ITEMS(pRole)
};



/***********************************************************************************
* GLOBAL FUNCTION PROTOTYPES
*/
extern uint8 mouseTask(uint8 *pData);
extern uint8 keyboardTask(uint8 *pData);



/***********************************************************************************
* LOCAL FUNCTION PROTOTYPES
*/
static void appSelectRole(void);


/***********************************************************************************
* GLOBAL FUNCTIONS
*/



/***********************************************************************************
* @fn          main
*
* @brief       This is the main entry of the RF HID application running on a
*              SmartRFxxEB. After the user has selected mouse or keyboard mode,
*              the radio link with the dongle is established.
*
*              The main loops continuously collects keyboard or mouse data and sends
*              them to the dongle via the RF link.
*
* @return      none
*/
void main(void)
{

    // Initialise board peripherals
    halBoardInit();
    halJoystickInit();

    // Indicate that the device is powered
    halLedSet(1);

    // Initialize MRFI
    mrfiLinkInit(EB_ADDRESS,DONGLE_ADDRESS,MRFI_CHANNEL);

    // Initialise application
    pFnTask= NULL;
    appSelectRole();
    halLedSet(3);

    //  Main processing loop
    while (TRUE) {
        uint8 nBytes;

        // Execute the task
        nBytes= pFnTask(pHidData);

        // We have HID input, transmit data to the dongle
        if (nBytes>0) {

            // Send HID data
            mrfiLinkSend(pHidData,nBytes,1);

            // Allow the receiver some respite
            halMcuWaitMs(5);

        }
    }
}


/***********************************************************************************
* LOCAL FUNCTIONS
*/


/***********************************************************************************
* @fn          appSelectRole
*
* @brief       Select application role
*
* @param       none
*
* @return      none
*/
static void appSelectRole(void)
{
    uint8 appRole;
    static appTaskFn_t fnLookup[]= {
        mouseTask,
        keyboardTask,
    };

    halLcdWriteLine(HAL_LCD_LINE_1, "    MRFI HID  ");
    appRole= utilMenuSelect(&pRoleMenu);
    halLcdWriteLine(HAL_LCD_LINE_3, "");
    halLcdWriteLine(HAL_LCD_LINE_2, pRole[appRole].szDescr);

    pFnTask= fnLookup[appRole];
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





