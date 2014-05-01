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

#include <cc2530.h>
#include "hal_defs.h"
#include "hal_led.h"
#include "hal_int.h"
#include "hal_assert.h"
#include "hal_mcu.h"
#include "hal_uart.h"
#include "rf.h"
#include "flush_buffers.h"
#include "timers34.h"
#include "leds.h"
#include "spin_clock.h"
#include "spin_multichannel.h"
#include "channels.h"

// RF sensor configuration
#define PAN 0x2011

// Length (in ticks of the clock counter) of a TDMA slot
#define SLOT_LENGTH 7 // 1953.125Hz (1 = 512 us)

// Threshold that forces the RF sensor to reset to the default frequency channel
#define RESET_LIMIT 3

// Amplifier
#define PA_LNA_RX_HGM() { uint8 i; P0_7 = 1; for(i = 0; i < 8; i++) { NOP; } }

spinPacket_t spinPacket, receivedPacket;
configurationPacket_t configPacket;
static rfConfig_t rfConfig;

// Flash data that contains the MAC address of the node
#define PAGE_SIZE 1024
const unsigned short __xdata __at (0x780C) flashDataAddr[PAGE_SIZE];

int nodeId, numNodes, packetSize;
int next_TX_time, next_channel_time;
long int i = 0;
signed char rssi;
char corr;
char TX_id;
int int_TX_id;

char channel;
static int channel_counter = 0;
static int TX_counter = 0;
unsigned int RX_packet_counter;

// Timer 3: frequency channel hopping
timer34Config_t channel_hoppingConfig;
// Timer 4: broadcast a packet
timer34Config_t next_TX_timeConfig;

void next_TX_timeISR(void) __interrupt (12) {
    int i;
    timer4Stop();
    next_TX_time = (numNodes + 3) * SLOT_LENGTH;
    next_TX_timeConfig.tickThresh = next_TX_time;
    timer4Init(&next_TX_timeConfig);
    timer4Start();

    ledOn(1); // Green LED on
    sendPacket((char*)&spinPacket, packetSize, rfConfig.pan, 0xFFFF, rfConfig.addr);
    ledOff(1); // Green LED off

    // Increase the counter for the number of packets consecutively broadcasted WITHOUT
    // receiving a packet from a neighboring RF sensors
    TX_counter++;
  
    // Reset the array used to store the RSS and correlation values of the packets
    // broadcasted by the neighboring RF sensors
    for(i = 0; i < numNodes; i++) {
        spinPacket.data[i].RSS = SPIN_HOLE;
        spinPacket.data[i].CORR = SPIN_HOLE;
    }
}

// ISR for switching frequency channel
// The RF node loops on the frequency channels defined in channels.h
void channel_hoppingISR(void) __interrupt (11) {
    if(TX_counter < RESET_LIMIT) {
  	    // Switch to the next frequency channel in the array defined in channels.h
        channel_counter++;
        if(channel_counter == CHANNELS_NUMBER) {
            channel_counter = 0;
        }
        rfConfig.channel = channel_sequence[channel_counter];
    } else {
        // Reset to the default frequency channel
        // The default channel is the first channel in the array defined in channels.h
        channel_counter = 0;
        rfConfig.channel = channel_sequence[channel_counter];
        RFST = ISFLUSHRX;
        RFST = ISFLUSHRX;
    }

    timer3Stop();
    next_channel_time = (numNodes + 3) * SLOT_LENGTH;
    channel_hoppingConfig.tickThresh = next_channel_time;
    timer3Init(&channel_hoppingConfig);
    timer3Start();
    radioInit(&rfConfig);
    spinPacket.header.TX_channel = channel_sequence[channel_counter];
}

void main(void) {
    int u, configured = 0, macsEqual = 1;

    clockInit();
    ledInit();
    setSysTickFreq(TIMER_TICK_FREQ_250KHZ);

    // Set up the radio module
    rfConfig.addr = 0x1234;
    rfConfig.pan = PAN;
    rfConfig.channel = channel_sequence[channel_counter];
    rfConfig.txPower = 0xF5; // Max. available TX power
    radioInit(&rfConfig);

    // Set up the amplifier
    AGCCTRL1 = 0x15;
    FSCAL1 = 0x0;
    RFC_OBS_CTRL0 = 0x68;
    RFC_OBS_CTRL1 = 0x6A;
    OBSSEL1 = 0xFB;
    OBSSEL4 = 0xFC;
    P0DIR |= 0x80;
    PA_LNA_RX_HGM();

    // Enable interrupts 
    EA = 1;

    // Wait for the configuration packet and configure the node
    while(!configured) {
        if(isPacketReady()) {
            if(receivePacket((char*)&configPacket, sizeof(configPacket), &rssi, &corr) == sizeof(configPacket)) {
                // Check if the MAC addresses are equal
                macsEqual = 1;
                for(u = 0; u < 4; u++) { // 4 because fashDataAddr is read 2 bytes at a time
                    if(configPacket.macAddress[2*u] != (flashDataAddr[u] >> 8) ||
                        configPacket.macAddress[(2*u)+1] != ((flashDataAddr[u] << 8) >> 8)) {
                        macsEqual = 0;
                    }
                }
                if(macsEqual) {
                    nodeId = configPacket.nodeId;
                    numNodes = configPacket.numNodes;
                    packetSize = sizeof(spinHeader) + sizeof(spinData) * numNodes;
                    configured = 1;
                }
            }
        }
    }

    // Reconfigure the radio with the assigned node ID
    rfConfig.addr = 0x1234 + (nodeId - 1);
    radioInit(&rfConfig);

    // Initialization of the length of the interval of time until the next transmission
    next_TX_time = 255 - (nodeId * SLOT_LENGTH);
    // Initialization of the length of time until the next frequency channel switch
    next_channel_time = 255 - (nodeId * SLOT_LENGTH);

    // Initialize the packet to be broadcasted
    spinPacket.header.packet_counter = 0;
    spinPacket.header.TX_id = nodeId;
    for(u = 0; u < numNodes; u++) {
        spinPacket.data[u].RSS = SPIN_HOLE;
        spinPacket.data[u].CORR = SPIN_HOLE;
    }
    spinPacket.header.TX_channel = channel_sequence[channel_counter];

    // Set up timer 4 for next_TX_time
    next_TX_timeConfig.tickDivider = 7;
    next_TX_timeConfig.tickThresh = next_TX_time;
    next_TX_timeConfig.isrPtr = next_TX_timeISR;
    timer4Init(&next_TX_timeConfig);
  
    // Set up timer 3 for next_channel_time
    channel_hoppingConfig.tickDivider = 7;
    channel_hoppingConfig.tickThresh = next_channel_time;
    channel_hoppingConfig.isrPtr = channel_hoppingISR;
    timer3Init(&channel_hoppingConfig);

    timer4Start();
    while(1) {
        if(isPacketReady()) {
            if(receivePacket((char*)&receivedPacket, packetSize, &rssi, &corr) == packetSize) {
                timer4Stop();
                timer3Stop();
        
                // Reset TX_counter each time a packet is received
                TX_counter = 0;

                RX_packet_counter = receivedPacket.header.packet_counter;
                TX_id = receivedPacket.header.TX_id;
                int_TX_id = (int)(TX_id);
                
                if((int_TX_id > 0) & (int_TX_id <= numNodes)) {
                    ledOn(2); // Red LED on
                    next_channel_time = (numNodes - int_TX_id + 2) * SLOT_LENGTH;
                    channel_hoppingConfig.tickThresh = next_channel_time;
                    timer3Init(&channel_hoppingConfig);
                    timer3Start();                   
                    
                    if(int_TX_id > nodeId) {
                        next_TX_time = numNodes - int_TX_id;
                        next_TX_time += (nodeId - 1);
                        next_TX_time = next_TX_time * SLOT_LENGTH;
                        next_TX_time += (3 * SLOT_LENGTH);
                        spinPacket.header.packet_counter = RX_packet_counter + numNodes - int_TX_id + 1;
                    } else {
                        next_TX_time = (nodeId - 1) - int_TX_id;
                        next_TX_time = next_TX_time * SLOT_LENGTH;
                        spinPacket.header.packet_counter = RX_packet_counter + nodeId - int_TX_id;
                    }

                    next_TX_timeConfig.tickThresh = next_TX_time;
                    timer4Init(&next_TX_timeConfig);
                    timer4Start();
          
                    // Update the RSS and CORR arrays
                    spinPacket.data[int_TX_id - 1].RSS = rssi;
                    spinPacket.data[int_TX_id - 1].CORR = corr;
                    ledOff(2); // Red LED off 
                }
            }
        }
    }
}
