;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.3.0 #8604 (Jul  8 2013) (Linux)
; This file was generated Thu Mar 27 19:34:24 2014
;--------------------------------------------------------
	.module rf
	.optsdcc -mmcs51 --model-large
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _blink
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
	.globl _radioInit
	.globl _sendPacket
	.globl _receivePacket
	.globl _isPacketReady
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
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
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
_sendPacket_seq_1_12:
	.ds 1
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
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
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'radioInit'
;------------------------------------------------------------
;rfConfig                  Allocated to registers r5 r6 r7 
;------------------------------------------------------------
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:25: void radioInit(rfConfig_t *rfConfig)
;	-----------------------------------------
;	 function radioInit
;	-----------------------------------------
_radioInit:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:33: MDMCTRL1 = CORR_THR;
	mov	dptr,#0x61A9
	mov	a,#0x14
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:36: RXCTRL = 0x3F;
	mov	dptr,#0x61AB
	mov	a,#0x3F
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:45: MDMCTRL0 = 0x85;
	mov	dptr,#0x61A8
	mov	a,#0x85
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:48: FSCTRL = 0x5A;
	mov	dptr,#0x61AC
	mov	a,#0x5A
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:51: AGCCTRL1 = 0x15;
	mov	dptr,#0x61B2
	mov	a,#0x15
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:54: SRCMATCH = 0x00;
	mov	dptr,#0x6182
	clr	a
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:57: ADCTEST0 = 0x10;
	mov	dptr,#0x61B5
	mov	a,#0x10
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:58: ADCTEST1 = 0x0E;
	mov	dptr,#0x61B6
	mov	a,#0x0E
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:59: ADCTEST2 = 0x03;
	mov	dptr,#0x61B7
	mov	a,#0x03
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:64: TXFILTCFG = TXFILTCFG_RESET_VALUE;
	mov	dptr,#0x61FA
	mov	a,#0x09
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:66: CSPT = 0xFF; //disable the CSPT register compare function
	mov	dptr,#0x61E5
	mov	a,#0xFF
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:67: TXPOWER = rfConfig->txPower; //Transmitter Power
	mov	a,#0x05
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	dptr,#0x6190
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:68: FREQCTRL = 11+5*(rfConfig->channel-11); //Frequency setup: f=(2394 + FREQCNTL) MHz
	mov	a,#0x04
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	add	a,#0xF5
	mov	b,#0x05
	mul	ab
	add	a,#0x0B
	mov	dptr,#0x618F
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:70: FRMCTRL0 |= 0x40; //Turn on auto CRC
	mov	dptr,#0x6189
	mov	a,#0x40
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:73: SHORT_ADDRL = (char)rfConfig->addr;
	mov	a,#0x02
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	dptr,#0x6174
	mov	a,r0
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:74: SHORT_ADDRH = (char)(rfConfig->addr>>8);
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	mov	dptr,#0x6175
	mov	a,r2
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:75: PANL = (char)rfConfig->pan;
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	dptr,#0x6172
	mov	a,r3
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:76: PANH = (char)(rfConfig->pan>>8);
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	dptr,#0x6173
	mov	a,r5
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:79: FRMFILT0 = 0x0D; //Enable frame filt, max_fcf_version set to 11
	mov	dptr,#0x6180
	mov	a,#0x0D
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:80: FRMFILT1 = 0x10; //Only allow for data packets (no beacons, no ack, etc)
	mov	dptr,#0x6181
	mov	a,#0x10
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:83: RFST = ISRXON;
	mov	_RFST,#0xE3
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'sendPacket'
;------------------------------------------------------------
;len                       Allocated to stack - _bp -4
;pan                       Allocated to stack - _bp -6
;dest                      Allocated to stack - _bp -8
;src                       Allocated to stack - _bp -10
;ptr                       Allocated to stack - _bp +1
;i                         Allocated to registers r4 
;seq                       Allocated with name '_sendPacket_seq_1_12'
;------------------------------------------------------------
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:87: void sendPacket(char* ptr, short len, short pan, short dest, short src)
;	-----------------------------------------
;	 function sendPacket
;	-----------------------------------------
_sendPacket:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:91: seq++;  //This auto increments every function call due to "static" declaration
	mov	dptr,#_sendPacket_seq_1_12
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:95: RFIRQF1 &= ~0x02; 
	mov	r4,_RFIRQF1
	mov	a,#0xFD
	anl	a,r4
	mov	_RFIRQF1,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:98: RFST = ISRFOFF;
	mov	_RFST,#0xEF
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:101: RFST = ISFLUSHTX; RFST = ISFLUSHTX; 
	mov	_RFST,#0xEE
	mov	_RFST,#0xEE
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:105: RFD = 2+2+1+8+len;
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	ar4,@r0
	mov	a,#0x0D
	add	a,r4
	mov	_RFD,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:108: RFD = 0x01; //FCF1 - No security, compression, ack
	mov	_RFD,#0x01
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:109: RFD = 0x88; //Use short addr and IEEE 802.15.4 2003 matching
	mov	_RFD,#0x88
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:110: RFD = seq;
	mov	dptr,#_sendPacket_seq_1_12
	movx	a,@dptr
	mov	_RFD,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:113: RFD = (char)pan; //LSB byte of pan
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	ar4,@r0
	mov	_RFD,r4
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:114: RFD = (char)(pan >> 8); //MSB byte of pan 
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	inc	r0
	mov	ar3,@r0
	mov	_RFD,r3
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:115: RFD = (char)dest; //LSB byte of pan
	mov	a,_bp
	add	a,#0xf8
	mov	r0,a
	mov	_RFD,@r0
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:116: RFD = (char)(dest >> 8); //MSB byte of pan
	mov	a,_bp
	add	a,#0xf8
	mov	r0,a
	inc	r0
	mov	_RFD,@r0
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:119: RFD = (char)pan; //LSB byte of pan
	mov	_RFD,r4
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:120: RFD = (char)(pan >> 8); //MSB byte of pan
	mov	_RFD,r3
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:121: RFD = (char)src; //LSB byte of pan
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	_RFD,@r0
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:122: RFD = (char)(src >> 8); //MSB byte of pan
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	inc	r0
	mov	_RFD,@r0
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:125: for (i=0; i<len; i++)
	mov	r4,#0x00
00106$:
	mov	a,r4
	mov	r2,a
	rlc	a
	subb	a,acc
	mov	r3,a
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	clr	c
	mov	a,r2
	subb	a,@r0
	mov	a,r3
	xrl	a,#0x80
	inc	r0
	mov	b,@r0
	xrl	b,#0x80
	subb	a,b
	jnc	00101$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:127: RFD = ptr[i];
	mov	r0,_bp
	inc	r0
	mov	a,r4
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r3,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	mov	_RFD,a
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:125: for (i=0; i<len; i++)
	inc	r4
	sjmp	00106$
00101$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:131: RFST = ISTXON;
	mov	_RFST,#0xE9
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:134: while (!(RFIRQF1 & 0x02));
00102$:
	mov	a,_RFIRQF1
	jnb	acc.1,00102$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:137: RFST = ISRXON;
	mov	_RFST,#0xE3
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'receivePacket'
;------------------------------------------------------------
;len                       Allocated to stack - _bp -3
;rssi                      Allocated to stack - _bp -6
;ptr                       Allocated to stack - _bp +1
;i                         Allocated to registers r7 
;------------------------------------------------------------
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:142: char receivePacket(char* ptr, char len, signed char* rssi)
;	-----------------------------------------
;	 function receivePacket
;	-----------------------------------------
_receivePacket:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:147: RFIRQF0 = 0x00;
	mov	_RFIRQF0,#0x00
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:148: blink(RXFIFOCNT + 1);
	mov	dptr,#0x0001
	lcall	_blink
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:150: if(RXFIFOCNT != len+14)
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar3,@r0
	mov	a,@r0
	rlc	a
	subb	a,acc
	mov	r4,a
	mov	a,#0x0E
	add	a,r3
	mov	r2,a
	clr	a
	addc	a,r4
	mov	r7,a
	orl	a,r2
	jz	00120$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:152: RFST = ISFLUSHRX; RFST = ISFLUSHRX; //Flush the FIFO - 2 times necessary
	mov	_RFST,#0xED
	mov	_RFST,#0xED
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:153: return 0; //Error
	mov	dpl,#0x00
	ljmp	00117$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:156: for (i = 0; i<12; i++)
00120$:
	mov	r7,#0x0C
00113$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:158: RFD; //Skip through the first 12 bytes, not useful here
	mov	a,_RFD
	djnz	r7,00113$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:156: for (i = 0; i<12; i++)
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:162: if(RXFIFOCNT != (len + 2))
	mov	a,#0x02
	add	a,r3
	mov	r3,a
	clr	a
	addc	a,r4
	mov	r4,a
	orl	a,r3
	jz	00124$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:164: RFST = ISFLUSHRX; RFST = ISFLUSHRX; //Flush the FIFO - 2 times necessary
	mov	_RFST,#0xED
	mov	_RFST,#0xED
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:165: return 0; //Error
	mov	dpl,#0x00
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:171: for(i=0;i<len;i++)
	sjmp	00117$
00124$:
	mov	r7,#0x00
00115$:
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	clr	c
	mov	a,r7
	xrl	a,#0x80
	mov	b,@r0
	xrl	b,#0x80
	subb	a,b
	jnc	00104$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:173: ptr[i] = RFD;
	mov	r0,_bp
	inc	r0
	mov	a,r7
	add	a,@r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,_RFD
	lcall	__gptrput
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:171: for(i=0;i<len;i++)
	inc	r7
	sjmp	00115$
00104$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:177: *rssi = RFD + RSSI_OFFSET;
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	mov	r4,_RFD
	mov	a,#0xB4
	add	a,r4
	mov	r4,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:180: i = RFD;
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:181: if(!(i & 0x80)) //MSB of last byte is CRC valid bit
	mov	a,_RFD
	mov	r7,a
	jnb	acc.7,00148$
	sjmp	00106$
00148$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:182: return len; //0;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	dpl,@r0
	sjmp	00117$
00106$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:184: return len;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	dpl,@r0
00117$:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'isPacketReady'
;------------------------------------------------------------
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:190: char isPacketReady(void)
;	-----------------------------------------
;	 function isPacketReady
;	-----------------------------------------
_isPacketReady:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:193: if(RFIRQF0 & 0x40) //Bit 6 means frame accepted and loaded
	mov	a,_RFIRQF0
	jnb	acc.6,00102$
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:194: return 1;
	mov	dpl,#0x01
	ret
00102$:
;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:196: return 0;
	mov	dpl,#0x00
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
