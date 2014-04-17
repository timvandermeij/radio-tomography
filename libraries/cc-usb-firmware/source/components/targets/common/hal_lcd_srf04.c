/***********************************************************************************
    Filename:     hal_lcd.c

    Description:  Functions for accessing the LCD on SmartRF04EB (Varitronix COG-1626512C)

***********************************************************************************/

/***********************************************************************************
* INCLUDES
*/
#include "hal_board.h"
#include "hal_lcd.h"
#include "util.h"


/***********************************************************************************
 * MACROS, CONSTANTS AND DEFINES
 */
#define DATA_HIGH()     MCU_IO_INPUT(1, 2, MCU_IO_PULLUP)
#define DATA_LOW()      MCU_IO_OUTPUT(1, 2, 0)

#define CLOCK_HIGH()    MCU_IO_INPUT(2, 0, MCU_IO_PULLUP)
#define CLOCK_LOW()     MCU_IO_OUTPUT(2, 0, 0)

#define LCD_SDA         P1_2
#define LCD_SCL         P2_0


/* SM-Bus address of the LCD controller */
#define LCD_ADDR        0x76

/* Internal addresses */
#define LINE1_ADDR      0x80    // Upper line of LCD
#define LINE2_ADDR      0xC0    // Lower line of LCD
#define CHAR1_ADDR      0x08    // First character

/*  RS selects the register to be accessed for read and write
    RS = 0 => selects instruction register for write and busy flag
    RS = 1 => selects the data register for both read and write */
#define REG_SEL_0       0x00
#define REG_SEL_1       0x40

// LCD lines
#define LCD_LINE_COUNT                  2
#define LCD_LINE_LENGTH                 16

// LCD symbols
enum {
    HAL_LCD_SYMBOL_ARROW_LEFT      = 0x10,
    HAL_LCD_SYMBOL_ARROW_RIGHT     = 0x11,
    HAL_LCD_SYMBOL_ARROW_UP        = 0x12,
    HAL_LCD_SYMBOL_ARROW_DOWN      = 0x13
};

/***********************************************************************************
 * LOCAL DATA
 */

/***********************************************************************************
 * LOCAL FUNCTIONS
 */

static void  smbStart(void);
static void  smbSend(const uint8* buffer, uint8 n);
static void  smbStop(void);
static void  smbClock(uint8 value);
static void  smbWrite(uint8 value);
static uint8 smbSendByte(uint8 b);

static char  lcdConvertChar(char c);
static void  lcdWait(void);



/***********************************************************************************
 * @fn          halLcdInit
 *
 * @brief       Initialize LCD
 *
 * @param       none
 *
 * @return      none
 */
void halLcdInit(void)
{
    uint8 sendBuffer[8];

    // Setting the ports as inputs.
    MCU_IO_INPUT(1, 2, MCU_IO_PULLUP);
    MCU_IO_INPUT(2, 0, MCU_IO_PULLUP);


    // Setting up the lcd initialisation data.
    sendBuffer[0] = LCD_ADDR;
    sendBuffer[1] = REG_SEL_0; // Instruction Register
    sendBuffer[2] = 0x0C;      // Display control         D =  1:      Display On
    //                                                    C =  0:      Cursor Off
    //                                                    B =  0:      Cursor character blink off
    sendBuffer[3] = 0x21;      // Function set            H =  1:      Use extended instruction set
    sendBuffer[4] = 0xA0;      // Set DDRAM address       ADD = 0x20
    sendBuffer[5] = 0x07;      // Display configuration   P =  1:      Column data right to left
    //                                                    Q =  1:      Row data, bottom to top
    sendBuffer[6] = 0x34;      // Function set            DL=  0:      4 bits
    //                                                    M =  1:      2-line by 16 display
    //                                                    SL=  0:      MUX1:18
    //                                                    H =  0:      Use basic instruction set
    sendBuffer[7] = 0x01;      // Clearing display
    smbSend(sendBuffer, 8);

    halLcdClear();
}


/***********************************************************************************
 * @fn          halLcdClear
 *
 * @brief       Clear all lines on LCD
 *
 * @param       none
 *
 * @return      none
 */
void halLcdClear(void)
{
    halLcdWriteLines(NULL, NULL, NULL);
}

/***********************************************************************************
 * @fn          halLcdGetLineLength
 *
 * @brief       Get max number of characters on each line
 *
 * @param       none
 *
 * @return      uint8 - number of characters on a line
 */
uint8 halLcdGetLineLength(void)
{
    return LCD_LINE_LENGTH;
}

/***********************************************************************************
 * @fn          halLcdGetNumLines
 *
 * @brief       Get the number of lines on the LCD.
 *
 * @param       none
 *
 * @return      uint8 - number of lines
 */
uint8 halLcdGetNumLines(void)
{
    return LCD_LINE_COUNT;
}


/***********************************************************************************
 * @fn          halLcdWriteChar
 *
 * @brief       Write a character on LCD.
 *
 * @param       line - line on display
 *              col - column
 *              char - character to display
 *
 * @return      none
 */
void halLcdWriteChar(uint8 line, uint8 col, char c)
{
    uint8 sendBuffer[3];
    uint8 i;

    if (col > LCD_LINE_LENGTH) {
        col = LCD_LINE_LENGTH - 1;
    }

    i = 0;
    sendBuffer[i++] = LCD_ADDR;
    sendBuffer[i++] = REG_SEL_0;
    sendBuffer[i++] = ((line == HAL_LCD_LINE_1) ?  LINE1_ADDR : LINE2_ADDR) + col;
    smbSend(sendBuffer, i);

    i = 0;
    sendBuffer[i++] = LCD_ADDR;
    sendBuffer[i++] = REG_SEL_1;
    sendBuffer[i++] = lcdConvertChar(c);
    smbSend(sendBuffer, i);
}


/***********************************************************************************
 * @fn          halLcdWriteLine
 *
 * @brief       Write line on LCD.
 *
 * @param       line - line on display
 *              text - text string
 *
 * @return      none
 */
void halLcdWriteLine(uint8 line, const char* text)
{
   uint8 sendBuffer[50];
   uint8 i, j;
   char c;

    if (text == NULL)
        return;

   i = 0;
   sendBuffer[i++] = LCD_ADDR;
   sendBuffer[i++] = REG_SEL_0;
   sendBuffer[i++] = ((line == HAL_LCD_LINE_1) ?  LINE1_ADDR : LINE2_ADDR);
   smbSend(sendBuffer, i);

   i = j = 0;
   sendBuffer[i++] = LCD_ADDR;
   sendBuffer[i++] = REG_SEL_1;
   while( ( (c = text[j]) != '\0' ) && j < LCD_LINE_LENGTH ){
      sendBuffer[i++] = lcdConvertChar(c);
      j++;
   }
   for ( ;j < LCD_LINE_LENGTH; j++){
      sendBuffer[i++] = lcdConvertChar(' ');
   }
   smbSend(sendBuffer, i);
}


/***********************************************************************************
 * @fn          halLcdWriteLine
 *
 * @brief       Write all lines on LCD.
 *
 * @param       line1 - text string to display on line 1
 *              line2 - text string to display on line 2
 *              line3 - ignored for this display
 *
 * @return      none
 */
void halLcdWriteLines(const char* line1, const char* line2, const char* line3)
{
   halLcdWriteLine(HAL_LCD_LINE_1, line1);
   halLcdWriteLine(HAL_LCD_LINE_2, line2);
   return;
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
void halLcdCreateSpecChar(uint8 index, const char *p5x8Spec)
{
    uint8 sendBuffer[10];
    uint8 address = CHAR1_ADDR + (index * 0x08);

    //send control data
    sendBuffer[0] = LCD_ADDR;
    sendBuffer[1] = REG_SEL_0;

    if (address < 0x40)
        sendBuffer[2] = 0x80;
    else
        sendBuffer[2] = 0xC0;

    sendBuffer[3] = 0x40 | (address & 0x3F);
    smbSend(sendBuffer, 4);

    //send data
    sendBuffer[0] = LCD_ADDR;
    sendBuffer[1] = REG_SEL_1;

    sendBuffer[2] = p5x8Spec[0];
    sendBuffer[3] = p5x8Spec[1];
    sendBuffer[4] = p5x8Spec[2];
    sendBuffer[5] = p5x8Spec[3];
    sendBuffer[6] = p5x8Spec[4];
    sendBuffer[7] = p5x8Spec[5];
    sendBuffer[8] = p5x8Spec[6];
    sendBuffer[9] = p5x8Spec[7];

    smbSend(sendBuffer, 10);
}

/***********************************************************************************
 * @fn          halLcdWriteSpecChar
 *
 * @brief       Write special character on display
 *
 * @param       uint8 line
 *              uint8 col
 *              uint8 index
 *
 * @return      none
 */
void halLcdWriteSpecChar(uint8 line, uint8 col, uint8 index)
{
    halLcdWriteChar(line, col, index);
}



/***********************************************************************************
* LOCAL FUNCTIONS
*/

/***********************************************************************************
 * @fn          smbSend
 *
 * @brief       Send n bytes over the SMB bus
 *
 * @param       uint8 *buffer
 *              const uint8 n
 *
 * @return      none
 */
static void smbSend(const uint8 *buffer, uint8 n)
{
   uint8 i;

   smbStart();
   for(i = 0; i < n; i++){
      while(!smbSendByte(buffer[i])); //send until ACK received
   }
   smbStop();
}

/***********************************************************************************
 * @fn          smbStart
 *
 * @brief       This function initiates SMBus communication. It makes sure that
 *              both the data and the clock of the SMBus are high. Then the data
 *              pin is set low while the clock is kept high. This initializes
 *              SMBus transfer.
 *
 * @param       none
 *
 * @return      none
 */
static void smbStart(void)
{
   while (! (LCD_SDA && LCD_SCL) ); //wait for Data and clk high
   DATA_LOW();
   lcdWait();
   smbClock(0);
}


/***********************************************************************************
 * @fn          smbStop
 *
 * @brief       This function terminates SMBus communication. It makes sure that the
 *              data and clock of the SMBus are low and high, respectively. Then
 *              the data pin is set high while the clock is kept high. This
 *              terminates SMBus transfer.
 *
 * @param       none
 *
 * @return      none
 */
static void smbStop(void)
{
   while (! (!LCD_SDA && LCD_SCL));
   smbClock(0);
   DATA_HIGH();
   lcdWait();
   smbClock(1);
}

/***********************************************************************************
 * @fn          smbStop
 *
 * @brief       This function is used to clock the SMBus connected to the LCD.
 *              If a negative edge is to follow, the pin is set as an output and
 *              driven low. If a positive edge is to follow, the pin is set as an
 *              input and the pull-up resistor is to drive the node high. This way
 *              the slave device can hold the node low if a longer setup time is
 *              desired.
 *
 * @param       uint8 value
 *
 * @return      none
 */
static void smbClock(uint8 value)
{
   if(!value)
   {
      CLOCK_LOW();
   }
   else {
      CLOCK_HIGH();
   }
   lcdWait();
}

/***********************************************************************************
 * @fn          smbStop
 *
 * @brief       Function for writing bit to the data line. Setting the port as input
 *              make the SMBus go high because of the pull-up resistors.
 *
 * @param       uint8 value
 *
 * @return      none
 */
static void smbWrite(uint8 value)
{
   smbClock(0);
   lcdWait();
   if(value){
      DATA_HIGH();
   }
   else{
      DATA_LOW();
   }
   smbClock(1);
   lcdWait();
}

/***********************************************************************************
 * @fn          smbSendByte
 *
 * @brief       Sends the byte b over the smb bus. Returns 1 if the byte was sent
 *              successfully.
 *
 * @param       uint8 b
 *
 * @return      none
 */
static uint8 smbSendByte(uint8 b)
{
   uint8 i;
   uint8 ack;
   for (i = 0; i < 8; i++){
      smbWrite(b & 0x80);
      b = (b <<  1);
   }
   smbClock(0);
   DATA_HIGH();
   smbClock(1);
   ack = !LCD_SDA;
   return ack; //high = ACK received, else ACK not received
}

/***********************************************************************************
 * @fn          lcdConvertChar
 *
 * @brief       Converts ASCII characters to the character set the LCD display uses
 *              (works for all digits and letters and some other common characters)
 *
 * @param       char c
 *
 * @return      none
 */
static char lcdConvertChar(char c)
{
   //character set R in data sheet
   if ((c >= 'a') && (c <= 'z')) //lower case
      c += ('a' - 0xE1);//0x80;
   else if ((c >= 'A') && (c <= 'Z')) //upper case
      c+= ('A' - 0xC1);
   else if ((c >= ' ') && (c <= '#') || (c >= '%') && (c <= '?'))
      c += (' ' - 0xA0);
   else{
      switch (c){
      case '$':
         c = 0x82;
         break;
      case '§':
         c = 0xDF;
         break;
      case '£':
         c = 0x81;
         break;
      case '@':
         c = 0x80;
         break;
      case '[':
         c = 0x8A;
         break;
      case ']':
         c = 0x54;
         break;
      case '_':
         c = 0x5A;
         break;
      case 'æ':
         c = 0x9D;
         break;
      case 'ø':
         c = 0x8C;
         break;
      case 'å':
         c = 0x8F;
         break;
      case 'Æ':
         c = 0x9C;
         break;
      case 'Ø':
         c = 0x8B;
         break;
      case 'Å':
         c = 0x8E;
         break;
      case HAL_LCD_SYMBOL_ARROW_LEFT:
         c = 0x10;
         break;
      case HAL_LCD_SYMBOL_ARROW_RIGHT:
         c = 0x20;
         break;
      case HAL_LCD_SYMBOL_ARROW_UP:
         c = 0x12;
         break;
      case HAL_LCD_SYMBOL_ARROW_DOWN:
         c = 0x30;
         break;
      }
   }
   return c;
}

/***********************************************************************************
 * @fn          lcdWait
 *
 * @brief       This function does the timing of clk
 *
 * @param       none
 *
 * @return      none
 */
static void lcdWait(void)
{
   uint8 i = 0x01;
   while(i--);
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
