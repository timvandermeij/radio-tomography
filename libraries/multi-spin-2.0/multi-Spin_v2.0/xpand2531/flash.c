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
#include "flash.h"

short flashWrite(char* ptr, char flashPage, short flashOffset, char len)
{

  // Set up the DMA Config pointers
  flashDMAConfig_t flashDMAConfig;
  flashDMAConfig_t* flashDMAConfigPtr = &flashDMAConfig;
  DMA0CFGH = (char)((short)(flashDMAConfigPtr)>>8);
  DMA0CFGL = (char)((short)(flashDMAConfigPtr));

  // Set up DMA for flash write
  flashDMAConfig.srcaddr_h = (char)((short)(ptr)>>8);
  flashDMAConfig.srcaddr_l = (char)(short)(ptr);
  flashDMAConfig.destaddr_h = (char)((short)(&FWDATA)>>8);
  flashDMAConfig.destaddr_l = (char)(short)(&FWDATA);
  
  flashDMAConfig.vlen_len = 0x00; // Len not set yet, change for high lengths
  flashDMAConfig.len = len; // up to 256 without vlen_len set
  flashDMAConfig.wordsize_tmode_trig = 0x12;
  flashDMAConfig.inc_irq = 0x42; // Interrupts disabled
  
  // Set up flash write addresses high and low
  short addr = flashPage*FLASH_PAGE_SIZE + flashOffset;
  addr /= 4; // Word address
  FADDRL = (char)addr;
  FADDRH = (char)(addr >> 8);
  
  //Arm the DMA
  DMAARM = 0x01;
  
  while (FCTL & 0x80);
  FCTL |= 0x02;         // Triggers the DMA to write
  while (FCTL & 0x80);  // Wait until writing is done.

  return 0;
}

short flashRead(char* ptr, char flashPage, short flashOffset, char count)
{
  
  // Calculate the offset into the containing flash bank as it gets mapped into XDATA.
  char* pData = (char*)(flashOffset + FLASH_PAGE_MAP) +
                 ((flashPage % FLASH_PAGE_PER_BANK) * FLASH_PAGE_SIZE);
  
  char memctr = MEMCTR;  // Save the current bank to restore later

  flashPage /= FLASH_PAGE_PER_BANK;  // Calculate the flash bank from the flash page.

  // Calculate and map the containing flash bank into XDATA.
  MEMCTR = (MEMCTR & 0xF8) | flashPage;
  while (count--)
  {
    *ptr++ = *pData++;
  }

  MEMCTR = memctr;
  
  return 0;
}

void flashErase(char page)
{
  while (FCTL & 0x80); 
  FADDRH = page << 1; 
  FCTL |= 0x01; 
  while (FCTL & 0x80); 
}
