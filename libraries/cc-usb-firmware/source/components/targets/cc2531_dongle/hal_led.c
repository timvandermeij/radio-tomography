/***********************************************************************************

    Filename: hal_led.c

    Copyright 2007 Texas Instruments, Inc.

***********************************************************************************/

#include "hal_types.h"
#include "hal_led.h"
#include "hal_board.h"

//----------------------------------------------------------------------------------
//  void halLedSet(uint8 id)
//
//  DESCRIPTION:
//    Turn LED on.
//----------------------------------------------------------------------------------
void halLedSet(uint8 id)
{
    if (id==1)
        HAL_LED_SET_1();
    if (id==2 || id==3)
        HAL_LED_SET_2();
}

//----------------------------------------------------------------------------------
//  void halLedClear(uint8 id)
//
//  DESCRIPTION:
//    Turn LED off.
//----------------------------------------------------------------------------------
void halLedClear(uint8 id)
{
    if (id==1)
        HAL_LED_CLR_1();
    if (id==2 || id==3)
        HAL_LED_CLR_2();
}

//----------------------------------------------------------------------------------
//  void halLedToggle(uint8 id)
//
//  DESCRIPTION:
//    Change state of LED. If on, turn it off. Else turn on.
//----------------------------------------------------------------------------------
void halLedToggle(uint8 id)
{
    if (id==1)
        HAL_LED_TGL_1();
    if (id==2 || id==3)
        HAL_LED_TGL_2();
}


