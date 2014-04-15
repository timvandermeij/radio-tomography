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

//Includes
#include <ioCC2531.h>
#include "hal_defs.h"
#include "hal_led.h"
#include "hal_int.h"
#include "hal_board.h"
#include "hal_assert.h"
#include "hal_mcu.h"
#include "hal_uart.h"
#include "rf.h"
#include "flush_buffers.h"
#include "timers34.h"
#include "leds.h"
#include "clock.h"
#include "spin_clock.h"
#include "spin_multichannel.h"
#include "channels.h"

// ID number of the RF sensor
#define THIS_NODE_ID 1
#define ADDR 0x1234 + (THIS_NODE_ID - 1)
#define PAN 0x2011

spinPacket_t spinPacket,receivedPacket;
static rfConfig_t rfConfig;

// Length (in ticks of the clock counter) of a TDMA slot
#define SLOT_LENGTH 7 //1953.125Hz (1 = 512 us)
// Initialization of the length of the interval of time until the next transmission
int next_TX_time = 255 - (THIS_NODE_ID * SLOT_LENGTH);
// Initialization of the length of time until the next frequency channel switch
int next_channel_time = 255-(THIS_NODE_ID*SLOT_LENGTH);
// Threshold that forces the RF sensor to reset to the default frequency channel
#define RESET_LIMIT 3

long int i = 0;
signed char rssi;
char TX_id;
int int_TX_id;

char channel;
static int channel_counter = 0;
static int TX_counter = 0;
unsigned int RX_packet_counter;

// timer 3: frequency channel hopping
timer34Config_t channel_hoppingConfig;
// timer 4: broadcast a packet
timer34Config_t next_TX_timeConfig;

// ISR for broadcasting a packet
void next_TX_timeISR(void)
{
  timer4Stop();
  next_TX_time = (MAX_NUM_NODES + 3) * SLOT_LENGTH;
  next_TX_timeConfig.tickThresh = next_TX_time;
  timer4Init(next_TX_timeConfig);
  timer4Start();
  
  ledOn(1); //green LED on
  sendPacket((char*)&spinPacket, sizeof(spinPacket), rfConfig.pan, 0xFFFF, rfConfig.addr);
  ledOff(1); //green LED off
  
  // Increase the counter for the number of packets consecutively broadcasted WITHOUT
  // receiving a packet from a neighboring RF sensors
  TX_counter++;
  
  // Reset the array used to store the RSS of the packets broadcasted by the
  // neighboring RF sensors
  for(int i=0; i<MAX_NUM_NODES; i++)
  {
    spinPacket.RSS[i] = SPIN_HOLE;
  }
}

// ISR for switching frequency channel
// The listen node loops on the frequency channels defined in channels.h
void channel_hoppingISR(void)
{
  if(TX_counter < RESET_LIMIT)
  {
  	// Switch to the next frequency channel in the array defined in channels.h
    channel_counter++;
    if(channel_counter == CHANNELS_NUMBER)
      channel_counter = 0;
    rfConfig.channel = channel_sequence[channel_counter];
  }
  else
  {
    // Reset to the default frequency channel
    // The "default" channel is the first channel in the array defined in channels.h
    channel_counter = 0;
    rfConfig.channel = channel_sequence[channel_counter];
    RFST = ISFLUSHRX;
    RFST = ISFLUSHRX;
  }

  timer3Stop();
  next_channel_time = (MAX_NUM_NODES + 3) * SLOT_LENGTH;
  channel_hoppingConfig.tickThresh = next_channel_time;
  timer3Init(channel_hoppingConfig);
  timer3Start();
  radioInit(rfConfig);
  spinPacket.TX_channel = channel_sequence[channel_counter];
}

void main(void)
{  
  clockInit();
  ledInit();
  setSysTickFreq(TIMER_TICK_FREQ_250KHZ);
  
  // Initialize the packet to be broadcasted
  spinPacket.packet_counter = 0;
  spinPacket.TX_id = THIS_NODE_ID;
  for (int u=0; u<MAX_NUM_NODES; u++)
  {
    spinPacket.RSS[u] = SPIN_HOLE;
  }
  spinPacket.TX_channel = channel_sequence[channel_counter];
  
  // Set up the radio module
  rfConfig.addr = ADDR;
  rfConfig.pan = PAN;
  rfConfig.channel = channel_sequence[channel_counter];
  rfConfig.txPower = 0xF5; // Max. available TX power
  radioInit(rfConfig);
  
  // Enable interrupts 
  EA = 1;
  
  //Set up Timer4 for next_TX_time
  next_TX_timeConfig.tickDivider = 7;
  next_TX_timeConfig.tickThresh = next_TX_time;
  next_TX_timeConfig.isrPtr = next_TX_timeISR;
  timer4Init(next_TX_timeConfig);
  
  //Set up Timer3 for next_channel_time
  channel_hoppingConfig.tickDivider = 7;
  channel_hoppingConfig.tickThresh = next_channel_time;
  channel_hoppingConfig.isrPtr = channel_hoppingISR;
  timer3Init(channel_hoppingConfig);

  timer4Start(); 
  while(1)
  {
    if(isPacketReady())
    {
      if(receivePacket((char*)&receivedPacket, sizeof(spinPacket), &rssi) == sizeof(spinPacket))
      {
        timer4Stop();
        timer3Stop();
        // Reset TX_counter each time a packet is received
        TX_counter = 0;
        
        RX_packet_counter = receivedPacket.packet_counter;
        TX_id = receivedPacket.TX_id;
        int_TX_id = (int)(TX_id);
        if ((int_TX_id > 0) & (int_TX_id <= MAX_NUM_NODES))
        {
          ledOn(2); //red LED on
          next_channel_time = (MAX_NUM_NODES - int_TX_id +2) * SLOT_LENGTH;
          channel_hoppingConfig.tickThresh = next_channel_time;
          timer3Init(channel_hoppingConfig);
          timer3Start();                   
          if (int_TX_id > THIS_NODE_ID)
          {
            next_TX_time = MAX_NUM_NODES - int_TX_id;
            next_TX_time += (THIS_NODE_ID - 1);
            next_TX_time = next_TX_time * SLOT_LENGTH;
            next_TX_time += (3 * SLOT_LENGTH);
            spinPacket.packet_counter = RX_packet_counter + MAX_NUM_NODES - int_TX_id + 1;
          }
          else
          {
            next_TX_time = THIS_NODE_ID - 1 - int_TX_id;
            next_TX_time = next_TX_time * SLOT_LENGTH;
            // next_TX_time++;
            spinPacket.packet_counter = RX_packet_counter + THIS_NODE_ID - int_TX_id;
          }          
          next_TX_timeConfig.tickThresh = next_TX_time;
          timer4Init(next_TX_timeConfig);
          timer4Start();
          
          // Update the RSS array
          spinPacket.RSS[int_TX_id-1] = rssi;          
          ledOff(2); //red LED off 
        }
      }
    }
  }
}