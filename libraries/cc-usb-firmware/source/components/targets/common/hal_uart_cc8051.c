/***********************************************************************************

  Filename:     hal_uart_cc8051.c

  Description:  UART interface to UART0 at P0. Works with HW flow control and
                optionally with buffered TX transmission. Reception is always
                buffered. Works with 8051 based SoCs.

***********************************************************************************/

/***********************************************************************************
* INCLUDES
*/
#include "hal_types.h"
#include "hal_uart.h"
#include "hal_board.h"
#include "util_buffer.h"
#include "hal_int.h"
#include "hal_mcu.h"

/***********************************************************************************
* LOCAL CONSTANTS and DEFINITIONS
*/

#define xHAL_UART_TX_POLLING

#define P2DIR_PRIPO               0xC0
#define HAL_UART_PRIPO            0x00

#define HAL_UART_0_PERCFG_BIT     0x01  // USART0 on P0, so clear this bit.
#define HAL_UART_0_P0_RX_TX       0x0C  // Peripheral I/O Select for Rx/Tx.

// UxCSR - USART Control and Status Register.
#define CSR_MODE                  0x80
#define CSR_RE                    0x40
#define CSR_SLAVE                 0x20
#define CSR_FE                    0x10
#define CSR_ERR                   0x08
#define CSR_RX_BYTE               0x04
#define CSR_TX_BYTE               0x02
#define CSR_ACTIVE                0x01

// UxUCR - USART UART Control Register.
#define UCR_FLUSH                 0x80
#define UCR_FLOW                  0x40
#define UCR_D9                    0x20
#define UCR_BIT9                  0x10
#define UCR_PARITY                0x08
#define UCR_SPB                   0x04
#define UCR_STOP                  0x02
#define UCR_START                 0x01

#define UTX0IE                    0x04
#define UTX1IE                    0x08


/************************************************************************************
* LOCAL VARIABLES
*/
static ringBuf_t rbRxBuf;
#ifndef HAL_UART_TX_POLLING
static ringBuf_t rbTxBuf;
#endif


// Baud rate settings
#if BSP_CONFIG_CLOCK_MHZ==32

#define BAUD_M_38400                 59
#define BAUD_M_57600                216
#define BAUD_M_115200               216

#define BAUD_E_38400                 10
#define BAUD_E_57600                 10
#define BAUD_E_115200                11

#elif BSP_CONFIG_CLOCK_MHZ==26

#define BAUD_M_38400                131
#define BAUD_M_57600                 34
#define BAUD_M_115200                34

#define BAUD_E_38400                 10
#define BAUD_E_57600                 11
#define BAUD_E_115200                12

#elif BSP_CONFIG_CLOCK_MHZ==24

#define BAUD_M_38400                163
#define BAUD_M_57600                 59
#define BAUD_M_115200                59

#define BAUD_E_38400                 10
#define BAUD_E_57600                 11
#define BAUD_E_115200                12

#else
#error "Clock speed not defined!"
#endif

/************************************************************************************
* @fn      halUartInit
*
* @brief   Initalise UART. Supported baudrates are: 38400, 57600 and 115200
*
* @param   uint8 baudrate
*          uint8 options - this parameter is ignored
*
* @return  none
*/
void halUartInit(uint8 baudrate, uint8 options)
{
    // Set P2 priority - USART0 over USART1 if both are defined.
    P2DIR &= ~P2DIR_PRIPO;
    P2DIR |= HAL_UART_PRIPO;
    
    // Set UART0 I/O location to P0.
    PERCFG &= ~HAL_UART_0_PERCFG_BIT;
    
    // Enable Tx and Rx on P0
    P0SEL |= (HAL_UART_0_P0_RX_TX);
    P1SEL &= ~(HAL_UART_0_P0_RX_TX);
    
    // Make sure ADC doesnt use this
    ADCCFG &= ~(HAL_UART_0_P0_RX_TX);
    
    U0CSR=  CSR_MODE;             // UART mode
    U0UCR|= UCR_FLUSH;
    
    // Set baud rate
    switch (baudrate) {
    case HAL_UART_BAUDRATE_38400:
        U0BAUD = BAUD_M_38400;
        U0GCR = BAUD_E_38400;
        break;
    case HAL_UART_BAUDRATE_57600:
        U0BAUD = BAUD_M_57600;
        U0GCR = BAUD_E_57600;
        break;
    default:
        // 115200 default
        U0BAUD = BAUD_M_115200;
        U0GCR = BAUD_E_115200;
    }
    
    
    // Initialize the RX buffer
    bufInit(&rbRxBuf);
    
#ifndef HAL_UART_TX_POLLING
    // Enable transmit register empty interrupt
    UTX0IF= 1;
    
    bufInit(&rbTxBuf);
#endif
    
    // Set RTS pin to output
    HAL_RTS_DIR_OUT();
    
    // One stop bit
    U0UCR |= UCR_STOP; 
    
    // Prepare for reception
    URX0IF = 0;       
    U0CSR |= CSR_RE;
    URX0IE = 1;
    
    // Enable HW flow control
    halUartEnableRxFlow(TRUE);
}


#ifndef HAL_UART_TX_POLLING
/***********************************************************************************
* @fn      halUartBufferedWrite
*
* @brief   Write data buffered to UART. Data is written into a buffer, and the
*          buffer is emptied by UART TX interrupt ISR
*
* @param   uint8* buf - buffer with data to write
*          uint16 length - number of bytes to write
*
* @return  none
*/
static uint16 halUartBufferedWrite(const uint8* buf, uint16 length)
{

    uint16 n;

    n= 0;
    while ( n < length ) {
        n+= bufPut(&rbTxBuf,buf+n,length-n);
        halMcuWaitMs(5);
    }

    // Enable UART TX interrupt
    IEN2|= UTX0IE;

    return n;
}


/************************************************************************************
* @fn      halUartWrite
*
* @brief   Write data buffer to UART
*
* @param   uint8* buf - buffer with data to write
*          uint16 length - number of bytes to write
*
* @return  uint16 - number of bytes written
*/
uint16 halUartWrite(const uint8* buf, uint16 length)
{
    return halUartBufferedWrite(buf,length);
}

#else

/************************************************************************************
* @fn      halUartWrite
*
* @brief   Write data buffer to UART
*
* @param   uint8* buf - buffer with data to write
*          uint16 length - number of bytes to write
*
* @return  uint16 - number of bytes written
*/
uint16 halUartWrite(const uint8* buf, uint16 length)
{
    uint16 i;

    UTX0IF = 0;
    for(i = 0; i < length; i++)
    {
        U0DBUF = buf[i];
        while (!UTX0IF);
        UTX0IF = 0;
    }
    return length;
}
#endif

/************************************************************************************
* @fn      halUartRead
*
* @brief   Read data from UART Rx buffer
*
* @param   uint8* buf - buffer with data to read in to
*          uint16 length - number of bytes to read
*
* @return  none
*/
uint16 halUartRead(uint8* buf, uint16 length)
{
    return bufGet(&rbRxBuf, (uint8 *)buf, length);
}


/************************************************************************************
* @fn      halUartGetNumRxBytes
*
* @brief   Returns number of bytes in RX buffer
*
* @param   none
*
* @return  uint8
*/
uint16 halUartGetNumRxBytes(void)
{
    return bufNumBytes(&rbRxBuf);
}


/***********************************************************************************
* @fn      halUartEnableRxFlow
*
* @brief   Signal ready/not ready to receive characters on UART
*
* @param   uint8 enable - TRUE to signal ready to receive on UART
*                         FALSE to signal not ready to receive on UART
*
* @return  none
*/
void halUartEnableRxFlow(uint8 enable)
{
    // Enable RX flow
    if(enable) {
        HAL_RTS_CLR();
    }
    // Disable RX flow
    else {
        HAL_RTS_SET();
    }
}


/************************************************************************************
* @fn      usart0Rx_ISR
*
* @brief   ISR framework for the USCI A0/B0 Receive component
*
* @param   none
*
* @return  none
*/
HAL_ISR_FUNCTION(uart0RxISR,URX0_VECTOR)
{
    uint8 c, s;

    URX0IF = 0;  
    c= U0DBUF;
    s= U0CSR;

    if ((s&(CSR_FE|CSR_ERR))==0)    // Check for Frame and parity errors
        bufPut(&rbRxBuf,&c,1);
}


#ifndef HAL_UART_TX_POLLING
/***********************************************************************************
* @fn      usart1Tx_ISR
*
* @brief   ISR framework for the USCI A0/B0 transmit component
*
* @param   none
*
* @return  none
*/
HAL_ISR_FUNCTION(uart0TxISR,UTX0_VECTOR)
{
    uint8 c;

    UTX0IF = 0;
    if (bufGet(&rbTxBuf,&c,1)==1) {
        U0DBUF= c;
    }
    // If buffer empty, disable uart TX interrupt
    if( (bufNumBytes(&rbTxBuf)) == 0) {
        IEN2&= ~UTX0IE;
    }
}
#endif

/************************************************************************************
  Copyright 2007 Texas Instruments Incorporated. All rights reserved.

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
