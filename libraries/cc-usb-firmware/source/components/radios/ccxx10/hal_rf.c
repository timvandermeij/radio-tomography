/***********************************************************************************

  Filename:       hal_rf.c

  Description:    CC2510 radio interface.

***********************************************************************************/

/***********************************************************************************
* INCLUDES
*/
#include "hal_board.h"
#include "hal_mcu.h"
#include "hal_int.h"
#include "hal_assert.h"
#include "util.h"

#include "hal_rf.h"

#include "string.h"

/***********************************************************************************
* CONSTANTS AND DEFINES
*/

// Chip revision
#define REV_A                   0x01
#define REV_B                   0x02
#define REV_C                   0x03
#define REV_D                   0x04
#define REV_E                   0x05
#define REV_F                   0x06

#define CHIPREVISION            REV_E

/***********************************************************************************
* @fn      halRfGetChipId
*
* @brief   Get chip id
*
* @param   none
*
* @return  uint8 - result
*/
uint8 halRfGetChipId(void)
{
    return PARTNUM;
}


/***********************************************************************************
* @fn      halRfGetChipVer
*
* @brief   Get chip version
*
* @param   none
*
* @return  uint8 - result
*/
uint8 halRfGetChipVer(void)
{
    return VERSION;
}


/***********************************************************************************
* @fn      halRfReadMemory
*
* @brief   Read RF device memory
*
* @param   uint16 addr - memory address
*          uint8* pData - data buffer. This must be allocated by caller.
*          uint8 length - number of bytes
*
* @return  Number of bytes read
*/
uint8 halRfReadMemory(uint16 addr, uint8* pData, uint8 length)
{
    return 0;
}


/***********************************************************************************
* @fn      halRfWriteMemory
*
* @brief   Write RF device memory
*
* @param   uint16 addr - memory address
*          uint8* pData - data buffer. This must be allocated by caller.
*          uint8 length - number of bytes
*
* @return  Number of bytes written
*/
uint8 halRfWriteMemory(uint16 addr, uint8* pData, uint8 length)
{
    return 0;
}

/***********************************************************************************
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
