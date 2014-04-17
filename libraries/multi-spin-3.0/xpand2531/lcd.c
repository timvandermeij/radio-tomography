// 
// Authors:
// Folkert Bleichrodt (CWI Amsterdam)
// Tim van der Meij (Leiden University)
// Alyssa Milburn (Leiden University)
//
// The LCD driver contains portions of code made by Texas Instruments.
//
// This file is part of multi-Spin.
// multi-Spin is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// multi-Spin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with multi-Spin. If not, see <http://www.gnu.org/licenses/>.
// 

#include <cc2530.h>
#include "hal_types.h"

// LCD lines
#define LCD_MAX_LINE_COUNT 3

// Set power save mode
#define SET_POWER_SAVE_MODE 0x0C

#define OSC_OFF 0x00
#define OSC_ON 0x01
#define POWER_SAVE_OFF 0x00
#define POWER_SAVE_ON 0x02

// Function set
#define FUNCTION_SET 0x10

#define CGROM 0x00
#define CGRAM 0x01
#define COM_FORWARD 0x00
#define COM_BACKWARD 0x02
#define TWO_LINE 0x00
#define THREE_LINE 0x04

// Set display start line
#define SET_DISPLAY_START_LINE 0x18

#define LINE1 0x00
#define LINE2 0x01
#define LINE3 0x02
#define LINE4 0x03

// Bias control
#define SET_BIAS_CTRL 0x1C

#define BIAS_1_5 0x00
#define BIAS_1_4 0x01

// Power control
#define SET_POWER_CTRL 0x20

#define VOLTAGE_DIVIDER_OFF 0x00
#define VOLTAGE_DIVIDER_ON 0x01
#define CONVERTER_AND_REG_OFF 0x00
#define CONVERTER_AND_REG_ON 0x04

// Set display control
#define SET_DISPLAY_CTRL 0x28

#define DISPLAY_CTRL_ON 0x01
#define DISPLAY_CTRL_OFF 0x00
#define DISPLAY_CTRL_BLINK_ON 0x02
#define DISPLAY_CTRL_BLINK_OFF 0x00
#define DISPLAY_CTRL_CURSOR_ON 0x04
#define DISPLAY_CTRL_CURSOR_OFF 0x00

// Set DD/CGRAM address
#define SET_DDRAM_ADDR 0x80
#define SET_GCRAM_CHAR 0xC0

// Set ICONRAM address
#define SET_ICONRAM_ADDR 0x40
#define CONTRAST_CTRL_REGISTER 0x10

// Set double height
#define SET_DOUBLE_HEIGHT 0x08

#define LINE_1_AND_2 0x01
#define LINE_2_AND_3 0x02
#define NORMAL_DISPLAY 0x00

void sleepUsecs(uint16 t) {
    while(t--) {
        __asm
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        __endasm;
    }
}

void lcdCmd(uint8 m, uint8 c) {
    P1_2 = 0;
    P0_0 = m;
    U1CSR &= ~((1 << 2) | (1 << 1));
    U1DBUF = c;
    while(!(U1CSR & (1 << 1)));
    __asm
    nop
    nop
    nop
    nop
    __endasm;
    P1_2 = 1;
}

void lcdInit(void) {
    // Configure I/O lines
    P0SEL &= ~(1 << 0);
    P0_0 = 1; // Set LCD_MODE
    P0DIR |= (1 << 0);
    P1SEL &= ~(1 << 1);
    P1_1 = 1; // Set LCD_RESET
    P1DIR |= (1 << 1);
    P1SEL &= ~(1 << 2);
    P1_2 = 1; // Set LCD_CS
    P1DIR |= (1 << 2);

    // Configure SPI
    PERCFG |= 0x02; // Use PSI for UART 1 alternative 2
    P1SEL |= (1 << 5); // Enable clock
    P1SEL |= (1 << 6); // Enable master out
    P1SEL |= (1 << 7); // Enable master in
    U1UCR = 0x80;
    U1CSR = 0x00; // Master
    U1GCR = 0x20 | 15;
    U1BAUD = 0;

    // Reset
    P1_1 = 0;
    sleepUsecs(15000);
    P1_1 = 1;
    sleepUsecs(15);

    lcdCmd(0, FUNCTION_SET | CGRAM | COM_FORWARD | THREE_LINE);
    lcdCmd(0, SET_POWER_SAVE_MODE | OSC_OFF | POWER_SAVE_ON);
    lcdCmd(0, SET_POWER_CTRL | VOLTAGE_DIVIDER_ON | CONVERTER_AND_REG_ON);
    lcdCmd(0, SET_BIAS_CTRL | BIAS_1_5);
    sleepUsecs(21000);

    lcdCmd(0, SET_DISPLAY_CTRL | DISPLAY_CTRL_ON | DISPLAY_CTRL_BLINK_OFF | DISPLAY_CTRL_CURSOR_OFF);
}

void lcdWriteString(char *str) {
    while(*str) {
        lcdCmd(1, *(str++));
    }
}

char charForNibble(char n) {
    if(n < 10) {
        return '0' + n;
    }
    return 'A' + (n - 10);
}

void lcdWriteNum(uint16 num) {
    lcdCmd(1, charForNibble((num >> 12) & 0xf));
    lcdCmd(1, charForNibble((num >> 8) & 0xf));
    lcdCmd(1, charForNibble((num >> 4) & 0xf));
    lcdCmd(1, charForNibble(num & 0xf));
}

void lcdWriteNum8(char num) {
    lcdCmd(1, charForNibble((num >> 4) & 0xf));
    lcdCmd(1, charForNibble(num & 0xf));
}

void lcdClear(void) {
    int i;
    // Go to (0,0)
    lcdCmd(0, SET_DDRAM_ADDR);
    // Clear screen
    for(i = 0; i < 16*3; ++i) {
        lcdCmd(1, ' ');
    }
    // Go to (0,0)
    lcdCmd(0, SET_DDRAM_ADDR);
}
