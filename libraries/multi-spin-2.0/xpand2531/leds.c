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

void ledInit(void)
{
  P0DIR |= 0x01;
  P1DIR |= 0x02;
}

void ledOn(char ledID)
{
  switch(ledID)
  {
  case 1:
    P0_0 = 0;
    break;
  case 2:
    P1_1 = 1;
    break;
  default:
    break;
  }
}

void ledOff(char ledID)
{
  switch(ledID)
  {
  case 1:
    P0_0 = 1;
    break;
  case 2:
    P1_1 = 0;
    break;
  default:
    break;
  }
}

void ledToggle(char ledID)
{
  switch(ledID)
  {
  case 1:
    P0_0 ^= 1;
    break;
  case 2:
    P1_1 ^= 1;
    break;
  default:
    break;
  }
}