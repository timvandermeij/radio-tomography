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

// Format of the packet transferred through the serial port of the listen node
typedef struct
{
  spinPacket_t spinPacket;
  uint16 suffix;
} serialPacket_t;
serialPacket_t serialPacket;
spinPacket_t rxPacket;
static rfConfig_t rfConfig;

// Length (in ticks of the clock counter) of a TDMA slot
#define SLOT_LENGTH 7

// ID number of the listen node (it can be defined when multiple listen nodes are
// simultaneously used to collect data)
// #define THIS_NODE_ID 1
#define ADDR 0x1234
#define PAN 0x2011

int counter = 0;
signed char rssi;
char TX_id;
int int_TX_id;

char channel;
static int channel_counter = 0;
int next_channel_time;
int next_reset_radio_time = (MAX_NUM_NODES + 3) * SLOT_LENGTH;

// timer 3: frequency channel hopping
timer34Config_t channel_hoppingConfig;
// timer 4: reset radio module to default frequency channel
timer34Config_t reset_radio_channelConfig;

// ISR for resetting the radio to the default channel
// The "default" channel is the first channel in the array defined in channels.h
void reset_radio_channelISR(void)
{
  timer4Stop();
  rfConfig.channel = channel_sequence[0];
  radioInit(rfConfig);
  ledOn(1); //green LED on
}

// ISR for switching frequency channel
// The listen node loops on the frequency channels defined in channels.h
void channel_hoppingISR(void)
{
  channel_counter++;
  if (channel_counter == CHANNELS_NUMBER)
    channel_counter = 0;
  rfConfig.channel = channel_sequence[channel_counter];
  timer3Stop();
  next_channel_time = (MAX_NUM_NODES + 3) * SLOT_LENGTH;
  channel_hoppingConfig.tickThresh = next_channel_time;
  timer3Init(channel_hoppingConfig);
  timer3Start();
  radioInit(rfConfig);  
}

void main(void)
{
  clockInit();
  ledInit();
  setSysTickFreq(TIMER_TICK_FREQ_250KHZ);
  
  halBoardInit();
  halUartInit(HAL_UART_BAUDRATE_38400,0);
  
  // Set up the radio module
  rfConfig.addr = ADDR;
  rfConfig.pan = PAN;
  rfConfig.channel = channel_sequence[channel_counter];
  rfConfig.txPower = 0xF5; // Max. available TX power
  radioInit(rfConfig);
  
  // Enable interrupts 
  EA = 1;
  
  // Set up Timer4:
  // The ISR fires when the listen node does not receive a packet from the RF sensors
  // in the interval of time corresponding to an entire TDMA cycle
  reset_radio_channelConfig.tickDivider = 7;
  reset_radio_channelConfig.tickThresh = next_reset_radio_time;
  reset_radio_channelConfig.isrPtr = reset_radio_channelISR;
  timer4Init(reset_radio_channelConfig);
  
  // Set up Timer3:
  channel_hoppingConfig.tickDivider = 7;
  channel_hoppingConfig.tickThresh = next_channel_time;
  channel_hoppingConfig.isrPtr = channel_hoppingISR;
  timer3Init(channel_hoppingConfig);
  
  while(1)
  {
    HAL_PROCESS();
    if(isPacketReady())
    {
      if(receivePacket((char*)&rxPacket, sizeof(rxPacket), &rssi) == sizeof(rxPacket))
      {
      	ledOn(2); //red LED on
        ledOff(1); //green LED off
          
        timer4Stop();
        timer3Stop();
        
        flushRXFIFO();
        serialPacket.spinPacket = rxPacket;
        serialPacket.suffix = 0xBEEF;
		// Transfer the packet through the serial port
        halUartWrite((uint8*)&serialPacket,sizeof(serialPacket));
        setSysTickFreq(TIMER_TICK_FREQ_250KHZ);
    	
    	// Update next_channel_time
        TX_id = rxPacket.TX_id;
        int_TX_id = (int)(TX_id);
        next_channel_time = (MAX_NUM_NODES - int_TX_id +2)*SLOT_LENGTH;
        channel_hoppingConfig.tickThresh = next_channel_time;
        timer3Init(channel_hoppingConfig);
        timer3Start();
          
        timer4Init(reset_radio_channelConfig);
        timer4Start();  
        ledOff(2); //red LED off
      }
    }
  }
}