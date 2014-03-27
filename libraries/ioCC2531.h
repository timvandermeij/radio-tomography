/**************************************************************************************************
 *                                        - ioCC2531.h -
 *
 * Header file with definitions for the Texas Instruments CC2531 low-power System-on-Chip:
 * an 8051-based MCU with 2.4 GHz IEEE 802.15.4 RF transceiver, up to 256 kB FLASH, and a
 * full-speed USB 2.0 compatible controller.
 *
 * This file supports the IAR Embedded Workbench for 8051.
 *
 **************************************************************************************************
 */

#ifndef IOCC2531_H
#define IOCC2531_H

#include "ioCC2530.h"


#ifdef __IAR_SYSTEMS_ICC__
/*  Enable language extensions for macros defined in included files                          */
#pragma language=save
#pragma language=extended
#endif


/* ------------------------------------------------------------------------------------------------
 *                                     Interrupt Alias
 * ------------------------------------------------------------------------------------------------
 */
#define  USB_VECTOR     P2INT_VECTOR /*  USB Interrupt vector, alias for P2INT_VECTOR        */


/* ------------------------------------------------------------------------------------------------
 *                                      SFR Bit Alias
 * ------------------------------------------------------------------------------------------------
 */
#define  USBIF     P2IF              /*  USB Interrupt Flag                                  */
/*       USBIE     P2IE              ,   not in a bit addressable register                   */


/* ------------------------------------------------------------------------------------------------
 *                                       Xdata USB Registers
 * ------------------------------------------------------------------------------------------------
 */
#define  USBADDR     XREG( 0x6200 )  /*  Function Address                                    */
#define  USBPOW      XREG( 0x6201 )  /*  Power/Control Register                              */
#define  USBIIF      XREG( 0x6202 )  /*  IN Endpoints and EP0 Interrupt Flags                */
#define  _XREG6203   XREG( 0x6203 )  /*  Reserved                                            */
#define  USBOIF      XREG( 0x6204 )  /*  OUT Endpoints Interrupt Flags                       */
#define  _XREG6205   XREG( 0x6205 )  /*  Reserved                                            */
#define  USBCIF      XREG( 0x6206 )  /*  Common USB Interrupt Flags                          */
#define  USBIIE      XREG( 0x6207 )  /*  IN Endpoints and EP0 Interrupt Enable Mask          */
#define  _XREG6208   XREG( 0x6208 )  /*  Reserved                                            */
#define  USBOIE      XREG( 0x6209 )  /*  OUT Endpoints Interrupt Enable Mask                 */
#define  _XREG620A   XREG( 0x620A )  /*  Reserved                                            */
#define  USBCIE      XREG( 0x620B )  /*  Common USB Interrupt Enable Mask                    */
#define  USBFRML     XREG( 0x620C )  /*  Current Frame Number (Low byte)                     */
#define  USBFRMH     XREG( 0x620D )  /*  Current Frame Number (High byte)                    */
#define  USBINDEX    XREG( 0x620E )  /*  Selects current endpoint                            */
#define  USBCTRL     XREG( 0x620F )  /*  USB Control Register                                */
#define  USBMAXI     XREG( 0x6210 )  /*  Max. packet size for IN endpoint                    */
#define  USBCS0      XREG( 0x6211 )  /*  EP0 Control and Status               (USBINDEX = 0) */
#define  USBCSIL     XREG( 0x6211 )  /*  IN EP{1-5} Control and Status Low    (USBINDEX > 0) */
#define  USBCSIH     XREG( 0x6212 )  /*  IN EP{1-5} Control and Status High                  */
#define  USBMAXO     XREG( 0x6213 )  /*  Max. packet size for OUT endpoint                   */
#define  USBCSOL     XREG( 0x6214 )  /*  OUT EP{1-5} Control and Status Low                  */
#define  USBCSOH     XREG( 0x6215 )  /*  OUT EP{1-5} Control and Status High                 */
#define  USBCNT0     XREG( 0x6216 )  /*  Number of received bytes in EP0 FIFO (USBINDEX = 0) */
#define  USBCNTL     XREG( 0x6216 )  /*  Number of bytes in OUT FIFO Low      (USBINDEX > 0) */
#define  USBCNTH     XREG( 0x6217 )  /*  Number of bytes in OUT FIFO High                    */
#define  USBF0       XREG( 0x6220 )  /*  Endpoint 0 FIFO                                     */
#define  USBF1       XREG( 0x6222 )  /*  Endpoint 1 FIFO                                     */
#define  USBF2       XREG( 0x6224 )  /*  Endpoint 2 FIFO                                     */
#define  USBF3       XREG( 0x6226 )  /*  Endpoint 3 FIFO                                     */
#define  USBF4       XREG( 0x6228 )  /*  Endpoint 4 FIFO                                     */
#define  USBF5       XREG( 0x622A )  /*  Endpoint 5 FIFO                                     */


/* ------------------------------------------------------------------------------------------------
 */
#ifdef __IAR_SYSTEMS_ICC__
#pragma language=restore
#endif

/**************************************************************************************************
 */
#endif

