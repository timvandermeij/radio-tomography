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

#ifndef XPANRF_H
#define XPANRF_H

#include <ioCC2531.h>

// Radio registers
#define RSSI_OFFSET -76;
#define CORR_THR                      0x14
#define CCA_THR                       0xF8
#define TXFILTCFG                     XREG( 0x61FA )
#define TXFILTCFG_RESET_VALUE         0x09
#define  PANL     XREG( 0x6172 ) //PAN LSB
#define  PANH     XREG( 0x6173 ) //PAN MSB
#define  SHORT_ADDRL     XREG( 0x6174 ) // Short addresss LSB
#define  SHORT_ADDRH     XREG( 0x6175 ) // Short address MSB

// Immediate strobe processor command instructions (issue twice)
#define ISRXON        0xE3
#define ISTXON        0xE9
#define ISTXONCCA     0xEA
#define ISRFOFF       0xEF
#define ISFLUSHRX     0xED
#define ISFLUSHTX     0xEE

typedef struct {
  short pan;
  short addr;
  char channel;
  char txPower;
} rfConfig_t;

// Prototypes
void radioInit(rfConfig_t rfConfig);
void sendPacket(char* ptr, short len, short pan, short dest, short src);
char receivePacket(char* ptr, char len, signed char* rssi);
char isPacketReady(void);

#endif