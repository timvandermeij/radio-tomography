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
#include "rf.h"

void radioInit(rfConfig_t rfConfig)
{
  /* This CORR_THR value should be changed to 0x14 before attempting RX. Testing has shown that
   * too many false frames are received if the reset value is used. Make it more likely to detect
   * sync by removing the requirement that both symbols in the SFD must have a correlation value
   * above the correlation threshold, and make sync word detection less likely by raising the
   * correlation threshold.
   */
  MDMCTRL1 = CORR_THR;

  /* tuning adjustments for optimal radio performance; details available in datasheet */
  RXCTRL = 0x3F;

  /* Raises the CCA threshold from about -108dBm to about -80 dBm input level.
   */
  //CCACTRL0 = CCA_THR; //CCA not implemented yet

  /* Makes sync word detection less likely by requiring two zero symbols before the sync word.
   * details available in datasheet.
   */
  MDMCTRL0 = 0x85;

  /* Adjust currents in synthesizer; details available in datasheet. */
  FSCTRL = 0x5A;

  /* Adjust target value for AGC control loop; details available in datasheet. */
  AGCCTRL1 = 0x15;

  /* Disable source address matching */
  SRCMATCH = 0x00;

  /* Tune ADC performance, details available in datasheet. */
  ADCTEST0 = 0x10;
  ADCTEST1 = 0x0E;
  ADCTEST2 = 0x03;

 /* Sets TX anti-aliasing filter to appropriate bandwidth.
  * Reduces spurious emissions close to signal.
  */
  TXFILTCFG = TXFILTCFG_RESET_VALUE;
  
  CSPT = 0xFF; //disable the CSPT register compare function
  TXPOWER = rfConfig.txPower; //Transmitter Power
  FREQCTRL = 11+5*(rfConfig.channel-11); //Frequency setup: f=(2394 + FREQCNTL) MHz

  FRMCTRL0 |= 0x40; //Turn on auto CRC
  
  //Set short address and pan
  SHORT_ADDRL = (char)rfConfig.addr;
  SHORT_ADDRH = (char)(rfConfig.addr>>8);
  PANL = (char)rfConfig.pan;
  PANH = (char)(rfConfig.pan>>8);
  
  //Set up frame filtering
  FRMFILT0 = 0x0D; //Enable frame filt, max_fcf_version set to 11
  FRMFILT1 = 0x10; //Only allow for data packets (no beacons, no ack, etc)
  
  //Turn on RX
  RFST = ISRXON;
  
}

void sendPacket(char* ptr, short len, short pan, short dest, short src)
{
  static char seq;
  seq++;  //This auto increments every function call due to "static" declaration
  
  // Turn off bit 1 of the RF Interrupt Flag. This enables us to see when
  // the sending is done, but no interrupt hookup is necessary.
  RFIRQF1 &= ~0x02; 
  
  //Turn off RX
  RFST = ISRFOFF;
  
  //Flush FIFO (twice to get it to work - datasheet?)
  RFST = ISFLUSHTX; RFST = ISFLUSHTX; 
  
  //Write the length to the TXFIFO
  //Byte count: 2-FCF, 2-FCS, 1-Seq, 8-Address (Pan+short, both dest and src)
  RFD = 2+2+1+8+len;
  
  //Write the FCF and seq
  RFD = 0x01; //FCF1 - No security, compression, ack
  RFD = 0x88; //Use short addr and IEEE 802.15.4 2003 matching
  RFD = seq;
    
  //Write pan and dest address
  RFD = (char)pan; //LSB byte of pan
  RFD = (char)(pan >> 8); //MSB byte of pan 
  RFD = (char)dest; //LSB byte of pan
  RFD = (char)(dest >> 8); //MSB byte of pan
   
  //Write pan and dest address
  RFD = (char)pan; //LSB byte of pan
  RFD = (char)(pan >> 8); //MSB byte of pan
  RFD = (char)src; //LSB byte of pan
  RFD = (char)(src >> 8); //MSB byte of pan
  
  //Write spin packet bytes to TXFIFO
  for (char i=0; i<len; i++)
    {
      RFD = ptr[i];
    }
  
  //Strobe to send
  RFST = ISTXON;
  
  //Wait for send to finish by looking at bit 1 of flag register
  while (!(RFIRQF1 & 0x02));
  
  //Turn on RX
  RFST = ISRXON;
}

char receivePacket(char* ptr, char len, signed char* rssi)
{
  char i; //Helper variable used throughout

  //Clear RX flags
  RFIRQF0 = 0x00;
  
  //Check total length, including frame headers (+14)
  if(RXFIFOCNT != len+14)
  {
    RFST = ISFLUSHRX; RFST = ISFLUSHRX; //Flush the FIFO - 2 times necessary
    return 0; //Error
  }

  for (i = 0; i<12; i++)
  {
    RFD; //Skip through the first 12 bytes, not useful here
  }
  
  //Check to make sure remaining length is correct
  if(RXFIFOCNT != (len + 2))
  {
    RFST = ISFLUSHRX; RFST = ISFLUSHRX; //Flush the FIFO - 2 times necessary
    return 0; //Error
  }
  else
  {
    
    //Copy the payload into the variable at ptr
    for(i=0;i<len;i++)
    {
      ptr[i] = RFD;
    }
    
    //Read the RSSI byte
    *rssi = RFD + RSSI_OFFSET;
    
    //Check CRC
    i = RFD;
    if(!(i & 0x80)) //MSB of last byte is CRC valid bit
      return 0;
    else
      return len;
    
    
  }
}

char isPacketReady(void)
{
  //Check RX interrupt flags
  if(RFIRQF0 & 0x40) //Bit 6 means frame accepted and loaded
    return 1;
  else
    return 0;
}