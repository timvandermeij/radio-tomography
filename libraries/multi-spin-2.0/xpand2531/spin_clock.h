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

#ifndef XPANMISC_H
#define XPANMISC_H

#define TIMER_TICK_FREQ_32MHZ 0
#define TIMER_TICK_FREQ_16MHZ 1
#define TIMER_TICK_FREQ_8MHZ 2
#define TIMER_TICK_FREQ_4MHZ 3
#define TIMER_TICK_FREQ_2MHZ 4
#define TIMER_TICK_FREQ_1MHZ 5
#define TIMER_TICK_FREQ_500KHZ 6
#define TIMER_TICK_FREQ_250KHZ 7

// Prototypes
void setSysTickFreq(char freq);
void clockInit(void);

#endif