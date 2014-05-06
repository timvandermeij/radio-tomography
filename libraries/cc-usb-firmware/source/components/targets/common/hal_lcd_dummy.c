/***********************************************************************************
    
    Filename:     hal_lcd_dummy.c

    Description:  Dummy LCD driver. Stubs for use on targets without LCD, thus avoiding
	              messy compiler switches in the application code.

    Copyright 2007-2008 by Texas Instruments, Inc.

***********************************************************************************/

/***********************************************************************************
 * INCLUDES
 */

#include "hal_types.h"
#include "hal_lcd.h"
#include "hal_mcu.h"
#include "hal_board.h"



/***********************************************************************************
 * CONSTANTS AND DEFINES
 */



/***********************************************************************************
 * LOCAL VARIABLES
 */

/***********************************************************************************
 * LOCAL FUNCTIONS
 */


/***********************************************************************************
 * GLOBAL FUNCTIONS
 */

 /***********************************************************************************
 * @fn          halLcdInit
 *
 * @brief       Initalise LCD
 *
 * @param       none
 *
 * @return      none
 */
void halLcdInit(void)
{
}

/***********************************************************************************
 * @fn          halLcdClear
 *
 * @brief       Clear all lines on display
 *
 * @param       none
 *
 * @return      none
 */
void halLcdClear(void)
{
}

/***********************************************************************************
 * @fn          halLcdSetContrast
 *
 * @brief       Set display contrast
 *
 * @param       uint8 value - contrast value
 *
 * @return      none
 */
void halLcdSetContrast(uint8 value)
{
}

/***********************************************************************************
 * @fn          halLcdGetLineLength
 *
 * @brief       Get max number of characters on each line
 *
 * @param       nono
 *
 * @return      uint8 - number of characters on a line
 */
uint8 halLcdGetLineLength(void)
{
    return 0;
}

/***********************************************************************************
 * @fn          halLcdWriteChar
 *
 * @brief       Write single character
 *
 * @param       uint8 line - display line
 *              uint8 col - column
 *              char text - character to display
 *
 * @return      none
 */
void halLcdWriteChar(uint8 line, uint8 col, char text)
{
}

/***********************************************************************************
 * @fn          halLcdWriteLine
 *
 * @brief       Write line on display
 *
 * @param       uint8 line - display line
 *              char *pLine2 - pointer to text buffer to write
 *
 * @return      none
 */
void halLcdWriteLine(uint8 line, const char XDATA *pLine)
{
}

/***********************************************************************************
 * @fn          halLcdWriteLines
 *
 * @brief       Write lines on display
 *
 * @param       char *pLine1 - pointer to text buffer for line 1
 *              char *pLine2 - pointer to text buffer for line 2
 *              char *pLine3 - pointer to text buffer for line 3
 *
 * @return      none
 */
void halLcdWriteLines(const char XDATA *pLine1, const char XDATA *pLine2, const char XDATA *pLine3)
{
}

/***********************************************************************************
 * @fn          halLcdDisplayValue
 *
 * @brief       Display value on display with optional text on right and left side
 *
 * @param       uint8 line
 *              char *pLeft
 *              int32 value
 *              char *pRight
 *
 * @return      none
 */
void halLcdDisplayValue(uint8 line, char XDATA *pLeft, int32 value, char XDATA *pRight)
{
}

/***********************************************************************************
 * @fn          halLcdDisplayCounters
 *
 * @brief       Display counter values with text on display
 *
 * @param       uint8 line - display line
 *              int32 lValue - left value
 *              char lChar - left text
 *              int32 rValue - right value
 *              char rChar - right text
 *
 * @return      none
 */
void halLcdDisplayCounters(uint8 line, int32 lValue, char lChar, int32 rValue, char rChar)
{
}

/***********************************************************************************
 * @fn          halLcdDisplayUint16
 *
 * @brief       Write a 16 bit value on the specified line on the LCD
 *
 * @param       uint16 value - value to display
 *              uint8 radix - must be HAL_LCD_RADIX_DEC
 *              uint8 line - line on display
 *
 * @return      none
 */
void halLcdDisplayUint16(uint8 line, uint8 radix, uint16 value)
{
}


/***********************************************************************************
 * @fn          halLcdClearAllSpecChars
 *
 * @brief       Clear special characters
 *
 * @param       none
 *
 * @return      none
 */
void halLcdClearAllSpecChars(void)
{
}

/***********************************************************************************
 * @fn          halLcdCreateSpecChar
 *
 * @brief       Create special character
 *
 * @param       uint8 index
 *              const char *p5x8Spec
 *
 * @return      none
 */
void halLcdCreateSpecChar(uint8 index, const char XDATA *p5x8Spec)
{
}

/***********************************************************************************
 * @fn          halLcdWriteSpecChar
 *
 * @brief       Write special character
 *
 * @param       uint8 line  - display line
 *              uint8 col   - column
 *              uint8 index - index of spec character
 *
 * @return      none
 */
void halLcdWriteSpecChar(uint8 line, uint8 col, uint8 index)
{
}
