/***********************************************************************************

  Filename:	    rf_modem.c

  Description:	RF Modem is an application which uses MRFI to implement Over The Air
                streaming between two serial ports. The application implements a
                simple ACK handshake on top of MRFI.

  Operation:    1) Select a device number (1 or 2) by moving the joystick left/right.
                The device number must be distinct between the two nodes in
                ordre to assign each of them unique addresses in the network.
                NB! USB dongles automatically assume device number 2.

                2) Push S1 to confirm the choice.

                3) Configure your terminal emulation program as follows:
                - baud rate 38400 bps
                - 8 data bits no parity, 1 stop bit
                - HW flow control

***********************************************************************************/

/***********************************************************************************
* INCLUDES
*/
#include "hal_defs.h"
#include "../common/mrfi_link.h"

#include "hal_board.h"
#include "hal_mcu.h"
#include "hal_uart.h"
#include "hal_lcd.h"
#include "hal_led.h"
#include "hal_timer_32k.h"
#include "hal_assert.h"

#include "util_lcd.h"
#include "stdio.h"



/***********************************************************************************
* CONSTANTS and DEFINITIONS
*/

// Uncomment the next line to force UART loopback instead of RF modem. This mode
// is intended for test purposes only.
//#define DEVICE_LOOPBACK_FORCE

// Application parameters
#define APP_PAYLOAD_LENGTH       44

// RF link properties
#define DEVICE_1_ADDR        0x25EB
#define DEVICE_2_ADDR        0x25DE
#define MRFI_CHANNEL              0

// Application states
#define INIT                      0
#define ROLE_SET                  1

// Device roles
#define DEVICE_1                  0
#define DEVICE_2                  1
#define DEVICE_LOOPBACK           2

// Other constrants
#define UART_RX_IDLE_TIME       100     // 100 ms
#define N_RETRIES                 5     // Number of transmission retries


/***********************************************************************************
* LOCAL VARIABLES
*/
static XDATA uint8 pTxData[APP_PAYLOAD_LENGTH];
static XDATA uint8 pRxData[APP_PAYLOAD_LENGTH];
static uint16 nTxErr, nRxErr;
static uint16 appRemoteAddr;
static uint16 appLocalAddr;
static uint8  appRole;

static volatile uint8 appUartRxIdle;

#if !(defined LCD_NOT_SUPPORTED) && !(defined DEVICE_LOOPBACK_FORCE)
// Role menu
static const menuItem_t pRole[]= {
    "Device 1", DEVICE_1,
    "Device 2", DEVICE_2,
    "Loopback", DEVICE_LOOPBACK,
};


static const menu_t pRoleMenu =
{
  pRole,
  N_ITEMS(pRole)
};
#endif


/***********************************************************************************
* LOCAL FUNCTIONS
*/
static void appLoopbackTask(void);
static void appRfReceiverTask(void);
static void appRfSenderTask(void);
static void appUpdateDisplay(void);

static void appConfigTimer(uint16 rate);
static void appSelectRole(void);


/***********************************************************************************
* @fn          main
*
* @brief       This is the main entry of the RF Modem application. It sets
*              distinct short addresses for the nodes, initalises and runs
*              receiver and sender tasks sequentially in an endless loop.
*
* @return      none
*/
void main(void)
{
   
    char *szTitle= "MRFI RF modem";
    appUartRxIdle = FALSE;

    // Initialise board peripherals
    halBoardInit();
    
    halUartInit(HAL_UART_BAUDRATE_38400, 0);

    // 100 ms RX idle timeout
    appConfigTimer(1000/UART_RX_IDLE_TIME);

    // Indicate that the application has been initialised
    halLcdClear();
    halLcdWriteLine(HAL_LCD_LINE_1, szTitle);
    halLedSet(1);

    // Select application role (Device 1, Device 2 or Loopback)
    appSelectRole();

    if (appRole != DEVICE_LOOPBACK) {
        // Initialize the MRFI RF link layer
        mrfiLinkInit(appLocalAddr,appRemoteAddr,MRFI_CHANNEL);  
    }

    // Indicate that the modem is operating
    halLcdWriteLine(HAL_LCD_LINE_1, szTitle);

    // Initialise error counters
    nTxErr= nRxErr= 0;

    // Enable RX idle timeout interrupt
    halTimer32kIntEnable();

    //  Main processing loop
    while(TRUE) {

        // On-board device processing (UART etc.)
        HAL_PROCESS();

        if (appRole == DEVICE_LOOPBACK) {

            // Loopback processing
            appLoopbackTask();

        } else {

            // RF transmitter processing
            appRfSenderTask();

            // RF receiver processing
            appRfReceiverTask();
        }

    }
}


/***********************************************************************************
* LOCAL FUNCTIONS
*/


/***********************************************************************************
* @fn          appRfReceiverTask
*
* @brief       Check if a new packet has been received. If a new packet
*              is received the payload is sent to the UART.
*
* @param       none
*
* @return      none
*/
static void appRfReceiverTask(void)
{

    if (mrfiLinkDataRdy()) {
        uint8 nToSend;
        uint8 fSuccess;

        // Tell the PC not to send data
        halUartEnableRxFlow(FALSE);

        // Wait for the PC to respond
        halMcuWaitUs(1000);

        // Receive RF data
        nToSend = mrfiLinkRecv(pRxData);

        // If reception successful, send packet to UART
        fSuccess= FALSE;
        if(nToSend>0) {
            if (halUartWrite(pRxData,nToSend)==nToSend)
                fSuccess= TRUE;
        }

        if (!fSuccess) {
            nRxErr++;
            appUpdateDisplay();
        }

        // Signal RX flow on, the PC may send data again
        halUartEnableRxFlow(TRUE);
    }
}



/***********************************************************************************
* @fn          appRfSenderTask
*
* @brief       Checks if new bytes have arrived from the UART. If there
*              are enough bytes to fill a maximal sized packet, or if the UART
*              is idle, the  bytes are transmitted on the air.
*
* @param       none
*
* @return      none
*/
static void appRfSenderTask(void)
{
    uint8 nBytes;
    uint8 payloadLength;
    uint8 bytesToRead;

    nBytes = halUartGetNumRxBytes();
    payloadLength= 0;
    bytesToRead= 0;

    if(nBytes >= APP_PAYLOAD_LENGTH || (appUartRxIdle && nBytes>0) ) {
        // Signal PC not to send on UART, while sending on air.
        halUartEnableRxFlow(FALSE);
        // Wait for PC to respond
        halMcuWaitUs(1000);

        bytesToRead = MIN(nBytes, APP_PAYLOAD_LENGTH);
        halUartRead(pTxData,bytesToRead);
        payloadLength+= bytesToRead;

        halLedToggle(3);
        if( (mrfiLinkSend(pTxData, payloadLength,N_RETRIES)) != MRFI_TX_RESULT_SUCCESS) {
            nTxErr++;
            appUpdateDisplay();
        }

        // Signal RX flow on
        halUartEnableRxFlow(TRUE);

        // Restart idle timer
        halTimer32kRestart();
        halTimer32kIntEnable();
        // Reset idle fimer flag
        appUartRxIdle = FALSE;
    }
}


/***********************************************************************************
* @fn          appLoopbackTask
*
* @brief       Checks if new bytes have arrived from the UART and echo them back.
*
* @param       none
*
* @return      none
*/
static void appLoopbackTask(void)
{
    uint8 nBytes, n;

    nBytes = halUartGetNumRxBytes();

    if( nBytes>0 ) {
        n= MIN(sizeof(pTxData),nBytes);
        halUartRead(pTxData,n);
        halUartWrite(pTxData,n);
    }
}


/***********************************************************************************
* @fn          appSelectRole
*
* @brief       Select application role. Device 1, device 2 or loopback.
*
* @param       none
*
* @return      none
*/
static void appSelectRole(void)
{
#ifdef DEVICE_LOOPBACK_FORCE
    appRole= DEVICE_LOOPBACK;
#else

#ifdef LCD_NOT_SUPPORTED
    appRole= DEVICE_2;
#else
    halLcdWriteLine(1, "Device Role: ");
    appRole= utilMenuSelect(&pRoleMenu);
#endif // LCD_NOT_SUPPORTED
#endif // DEVICE_LOOPBACK_FORCE

    halLcdClear();

    // Set distinct addresses
    if(appRole == DEVICE_1) {
        halLcdWriteLine(HAL_LCD_LINE_2, "Device 1 ready");
        appLocalAddr = DEVICE_1_ADDR;
        appRemoteAddr= DEVICE_2_ADDR;
    } else if (appRole == DEVICE_2) {
        halLcdWriteLine(HAL_LCD_LINE_2, "Device 2 ready");
        appLocalAddr = DEVICE_2_ADDR;
        appRemoteAddr= DEVICE_1_ADDR;
    } else if (appRole == DEVICE_LOOPBACK) {
        halLcdWriteLine(HAL_LCD_LINE_2, "Loopback ready");
    }
}


/***********************************************************************************
* @fn          appUpdateDisplay
*
* @brief       Update display with status information.
*
* @param       none
*
* @global      nErrors
*
* @return      none
*/
static void appUpdateDisplay(void)
{
    char buf[17];
    sprintf(buf,"Err: %2d/%2d", nTxErr,nRxErr);
    halLcdWriteLine(HAL_LCD_LINE_3, buf);
}


/***********************************************************************************
* @fn          appTimerISR
*
* @brief       32KHz timer interrupt service routine. Signals UART RX timeout to
*              appRfSenderTask
*
* @param       none
*
* @return      none
*/
static void appTimerISR(void)
{
    appUartRxIdle = TRUE;
}


/***********************************************************************************
* @fn          appConfigTimer
*
* @brief       Configure timer interrupts for application. Uses 32 KHz timer
*
* @param       uint16 period - Frequency of timer interrupt. This value must be
*              between 1 and 32768 Hz
*
* @return      none
*/
static void appConfigTimer(uint16 rate)
{
    halTimer32kInit(TIMER_32K_CLK_FREQ/rate);
    halTimer32kIntConnect(&appTimerISR);
}



/***********************************************************************************
  Copyright 2004-2009 Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
***********************************************************************************/

