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

#ifndef XPAND_SPIN_MULTICHANNEL_H
#define XPAND_SPIN_MULTICHANNEL_H

// Number of nodes composing the sensor network
#define MAX_NUM_NODES 2

#define SPIN_HOLE 0x7F // 127 (max. of signed 8 bit)

typedef struct {
    unsigned int packet_counter;
    char TX_id;
    signed char RSS[MAX_NUM_NODES];
    char CORR[MAX_NUM_NODES];
    signed char TX_channel;
} spinPacket_t;

#endif
