/***********************************************************************************

    Filename:     hal_button.c

    Description:  HAL button implementation for CCxx11 dongle.

    Copyright 2009 Texas Instruments, Inc.

***********************************************************************************/
#include "hal_types.h"
#include "hal_board.h"
#include "hal_button.h"


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
    MCU_IO_INPUT(HAL_BOARD_IO_BTN_PORT, HAL_BOARD_IO_BTN_PIN, MCU_IO_PULLUP);
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
*          HAL_BUTTON_1:    button is being pushed
*          HAL_BUTTON_NONE: button is not being pushed
*
******************************************************************************/
uint8 halButtonPushed(void)
{
    uint8 v;

    v= HAL_BUTTON_NONE;
    if (HAL_BUTTON_PUSHED()) {
        HAL_DEBOUNCE(!HAL_BUTTON_PUSHED());
        v= HAL_BUTTON_1;
    }

    return v;
}
