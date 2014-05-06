/***********************************************************************************

    Filename:     hal_button.c

    Description:  HAL button implementation for CC2531 dongle.

    Copyright 2009 Texas Instruments, Inc.

***********************************************************************************/
#include "hal_types.h"
#include "hal_board.h"
#include "hal_button.h"
//#include "hal_cc8051.h"


/******************************************************************************
 * @fn          halButtonInit
 *
 * @brief       Button is configured as input
 *
 * @param       none
 *
 * @return      none
 *****************************************************************************/
void halButtonInit(void)
{
    MCU_IO_INPUT(HAL_BOARD_IO_BTN_1_PORT, HAL_BOARD_IO_BTN_1_PIN, MCU_IO_PULLUP);
    MCU_IO_INPUT(HAL_BOARD_IO_BTN_2_PORT, HAL_BOARD_IO_BTN_2_PIN, MCU_IO_PULLUP);
}


/******************************************************************************
* @fn  halButtonPushed
*
* @brief
*      This function detects if 'S1' is being pushed. The function
*      implements software debounce. Return true only if previuosly called
*      with button not pushed. Return true only once each time the button
*      is pressed.
*
* Parameters:
*
* @param  void
*
* @return uint8
*          1: Button is being pushed
*          0: Button is not being pushed
*
******************************************************************************/
uint8 halButtonPushed(void)
{
    uint8 v;

    v= HAL_BUTTON_NONE;
    if (HAL_BUTTON_1_PUSHED()) {
        HAL_DEBOUNCE(!HAL_BUTTON_1_PUSHED());
        v= HAL_BUTTON_1;
    }

    if (HAL_BUTTON_2_PUSHED()) {
        HAL_DEBOUNCE(!HAL_BUTTON_2_PUSHED());
        v= HAL_BUTTON_2;
    }

    return v;
}