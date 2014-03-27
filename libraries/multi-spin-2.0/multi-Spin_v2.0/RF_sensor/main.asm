;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.3.0 #8604 (Jul  8 2013) (Linux)
; This file was generated Thu Mar 27 19:34:24 2014
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-large
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _channel_hoppingISR
	.globl _next_TX_timeISR
	.globl _blink
	.globl _clockInit
	.globl _setSysTickFreq
	.globl _ledOff
	.globl _ledOn
	.globl _ledInit
	.globl _timer4Stop
	.globl _timer4Start
	.globl _timer4Init
	.globl _timer3Stop
	.globl _timer3Start
	.globl _timer3Init
	.globl _isPacketReady
	.globl _receivePacket
	.globl _sendPacket
	.globl _radioInit
	.globl _U1ACTIVE
	.globl _U1TX_BYTE
	.globl _U1RX_BYTE
	.globl _U1ERR
	.globl _U1FE
	.globl _U1SLAVE
	.globl _U1RE
	.globl _U1MODE
	.globl _P2IF
	.globl _UTX0IF
	.globl _UTX1IF
	.globl _P1IF
	.globl _WDTIF
	.globl __IRCON25
	.globl __IRCON26
	.globl __IRCON27
	.globl _T3OVFIF
	.globl _T3CH0IF
	.globl _T3CH1IF
	.globl _T4OVFIF
	.globl _T4CH0IF
	.globl _T4CH1IF
	.globl _T1OVFIM
	.globl __TIMIF7
	.globl _P
	.globl _F1
	.globl _OV
	.globl _RS0
	.globl _RS1
	.globl _F0
	.globl _AC
	.globl _CY
	.globl _DMAIF
	.globl _T1IF
	.globl _T2IF
	.globl _T3IF
	.globl _T4IF
	.globl _P0IF
	.globl __IRCON6
	.globl _STIF
	.globl _DMAIE
	.globl _T1IE
	.globl _T2IE
	.globl _T3IE
	.globl _T4IE
	.globl _P0IE
	.globl __IEN16
	.globl __IEN17
	.globl _RFERRIE
	.globl _ADCIE
	.globl _URX0IE
	.globl _URX1IE
	.globl _ENCIE
	.globl _STIE
	.globl __IEN06
	.globl _EA
	.globl _P2_0
	.globl _P2_1
	.globl _P2_2
	.globl _P2_3
	.globl _P2_4
	.globl __P2_5
	.globl __P2_6
	.globl __P2_7
	.globl _ENCIF_0
	.globl _ENCIF_1
	.globl __S0CON2
	.globl __S0CON3
	.globl __S0CON4
	.globl __S0CON5
	.globl __S0CON6
	.globl __S0CON7
	.globl _P1_0
	.globl _P1_1
	.globl _P1_2
	.globl _P1_3
	.globl _P1_4
	.globl _P1_5
	.globl _P1_6
	.globl _P1_7
	.globl _IT0
	.globl _RFERRIF
	.globl _IT1
	.globl _URX0IF
	.globl __TCON4
	.globl _ADCIF
	.globl __TCON6
	.globl _URX1IF
	.globl _P0_0
	.globl _P0_1
	.globl _P0_2
	.globl _P0_3
	.globl _P0_4
	.globl _P0_5
	.globl _P0_6
	.globl _P0_7
	.globl _P2DIR
	.globl _P1DIR
	.globl _P0DIR
	.globl _U1GCR
	.globl _U1UCR
	.globl _U1BAUD
	.globl _U1DBUF
	.globl _U1CSR
	.globl _P2INP
	.globl _P1INP
	.globl _P2SEL
	.globl _P1SEL
	.globl _P0SEL
	.globl _APCFG
	.globl _ADCCFG
	.globl _PERCFG
	.globl _B
	.globl _T4CC1
	.globl _T4CCTL1
	.globl _T4CC0
	.globl _T4CCTL0
	.globl _T4CTL
	.globl _T4CNT
	.globl _RFIRQF0
	.globl _IRCON2
	.globl _T1CCTL2
	.globl _T1CCTL1
	.globl _T1CCTL0
	.globl _T1CTL
	.globl _T1CNTH
	.globl _T1CNTL
	.globl _RFST
	.globl _ACC
	.globl _T1CC2H
	.globl _T1CC2L
	.globl _T1CC1H
	.globl _T1CC1L
	.globl _T1CC0H
	.globl _T1CC0L
	.globl _RFD
	.globl _TIMIF
	.globl _DMAREQ
	.globl _DMAARM
	.globl _DMA0CFGH
	.globl _DMA0CFGL
	.globl _DMA1CFGH
	.globl _DMA1CFGL
	.globl _DMAIRQ
	.globl _PSW
	.globl _T3CC1
	.globl _T3CCTL1
	.globl _T3CC0
	.globl _T3CCTL0
	.globl _T3CTL
	.globl _T3CNT
	.globl _WDCTL
	.globl __SFRC8
	.globl _MEMCTR
	.globl _CLKCONCMD
	.globl _U0GCR
	.globl _U0UCR
	.globl _T2MSEL
	.globl _U0BAUD
	.globl _U0DBUF
	.globl _IRCON
	.globl _RFERRF
	.globl _SLEEPCMD
	.globl _RNDH
	.globl _RNDL
	.globl _ADCH
	.globl _ADCL
	.globl _IP1
	.globl _IEN1
	.globl __SFRB7
	.globl _ADCCON3
	.globl _ADCCON2
	.globl _ADCCON1
	.globl _ENCCS
	.globl _ENCDO
	.globl _ENCDI
	.globl __SFRB0
	.globl _T1STAT
	.globl _PMUX
	.globl _STLOAD
	.globl _P2IEN
	.globl _P0IEN
	.globl __SFRAA
	.globl _IP0
	.globl _IEN0
	.globl _T2IRQM
	.globl _T2MOVF2
	.globl _T2MOVF1
	.globl _T2MOVF0
	.globl _T2M1
	.globl _T2M0
	.globl _T2IRQF
	.globl _P2
	.globl _FMAP
	.globl _CLKCONSTA
	.globl _SLEEPSTA
	.globl _T2EVTCFG
	.globl _T2CSPCFG
	.globl _S1CON
	.globl _IEN2
	.globl __SFR99
	.globl _S0CON
	.globl _ST2
	.globl _ST1
	.globl _ST0
	.globl _T2CTRL
	.globl _MPAGE
	.globl _DPS
	.globl _RFIRQF1
	.globl _P1
	.globl _P0INP
	.globl __SFR8E
	.globl _P1IEN
	.globl _PICTL
	.globl _P2IFG
	.globl _P1IFG
	.globl _P0IFG
	.globl _TCON
	.globl _PCON
	.globl _U0CSR
	.globl _DPH1
	.globl _DPL1
	.globl _DPH0
	.globl _DPL0
	.globl _SP
	.globl _P0
	.globl _i
	.globl _next_channel_time
	.globl _next_TX_time
	.globl _channel_sequence
	.globl _next_TX_timeConfig
	.globl _channel_hoppingConfig
	.globl _RX_packet_counter
	.globl _channel
	.globl _int_TX_id
	.globl _TX_id
	.globl _rssi
	.globl _receivedPacket
	.globl _spinPacket
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL0	=	0x0082
_DPH0	=	0x0083
_DPL1	=	0x0084
_DPH1	=	0x0085
_U0CSR	=	0x0086
_PCON	=	0x0087
_TCON	=	0x0088
_P0IFG	=	0x0089
_P1IFG	=	0x008a
_P2IFG	=	0x008b
_PICTL	=	0x008c
_P1IEN	=	0x008d
__SFR8E	=	0x008e
_P0INP	=	0x008f
_P1	=	0x0090
_RFIRQF1	=	0x0091
_DPS	=	0x0092
_MPAGE	=	0x0093
_T2CTRL	=	0x0094
_ST0	=	0x0095
_ST1	=	0x0096
_ST2	=	0x0097
_S0CON	=	0x0098
__SFR99	=	0x0099
_IEN2	=	0x009a
_S1CON	=	0x009b
_T2CSPCFG	=	0x009c
_T2EVTCFG	=	0x009c
_SLEEPSTA	=	0x009d
_CLKCONSTA	=	0x009e
_FMAP	=	0x009f
_P2	=	0x00a0
_T2IRQF	=	0x00a1
_T2M0	=	0x00a2
_T2M1	=	0x00a3
_T2MOVF0	=	0x00a4
_T2MOVF1	=	0x00a5
_T2MOVF2	=	0x00a6
_T2IRQM	=	0x00a7
_IEN0	=	0x00a8
_IP0	=	0x00a9
__SFRAA	=	0x00aa
_P0IEN	=	0x00ab
_P2IEN	=	0x00ac
_STLOAD	=	0x00ad
_PMUX	=	0x00ae
_T1STAT	=	0x00af
__SFRB0	=	0x00b0
_ENCDI	=	0x00b1
_ENCDO	=	0x00b2
_ENCCS	=	0x00b3
_ADCCON1	=	0x00b4
_ADCCON2	=	0x00b5
_ADCCON3	=	0x00b6
__SFRB7	=	0x00b7
_IEN1	=	0x00b8
_IP1	=	0x00b9
_ADCL	=	0x00ba
_ADCH	=	0x00bb
_RNDL	=	0x00bc
_RNDH	=	0x00bd
_SLEEPCMD	=	0x00be
_RFERRF	=	0x00bf
_IRCON	=	0x00c0
_U0DBUF	=	0x00c1
_U0BAUD	=	0x00c2
_T2MSEL	=	0x00c3
_U0UCR	=	0x00c4
_U0GCR	=	0x00c5
_CLKCONCMD	=	0x00c6
_MEMCTR	=	0x00c7
__SFRC8	=	0x00c8
_WDCTL	=	0x00c9
_T3CNT	=	0x00ca
_T3CTL	=	0x00cb
_T3CCTL0	=	0x00cc
_T3CC0	=	0x00cd
_T3CCTL1	=	0x00ce
_T3CC1	=	0x00cf
_PSW	=	0x00d0
_DMAIRQ	=	0x00d1
_DMA1CFGL	=	0x00d2
_DMA1CFGH	=	0x00d3
_DMA0CFGL	=	0x00d4
_DMA0CFGH	=	0x00d5
_DMAARM	=	0x00d6
_DMAREQ	=	0x00d7
_TIMIF	=	0x00d8
_RFD	=	0x00d9
_T1CC0L	=	0x00da
_T1CC0H	=	0x00db
_T1CC1L	=	0x00dc
_T1CC1H	=	0x00dd
_T1CC2L	=	0x00de
_T1CC2H	=	0x00df
_ACC	=	0x00e0
_RFST	=	0x00e1
_T1CNTL	=	0x00e2
_T1CNTH	=	0x00e3
_T1CTL	=	0x00e4
_T1CCTL0	=	0x00e5
_T1CCTL1	=	0x00e6
_T1CCTL2	=	0x00e7
_IRCON2	=	0x00e8
_RFIRQF0	=	0x00e9
_T4CNT	=	0x00ea
_T4CTL	=	0x00eb
_T4CCTL0	=	0x00ec
_T4CC0	=	0x00ed
_T4CCTL1	=	0x00ee
_T4CC1	=	0x00ef
_B	=	0x00f0
_PERCFG	=	0x00f1
_ADCCFG	=	0x00f2
_APCFG	=	0x00f2
_P0SEL	=	0x00f3
_P1SEL	=	0x00f4
_P2SEL	=	0x00f5
_P1INP	=	0x00f6
_P2INP	=	0x00f7
_U1CSR	=	0x00f8
_U1DBUF	=	0x00f9
_U1BAUD	=	0x00fa
_U1UCR	=	0x00fb
_U1GCR	=	0x00fc
_P0DIR	=	0x00fd
_P1DIR	=	0x00fe
_P2DIR	=	0x00ff
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_7	=	0x0087
_P0_6	=	0x0086
_P0_5	=	0x0085
_P0_4	=	0x0084
_P0_3	=	0x0083
_P0_2	=	0x0082
_P0_1	=	0x0081
_P0_0	=	0x0080
_URX1IF	=	0x008f
__TCON6	=	0x008e
_ADCIF	=	0x008d
__TCON4	=	0x008c
_URX0IF	=	0x008b
_IT1	=	0x008a
_RFERRIF	=	0x0089
_IT0	=	0x0088
_P1_7	=	0x0097
_P1_6	=	0x0096
_P1_5	=	0x0095
_P1_4	=	0x0094
_P1_3	=	0x0093
_P1_2	=	0x0092
_P1_1	=	0x0091
_P1_0	=	0x0090
__S0CON7	=	0x009f
__S0CON6	=	0x009e
__S0CON5	=	0x009d
__S0CON4	=	0x009c
__S0CON3	=	0x009b
__S0CON2	=	0x009a
_ENCIF_1	=	0x0099
_ENCIF_0	=	0x0098
__P2_7	=	0x00a7
__P2_6	=	0x00a6
__P2_5	=	0x00a5
_P2_4	=	0x00a4
_P2_3	=	0x00a3
_P2_2	=	0x00a2
_P2_1	=	0x00a1
_P2_0	=	0x00a0
_EA	=	0x00af
__IEN06	=	0x00ae
_STIE	=	0x00ad
_ENCIE	=	0x00ac
_URX1IE	=	0x00ab
_URX0IE	=	0x00aa
_ADCIE	=	0x00a9
_RFERRIE	=	0x00a8
__IEN17	=	0x00bf
__IEN16	=	0x00be
_P0IE	=	0x00bd
_T4IE	=	0x00bc
_T3IE	=	0x00bb
_T2IE	=	0x00ba
_T1IE	=	0x00b9
_DMAIE	=	0x00b8
_STIF	=	0x00c7
__IRCON6	=	0x00c6
_P0IF	=	0x00c5
_T4IF	=	0x00c4
_T3IF	=	0x00c3
_T2IF	=	0x00c2
_T1IF	=	0x00c1
_DMAIF	=	0x00c0
_CY	=	0x00d7
_AC	=	0x00d6
_F0	=	0x00d5
_RS1	=	0x00d4
_RS0	=	0x00d3
_OV	=	0x00d2
_F1	=	0x00d1
_P	=	0x00d0
__TIMIF7	=	0x00df
_T1OVFIM	=	0x00de
_T4CH1IF	=	0x00dd
_T4CH0IF	=	0x00dc
_T4OVFIF	=	0x00db
_T3CH1IF	=	0x00da
_T3CH0IF	=	0x00d9
_T3OVFIF	=	0x00d8
__IRCON27	=	0x00ef
__IRCON26	=	0x00ee
__IRCON25	=	0x00ed
_WDTIF	=	0x00ec
_P1IF	=	0x00eb
_UTX1IF	=	0x00ea
_UTX0IF	=	0x00e9
_P2IF	=	0x00e8
_U1MODE	=	0x00ff
_U1RE	=	0x00fe
_U1SLAVE	=	0x00fd
_U1FE	=	0x00fc
_U1ERR	=	0x00fb
_U1RX_BYTE	=	0x00fa
_U1TX_BYTE	=	0x00f9
_U1ACTIVE	=	0x00f8
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
_spinPacket::
	.ds 8
_receivedPacket::
	.ds 8
_rfConfig:
	.ds 6
_rssi::
	.ds 1
_TX_id::
	.ds 1
_int_TX_id::
	.ds 2
_channel::
	.ds 1
_RX_packet_counter::
	.ds 2
_channel_hoppingConfig::
	.ds 4
_next_TX_timeConfig::
	.ds 4
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
_channel_sequence::
	.ds 4
_next_TX_time::
	.ds 2
_next_channel_time::
	.ds 2
_i::
	.ds 4
_channel_counter:
	.ds 2
_TX_counter:
	.ds 2
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_channel_hoppingISR
	.ds	5
	ljmp	_next_TX_timeISR
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'blink'
;------------------------------------------------------------
;arg                       Allocated to registers r6 r7 
;i                         Allocated to registers r4 r5 
;j                         Allocated to registers r4 r5 
;k                         Allocated to registers r2 r3 
;------------------------------------------------------------
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:75: void blink(int arg) {
;	-----------------------------------------
;	 function blink
;	-----------------------------------------
_blink:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6,dpl
	mov	r7,dph
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:78: ledOn(1);
	mov	dpl,#0x01
	push	ar7
	push	ar6
	lcall	_ledOn
	pop	ar6
	pop	ar7
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:79: for (i = 0; i < 4000; ++i) {
	mov	r4,#0x00
	mov	r5,#0x00
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:80: for (k = 0; k < 800; ++k) {
00145$:
	mov	r2,#0x20
	mov	r3,#0x03
00118$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:81: NOP;
	NOP 
	dec	r2
	cjne	r2,#0xFF,00225$
	dec	r3
00225$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:80: for (k = 0; k < 800; ++k) {
	mov	a,r2
	orl	a,r3
	jnz	00118$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:79: for (i = 0; i < 4000; ++i) {
	inc	r4
	cjne	r4,#0x00,00227$
	inc	r5
00227$:
	clr	c
	mov	a,r4
	subb	a,#0xA0
	mov	a,r5
	xrl	a,#0x80
	subb	a,#0x8f
	jc	00145$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:84: ledOff(1);
	mov	dpl,#0x01
	push	ar7
	push	ar6
	lcall	_ledOff
	pop	ar6
	pop	ar7
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:85: for (i = 0; i < 1000; ++i) {
	mov	r4,#0x00
	mov	r5,#0x00
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:86: for (k = 0; k < 400; ++k) {
00149$:
	mov	r2,#0x90
	mov	r3,#0x01
00123$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:87: NOP;
	NOP 
	dec	r2
	cjne	r2,#0xFF,00229$
	dec	r3
00229$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:86: for (k = 0; k < 400; ++k) {
	mov	a,r2
	orl	a,r3
	jnz	00123$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:85: for (i = 0; i < 1000; ++i) {
	inc	r4
	cjne	r4,#0x00,00231$
	inc	r5
00231$:
	clr	c
	mov	a,r4
	subb	a,#0xE8
	mov	a,r5
	xrl	a,#0x80
	subb	a,#0x83
	jc	00149$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:93: for (j = 0; j < 16; ++j) {
	mov	r4,#0x00
	mov	r5,#0x00
00136$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:94: if ((arg>>j) == 0)
	mov	b,r4
	inc	b
	mov	r2,ar6
	mov	r3,ar7
	mov	a,r7
	rlc	a
	mov	ov,c
	sjmp	00234$
00233$:
	mov	c,ov
	mov	a,r3
	rrc	a
	mov	r3,a
	mov	a,r2
	rrc	a
	mov	r2,a
00234$:
	djnz	b,00233$
	mov	a,r2
	orl	a,r3
	jnz	00235$
	ljmp	00113$
00235$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:97: if ((arg>>j) & 1)
	mov	a,r2
	jnb	acc.0,00157$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:98: ledOn(1);
	mov	dpl,#0x01
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_ledOn
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:99: for (i = 0; i < 2000; ++i) {
00157$:
	mov	r2,#0x00
	mov	r3,#0x00
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:100: for (k = 0; k < 400; ++k) {
00155$:
	mov	r0,#0x90
	mov	r1,#0x01
00128$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:101: NOP;
	NOP 
	dec	r0
	cjne	r0,#0xFF,00237$
	dec	r1
00237$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:100: for (k = 0; k < 400; ++k) {
	mov	a,r0
	orl	a,r1
	jnz	00128$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:99: for (i = 0; i < 2000; ++i) {
	inc	r2
	cjne	r2,#0x00,00239$
	inc	r3
00239$:
	clr	c
	mov	a,r2
	subb	a,#0xD0
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x87
	jc	00155$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:104: ledOff(1);
	mov	dpl,#0x01
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_ledOff
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:105: for (i = 0; i < 1000; ++i) {
	mov	r2,#0x00
	mov	r3,#0x00
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:106: for (k = 0; k < 400; ++k) {
00159$:
	mov	r0,#0x90
	mov	r1,#0x01
00133$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:107: NOP;
	NOP 
	dec	r0
	cjne	r0,#0xFF,00241$
	dec	r1
00241$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:106: for (k = 0; k < 400; ++k) {
	mov	a,r0
	orl	a,r1
	jnz	00133$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:105: for (i = 0; i < 1000; ++i) {
	inc	r2
	cjne	r2,#0x00,00243$
	inc	r3
00243$:
	clr	c
	mov	a,r2
	subb	a,#0xE8
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x83
	jc	00159$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:93: for (j = 0; j < 16; ++j) {
	inc	r4
	cjne	r4,#0x00,00245$
	inc	r5
00245$:
	clr	c
	mov	a,r4
	subb	a,#0x10
	mov	a,r5
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00246$
	ljmp	00136$
00246$:
00113$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:113: ledOn(1);
	mov	dpl,#0x01
	lcall	_ledOn
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:114: for (i = 0; i < 4000; ++i) {
	mov	r6,#0x00
	mov	r7,#0x00
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:115: for (k = 0; k < 800; ++k) {
00164$:
	mov	r4,#0x20
	mov	r5,#0x03
00140$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:116: NOP;
	NOP 
	dec	r4
	cjne	r4,#0xFF,00247$
	dec	r5
00247$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:115: for (k = 0; k < 800; ++k) {
	mov	a,r4
	orl	a,r5
	jnz	00140$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:114: for (i = 0; i < 4000; ++i) {
	inc	r6
	cjne	r6,#0x00,00249$
	inc	r7
00249$:
	clr	c
	mov	a,r6
	subb	a,#0xA0
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x8f
	jc	00164$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:119: ledOff(1);
	mov	dpl,#0x01
	ljmp	_ledOff
;------------------------------------------------------------
;Allocation info for local variables in function 'next_TX_timeISR'
;------------------------------------------------------------
;i                         Allocated to registers r6 r7 
;------------------------------------------------------------
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:122: void next_TX_timeISR(void) __interrupt (12)
;	-----------------------------------------
;	 function next_TX_timeISR
;	-----------------------------------------
_next_TX_timeISR:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x00
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:125: timer4Stop();
	lcall	_timer4Stop
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:126: next_TX_time = (MAX_NUM_NODES + 3) * SLOT_LENGTH;
	mov	dptr,#_next_TX_time
	mov	a,#0x31
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:127: next_TX_timeConfig.tickThresh = next_TX_time;
	mov	dptr,#(_next_TX_timeConfig + 0x0001)
	mov	a,#0x31
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:128: timer4Init(&next_TX_timeConfig); // PATCHED: &
	mov	dptr,#_next_TX_timeConfig
	mov	b,#0x00
	lcall	_timer4Init
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:129: timer4Start();
	lcall	_timer4Start
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:132: sendPacket((char*)&spinPacket, sizeof(spinPacket), rfConfig.pan, 0xFFFF, rfConfig.addr);
	mov	dptr,#(_rfConfig + 0x0002)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#_rfConfig
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	r2,#_spinPacket
	mov	r1,#(_spinPacket >> 8)
	mov	r3,#0x00
	push	ar6
	push	ar7
	mov	a,#0xFF
	push	acc
	push	acc
	push	ar4
	push	ar5
	mov	a,#0x08
	push	acc
	clr	a
	push	acc
	mov	dpl,r2
	mov	dph,r1
	mov	b,r3
	lcall	_sendPacket
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:137: TX_counter++;
	mov	dptr,#_TX_counter
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0x00
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:141: for(i=0; i<MAX_NUM_NODES; i++)
	mov	r6,#0x00
	mov	r7,#0x00
00102$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:143: spinPacket.RSS[i] = SPIN_HOLE;
	mov	a,r6
	add	a,#(_spinPacket + 0x0003)
	mov	dpl,a
	mov	a,r7
	addc	a,#((_spinPacket + 0x0003) >> 8)
	mov	dph,a
	mov	a,#0x7F
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:141: for(i=0; i<MAX_NUM_NODES; i++)
	inc	r6
	cjne	r6,#0x00,00110$
	inc	r7
00110$:
	clr	c
	mov	a,r6
	subb	a,#0x04
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jc	00102$
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'channel_hoppingISR'
;------------------------------------------------------------
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:149: void channel_hoppingISR(void) __interrupt (11)
;	-----------------------------------------
;	 function channel_hoppingISR
;	-----------------------------------------
_channel_hoppingISR:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x00
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:151: if(TX_counter < RESET_LIMIT)
	mov	dptr,#_TX_counter
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	clr	c
	mov	a,r6
	subb	a,#0x03
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00104$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:154: channel_counter++;
	mov	dptr,#_channel_counter
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0x00
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:155: if(channel_counter == CHANNELS_NUMBER)
	mov	dptr,#_channel_counter
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	cjne	r6,#0x04,00102$
	cjne	r7,#0x00,00102$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:156: channel_counter = 0;
	mov	dptr,#_channel_counter
	clr	a
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
00102$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:157: rfConfig.channel = channel_sequence[channel_counter];
	mov	dptr,#_channel_counter
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	a,r6
	add	a,#_channel_sequence
	mov	dpl,a
	mov	a,r7
	addc	a,#(_channel_sequence >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#(_rfConfig + 0x0004)
	movx	@dptr,a
	sjmp	00105$
00104$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:163: channel_counter = 0;
	mov	dptr,#_channel_counter
	clr	a
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:164: rfConfig.channel = channel_sequence[channel_counter];
	mov	dptr,#_channel_sequence
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#(_rfConfig + 0x0004)
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:165: RFST = ISFLUSHRX;
	mov	_RFST,#0xED
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:166: RFST = ISFLUSHRX;
	mov	_RFST,#0xED
00105$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:169: timer3Stop();
	lcall	_timer3Stop
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:170: next_channel_time = (MAX_NUM_NODES + 3) * SLOT_LENGTH;
	mov	dptr,#_next_channel_time
	mov	a,#0x31
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:171: channel_hoppingConfig.tickThresh = next_channel_time;
	mov	dptr,#(_channel_hoppingConfig + 0x0001)
	mov	a,#0x31
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:172: timer3Init(&channel_hoppingConfig); // PATCHED: &
	mov	dptr,#_channel_hoppingConfig
	mov	b,#0x00
	lcall	_timer3Init
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:173: timer3Start();
	lcall	_timer3Start
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:174: radioInit(&rfConfig); // PATCHED: &
	mov	dptr,#_rfConfig
	mov	b,#0x00
	lcall	_radioInit
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:175: spinPacket.TX_channel = channel_sequence[channel_counter];
	mov	dptr,#_channel_counter
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	a,r6
	add	a,#_channel_sequence
	mov	dpl,a
	mov	a,r7
	addc	a,#(_channel_sequence >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	dptr,#(_spinPacket + 0x0007)
	movx	@dptr,a
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;u                         Allocated to registers r6 r7 
;------------------------------------------------------------
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:178: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:181: clockInit();
	lcall	_clockInit
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:182: ledInit();
	lcall	_ledInit
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:183: setSysTickFreq(TIMER_TICK_FREQ_250KHZ);
	mov	dpl,#0x07
	lcall	_setSysTickFreq
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:186: spinPacket.packet_counter = 0;
	mov	dptr,#_spinPacket
	clr	a
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:187: spinPacket.TX_id = THIS_NODE_ID;
	mov	dptr,#(_spinPacket + 0x0002)
	mov	a,#0x04
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:188: for (u=0; u<MAX_NUM_NODES; u++)
	mov	r6,#0x00
	mov	r7,#0x00
00114$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:190: spinPacket.RSS[u] = SPIN_HOLE;
	mov	a,r6
	add	a,#(_spinPacket + 0x0003)
	mov	dpl,a
	mov	a,r7
	addc	a,#((_spinPacket + 0x0003) >> 8)
	mov	dph,a
	mov	a,#0x7F
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:188: for (u=0; u<MAX_NUM_NODES; u++)
	inc	r6
	cjne	r6,#0x00,00140$
	inc	r7
00140$:
	clr	c
	mov	a,r6
	subb	a,#0x04
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jc	00114$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:192: spinPacket.TX_channel = channel_sequence[channel_counter];
	mov	dptr,#_channel_counter
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	a,r6
	add	a,#_channel_sequence
	mov	dpl,a
	mov	a,r7
	addc	a,#(_channel_sequence >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	dptr,#(_spinPacket + 0x0007)
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:195: rfConfig.addr = ADDR;
	mov	dptr,#(_rfConfig + 0x0002)
	mov	a,#0x37
	movx	@dptr,a
	mov	a,#0x12
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:196: rfConfig.pan = PAN;
	mov	dptr,#_rfConfig
	mov	a,#0x11
	movx	@dptr,a
	mov	a,#0x20
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:197: rfConfig.channel = channel_sequence[channel_counter];
	mov	dptr,#_channel_counter
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	a,r6
	add	a,#_channel_sequence
	mov	dpl,a
	mov	a,r7
	addc	a,#(_channel_sequence >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	dptr,#(_rfConfig + 0x0004)
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:198: rfConfig.txPower = 0xF5; // Max. available TX power
	mov	dptr,#(_rfConfig + 0x0005)
	mov	a,#0xF5
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:199: radioInit(&rfConfig); // PATCHED: &
	mov	dptr,#_rfConfig
	mov	b,#0x00
	lcall	_radioInit
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:212: EA = 1;
	setb	_EA
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:215: next_TX_timeConfig.tickDivider = 7;
	mov	dptr,#_next_TX_timeConfig
	mov	a,#0x07
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:216: next_TX_timeConfig.tickThresh = next_TX_time;
	mov	dptr,#_next_TX_time
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	dptr,#(_next_TX_timeConfig + 0x0001)
	mov	a,r6
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:217: next_TX_timeConfig.isrPtr = next_TX_timeISR;
	mov	dptr,#(_next_TX_timeConfig + 0x0002)
	mov	a,#_next_TX_timeISR
	movx	@dptr,a
	mov	a,#(_next_TX_timeISR >> 8)
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:218: timer4Init(&next_TX_timeConfig); // PATCHED: &
	mov	dptr,#_next_TX_timeConfig
	mov	b,#0x00
	lcall	_timer4Init
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:221: channel_hoppingConfig.tickDivider = 7;
	mov	dptr,#_channel_hoppingConfig
	mov	a,#0x07
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:222: channel_hoppingConfig.tickThresh = next_channel_time;
	mov	dptr,#_next_channel_time
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	dptr,#(_channel_hoppingConfig + 0x0001)
	mov	a,r6
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:223: channel_hoppingConfig.isrPtr = channel_hoppingISR;
	mov	dptr,#(_channel_hoppingConfig + 0x0002)
	mov	a,#_channel_hoppingISR
	movx	@dptr,a
	mov	a,#(_channel_hoppingISR >> 8)
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:224: timer3Init(&channel_hoppingConfig); // PATCHED: &
	mov	dptr,#_channel_hoppingConfig
	mov	b,#0x00
	lcall	_timer3Init
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:226: timer4Start();
	lcall	_timer4Start
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:227: while(1)
00112$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:229: if(isPacketReady())
	lcall	_isPacketReady
	mov	a,dpl
	jz	00112$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:231: if(receivePacket((char*)&receivedPacket, sizeof(spinPacket), &rssi) == sizeof(spinPacket))
	mov	r6,#_receivedPacket
	mov	r7,#(_receivedPacket >> 8)
	mov	r5,#0x00
	mov	a,#_rssi
	push	acc
	mov	a,#(_rssi >> 8)
	push	acc
	clr	a
	push	acc
	mov	a,#0x08
	push	acc
	mov	dpl,r6
	mov	dph,r7
	mov	b,r5
	lcall	_receivePacket
	mov	r7,dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	cjne	r7,#0x08,00112$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:233: timer4Stop();
	lcall	_timer4Stop
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:234: timer3Stop();
	lcall	_timer3Stop
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:236: TX_counter = 0;
	mov	dptr,#_TX_counter
	clr	a
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:238: RX_packet_counter = receivedPacket.packet_counter;
	mov	dptr,#_receivedPacket
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#_RX_packet_counter
	mov	a,r6
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:239: TX_id = receivedPacket.TX_id;
	mov	dptr,#(_receivedPacket + 0x0002)
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#_TX_id
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:240: int_TX_id = (int)(TX_id);
	mov	a,r7
	rlc	a
	subb	a,acc
	mov	r6,a
	mov	dptr,#_int_TX_id
	mov	a,r7
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:241: if ((int_TX_id > 0) & (int_TX_id <= MAX_NUM_NODES))
	clr	c
	clr	a
	subb	a,r7
	clr	a
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	clr	a
	rlc	a
	mov	r5,a
	clr	c
	mov	a,#0x04
	subb	a,r7
	clr	a
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	cpl	c
	clr	a
	rlc	a
	mov	r7,a
	anl	a,r5
	jnz	00146$
	ljmp	00112$
00146$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:243: ledOn(1); //red LED on
	mov	dpl,#0x01
	lcall	_ledOn
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:244: next_channel_time = (MAX_NUM_NODES - int_TX_id +2) * SLOT_LENGTH;
	mov	dptr,#_int_TX_id
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	a,#0x06
	clr	c
	subb	a,r6
	mov	r6,a
	clr	a
	subb	a,r7
	mov	r7,a
	push	ar6
	push	ar7
	mov	dptr,#0x0007
	lcall	__mulint
	mov	r6,dpl
	mov	r7,dph
	dec	sp
	dec	sp
	mov	dptr,#_next_channel_time
	mov	a,r6
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:245: channel_hoppingConfig.tickThresh = next_channel_time;
	mov	dptr,#(_channel_hoppingConfig + 0x0001)
	mov	a,r6
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:246: timer3Init(&channel_hoppingConfig); // PATCHED: &
	mov	dptr,#_channel_hoppingConfig
	mov	b,#0x00
	lcall	_timer3Init
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:247: timer3Start();                   
	lcall	_timer3Start
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:248: if (int_TX_id > THIS_NODE_ID)
	mov	dptr,#_int_TX_id
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	clr	c
	mov	a,#0x04
	subb	a,r6
	clr	a
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00103$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:250: next_TX_time = MAX_NUM_NODES - int_TX_id;
	mov	a,#0x04
	clr	c
	subb	a,r6
	mov	r4,a
	clr	a
	subb	a,r7
	mov	r5,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:251: next_TX_time += (THIS_NODE_ID - 1);
	mov	a,#0x03
	add	a,r4
	mov	r4,a
	clr	a
	addc	a,r5
	mov	r5,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:252: next_TX_time = next_TX_time * SLOT_LENGTH;
	push	ar7
	push	ar6
	push	ar4
	push	ar5
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:253: next_TX_time += (3 * SLOT_LENGTH);
	mov	dptr,#0x0007
	lcall	__mulint
	mov	r4,dpl
	mov	r5,dph
	dec	sp
	dec	sp
	pop	ar6
	pop	ar7
	mov	dptr,#_next_TX_time
	mov	a,#0x15
	add	a,r4
	movx	@dptr,a
	clr	a
	addc	a,r5
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:254: spinPacket.packet_counter = RX_packet_counter + MAX_NUM_NODES - int_TX_id + 1;
	mov	a,#0x05
	clr	c
	subb	a,r6
	mov	r4,a
	clr	a
	subb	a,r7
	mov	r5,a
	mov	dptr,#_RX_packet_counter
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	a,r4
	add	a,r2
	mov	r2,a
	mov	a,r5
	addc	a,r3
	mov	r3,a
	mov	dptr,#_spinPacket
	mov	a,r2
	movx	@dptr,a
	mov	a,r3
	inc	dptr
	movx	@dptr,a
	sjmp	00104$
00103$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:258: next_TX_time = THIS_NODE_ID - 1 - int_TX_id;
	mov	a,#0x03
	clr	c
	subb	a,r6
	mov	r4,a
	clr	a
	subb	a,r7
	mov	r5,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:259: next_TX_time = next_TX_time * SLOT_LENGTH;
	push	ar7
	push	ar6
	push	ar4
	push	ar5
	mov	dptr,#0x0007
	lcall	__mulint
	mov	r4,dpl
	mov	r5,dph
	dec	sp
	dec	sp
	pop	ar6
	pop	ar7
	mov	dptr,#_next_TX_time
	mov	a,r4
	movx	@dptr,a
	mov	a,r5
	inc	dptr
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:261: spinPacket.packet_counter = RX_packet_counter + THIS_NODE_ID - int_TX_id;
	mov	dptr,#_RX_packet_counter
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	a,#0x04
	add	a,r4
	mov	r4,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	a,r4
	clr	c
	subb	a,r6
	mov	r4,a
	mov	a,r5
	subb	a,r7
	mov	r5,a
	mov	dptr,#_spinPacket
	mov	a,r4
	movx	@dptr,a
	mov	a,r5
	inc	dptr
	movx	@dptr,a
00104$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:263: next_TX_timeConfig.tickThresh = next_TX_time;
	mov	dptr,#_next_TX_time
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	dptr,#(_next_TX_timeConfig + 0x0001)
	mov	a,r6
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:264: timer4Init(&next_TX_timeConfig); // PATCHED: &
	mov	dptr,#_next_TX_timeConfig
	mov	b,#0x00
	lcall	_timer4Init
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:265: timer4Start();
	lcall	_timer4Start
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:268: spinPacket.RSS[int_TX_id-1] = rssi;          
	mov	dptr,#_int_TX_id
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	a,r6
	dec	a
	add	a,#(_spinPacket + 0x0003)
	mov	r6,a
	clr	a
	addc	a,#((_spinPacket + 0x0003) >> 8)
	mov	r7,a
	mov	dptr,#_rssi
	movx	a,@dptr
	mov	dpl,r6
	mov	dph,r7
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.c:269: ledOff(1); //red LED off 
	mov	dpl,#0x01
	lcall	_ledOff
	ljmp	00112$
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
__xinit__channel_sequence:
	.db #0x1A	;  26
	.db #0x0B	;  11
	.db #0x10	;  16
	.db #0x15	;  21
__xinit__next_TX_time:
	.byte #0xE3,#0x00	;  227
__xinit__next_channel_time:
	.byte #0xE3,#0x00	;  227
__xinit__i:
	.byte #0x00,#0x00,#0x00,#0x00	;  0
__xinit__channel_counter:
	.byte #0x00,#0x00	;  0
__xinit__TX_counter:
	.byte #0x00,#0x00	;  0
	.area CABS    (ABS,CODE)
