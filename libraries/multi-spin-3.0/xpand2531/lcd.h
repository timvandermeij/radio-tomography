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

#ifndef XPAND_LCD_H
#define XPAND_LCD_H

void sleepUsecs(uint16);
void lcdCmd(uint8, uint8);
void lcdInit(void);
void lcdWriteString(char*);
char charForNibble(char);
void lcdWriteNum(uint16);
void lcdWriteNum8(char);
void lcdClear(void);

#endif
