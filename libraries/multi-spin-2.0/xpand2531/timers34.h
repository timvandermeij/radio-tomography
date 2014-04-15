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

#ifndef XPANTIMER34_H
#define XPANTIMER34_H

typedef struct
{
  char tickDivider;
  char tickThresh;
  void (*isrPtr)(void);
} timer34Config_t;

void timer3Init(timer34Config_t config);
void timer3Start(void);
void timer3Stop(void);

void timer4Init(timer34Config_t config);
void timer4Start(void);
void timer4Stop(void);

#endif

