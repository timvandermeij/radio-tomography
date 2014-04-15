// 
// SPAN Lab (The University of Utah) and Xandem Technology Copyright 2012-2013
// 
// Author(s):
// Maurizio Bocca (maurizio.bocca@utah.edu)
// Joey Wilson (joey@xandem.com)
// Neal Patwari (neal@xandem.com)
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

#include <ioCC2531.h>

void clockInit(void)
{
  CLKCONCMD = 0x80; //Set up clock speed to use crystal at 32MHz
  while(!(CLKCONSTA == 0x80)); //Wait for ack of clock change
}

void setSysTickFreq(char freq)
{
  // bits 5-3 of CLKCONCMD
  if (freq & 0x02)
    CLKCONCMD |= (1<<5);
  else
    CLKCONCMD &= ~(1<<5);
  if (freq & 0x01)
    CLKCONCMD |= (1<<4);
  else
    CLKCONCMD &= ~(1<<3);
  if (freq & 0x01)
    CLKCONCMD |= (1<<3);
  else
    CLKCONCMD &= ~(1<<3);
}