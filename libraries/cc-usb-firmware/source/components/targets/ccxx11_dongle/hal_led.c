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
    HAL_LED_SET();
}

//----------------------------------------------------------------------------------
//  void halLedClear(uint8 id)
//
//  DESCRIPTION:
//    Turn LED off.
//----------------------------------------------------------------------------------
void halLedClear(uint8 id)
{
    HAL_LED_CLR();
}

//----------------------------------------------------------------------------------
//  void halLedToggle(uint8 id)
//
//  DESCRIPTION:
//    Change state of LED. If on, turn it off. Else turn on.
//----------------------------------------------------------------------------------
void halLedToggle(uint8 id)
{
    HAL_LED_TGL();
}


