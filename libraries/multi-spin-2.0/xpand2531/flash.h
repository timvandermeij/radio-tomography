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

#ifndef XPANFLASH_H
#define XPANFLASH_H

#define FLASH_PAGE_SIZE 2048
#define FLASH_PAGE_MAP  0x8000
#define FLASH_PAGE_PER_BANK 16

// DMA config for flash
typedef struct
{
  char srcaddr_h;
  char srcaddr_l;
  char destaddr_h;
  char destaddr_l;
  char vlen_len;
  char len;
  char wordsize_tmode_trig;
  char inc_irq;
} flashDMAConfig_t;

// prototypes
void flashInit(void);
short flashWrite(char* ptr, char flashPage, short flashOffset, char len);
short flashRead(char* ptr, char flashPage, short flashOffset, char len);
void flashErase(char page);

#endif