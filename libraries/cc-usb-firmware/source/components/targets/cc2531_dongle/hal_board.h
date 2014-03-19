/******************************************************************************

    Filename: hal_board.h

    Description: HAL board peripherals header file for the CC2531 USB dongle

    Copyright 2007 Texas Instruments, Inc.

******************************************************************************/
#ifndef HAL_BOARD_H
#define HAL_BOARD_H


/******************************************************************************
 * INCLUDES
 */

#include "hal_types.h"
#include "hal_defs.h"
#include "cc8051\hal_cc8051.h"
#include "usb_reg.h"

#if (chip==2531)
#include <ioCC2531.h>
#else
#error "chip not defined!"
#endif

#ifdef USB_UART
#include "usb_uart.h"
#endif

/******************************************************************************
 * CONSTANTS
 */

// Board properties
#define BOARD_NAME                     "RFUSB2531"
#define NUM_LEDS                       2
#define NUM_BUTTONS                    2
#define NUM_JSTKS                      0
#define NUM_POTS                       0


//-----------------------------------------------------------------------------
//  Define ports and pins used by CC2531 on USB dongle
//-----------------------------------------------------------------------------
// USB
#define HAL_BOARD_IO_USB_ENABLE_PORT   1   // USB pull-up enable
#define HAL_BOARD_IO_USB_ENABLE_PIN    0

// LEDs
#define HAL_BOARD_IO_LED_1_PORT        1   // Red
#define HAL_BOARD_IO_LED_1_PIN         1
#define HAL_BOARD_IO_LED_2_PORT        0   // Green
#define HAL_BOARD_IO_LED_2_PIN         0


// Buttons
#define HAL_BOARD_IO_BTN_1_PORT        1   // Button S1
#define HAL_BOARD_IO_BTN_1_PIN         2
#define HAL_BOARD_IO_BTN_2_PORT        1   // Button S2
#define HAL_BOARD_IO_BTN_2_PIN         3



/******************************************************************************
 * MACROS
 */

// LED
#define HAL_LED_SET_1()            MCU_IO_SET_HIGH(HAL_BOARD_IO_LED_1_PORT, \
    HAL_BOARD_IO_LED_1_PIN)
#define HAL_LED_CLR_1()            MCU_IO_SET_LOW(HAL_BOARD_IO_LED_1_PORT, \
    HAL_BOARD_IO_LED_1_PIN)
#define HAL_LED_TGL_1()            MCU_IO_TGL(HAL_BOARD_IO_LED_1_PORT, \
    HAL_BOARD_IO_LED_1_PIN)

#define HAL_LED_SET_2()            MCU_IO_SET_LOW(HAL_BOARD_IO_LED_2_PORT, \
    HAL_BOARD_IO_LED_2_PIN)
#define HAL_LED_CLR_2()            MCU_IO_SET_HIGH(HAL_BOARD_IO_LED_2_PORT, \
    HAL_BOARD_IO_LED_2_PIN)
#define HAL_LED_TGL_2()            MCU_IO_TGL(HAL_BOARD_IO_LED_2_PORT, \
    HAL_BOARD_IO_LED_2_PIN)

// Buttons
#define HAL_BUTTON_1_PUSHED()      (!MCU_IO_GET(HAL_BOARD_IO_BTN_1_PORT, HAL_BOARD_IO_BTN_1_PIN))
#define HAL_BUTTON_2_PUSHED()      (!MCU_IO_GET(HAL_BOARD_IO_BTN_2_PORT, HAL_BOARD_IO_BTN_2_PIN))
#define HAL_DEBOUNCE(expr)         { int i; for (i=0; i<500; i++) { if (!(expr)) i = 0; } }

// USB interface
#define HAL_USB_ENABLE()           st( USBCTRL= USBCTRL_PLL_EN | USBCTRL_USB_EN; \
                                        while (!(USBCTRL&USBCTRL_PLL_LOCKED)); )
#define HAL_USB_PLL_DISABLE()      st( USBCTRL&= ~USBCTRL_PLL_EN; \
                                        while (USBCTRL&USBCTRL_PLL_LOCKED); )
#define HAL_USB_DISABLE()          st(USBCTRL = 0; while (USBCTRL & 0x80);)

#define HAL_USB_PULLUP_ENABLE()    MCU_IO_OUTPUT(HAL_BOARD_IO_USB_ENABLE_PORT, HAL_BOARD_IO_USB_ENABLE_PIN, 1)
#define HAL_USB_PULLUP_DISABLE()   MCU_IO_SET_LOW(HAL_BOARD_IO_USB_ENABLE_PORT, HAL_BOARD_IO_USB_ENABLE_PIN)

#define HAL_USB_INT_ENABLE()       st( P2IEN|= 0x20; IEN2|= 0x02; )
#define HAL_USB_INT_DISABLE()      st( P2IEN&= ~0x20; )
#define HAL_USB_INT_CLEAR()        st( P2IFG= 0; P2IF= 0; )

#define HAL_USB_RESUME_INT_ENABLE()    st ( USBCIE |= USBCIE_RESUMEIE; )
#define HAL_USB_RESUME_INT_DISABLE()   st ( USBCIE &= ~USBCIE_RESUMEIE; )


#define LCD_NOT_SUPPORTED

#ifdef USB_UART
#define HAL_PROCESS()              usbUartProcess()
#else
#define HAL_PROCESS()
#endif


/******************************************************************************
 * FUNCTIONS
 */

#ifdef __cplusplus
extern "C" {
#endif

void halBoardInit(void);


#ifdef __cplusplus
}
#endif

/*****************************************************************************/
#endif

