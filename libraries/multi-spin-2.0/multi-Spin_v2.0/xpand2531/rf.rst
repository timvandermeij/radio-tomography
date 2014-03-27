                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.3.0 #8604 (Jul  8 2013) (Linux)
                              4 ; This file was generated Thu Mar 27 19:34:24 2014
                              5 ;--------------------------------------------------------
                              6 	.module rf
                              7 	.optsdcc -mmcs51 --model-large
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _blink
                             13 	.globl _U1ACTIVE
                             14 	.globl _U1TX_BYTE
                             15 	.globl _U1RX_BYTE
                             16 	.globl _U1ERR
                             17 	.globl _U1FE
                             18 	.globl _U1SLAVE
                             19 	.globl _U1RE
                             20 	.globl _U1MODE
                             21 	.globl _P2IF
                             22 	.globl _UTX0IF
                             23 	.globl _UTX1IF
                             24 	.globl _P1IF
                             25 	.globl _WDTIF
                             26 	.globl __IRCON25
                             27 	.globl __IRCON26
                             28 	.globl __IRCON27
                             29 	.globl _T3OVFIF
                             30 	.globl _T3CH0IF
                             31 	.globl _T3CH1IF
                             32 	.globl _T4OVFIF
                             33 	.globl _T4CH0IF
                             34 	.globl _T4CH1IF
                             35 	.globl _T1OVFIM
                             36 	.globl __TIMIF7
                             37 	.globl _P
                             38 	.globl _F1
                             39 	.globl _OV
                             40 	.globl _RS0
                             41 	.globl _RS1
                             42 	.globl _F0
                             43 	.globl _AC
                             44 	.globl _CY
                             45 	.globl _DMAIF
                             46 	.globl _T1IF
                             47 	.globl _T2IF
                             48 	.globl _T3IF
                             49 	.globl _T4IF
                             50 	.globl _P0IF
                             51 	.globl __IRCON6
                             52 	.globl _STIF
                             53 	.globl _DMAIE
                             54 	.globl _T1IE
                             55 	.globl _T2IE
                             56 	.globl _T3IE
                             57 	.globl _T4IE
                             58 	.globl _P0IE
                             59 	.globl __IEN16
                             60 	.globl __IEN17
                             61 	.globl _RFERRIE
                             62 	.globl _ADCIE
                             63 	.globl _URX0IE
                             64 	.globl _URX1IE
                             65 	.globl _ENCIE
                             66 	.globl _STIE
                             67 	.globl __IEN06
                             68 	.globl _EA
                             69 	.globl _P2_0
                             70 	.globl _P2_1
                             71 	.globl _P2_2
                             72 	.globl _P2_3
                             73 	.globl _P2_4
                             74 	.globl __P2_5
                             75 	.globl __P2_6
                             76 	.globl __P2_7
                             77 	.globl _ENCIF_0
                             78 	.globl _ENCIF_1
                             79 	.globl __S0CON2
                             80 	.globl __S0CON3
                             81 	.globl __S0CON4
                             82 	.globl __S0CON5
                             83 	.globl __S0CON6
                             84 	.globl __S0CON7
                             85 	.globl _P1_0
                             86 	.globl _P1_1
                             87 	.globl _P1_2
                             88 	.globl _P1_3
                             89 	.globl _P1_4
                             90 	.globl _P1_5
                             91 	.globl _P1_6
                             92 	.globl _P1_7
                             93 	.globl _IT0
                             94 	.globl _RFERRIF
                             95 	.globl _IT1
                             96 	.globl _URX0IF
                             97 	.globl __TCON4
                             98 	.globl _ADCIF
                             99 	.globl __TCON6
                            100 	.globl _URX1IF
                            101 	.globl _P0_0
                            102 	.globl _P0_1
                            103 	.globl _P0_2
                            104 	.globl _P0_3
                            105 	.globl _P0_4
                            106 	.globl _P0_5
                            107 	.globl _P0_6
                            108 	.globl _P0_7
                            109 	.globl _P2DIR
                            110 	.globl _P1DIR
                            111 	.globl _P0DIR
                            112 	.globl _U1GCR
                            113 	.globl _U1UCR
                            114 	.globl _U1BAUD
                            115 	.globl _U1DBUF
                            116 	.globl _U1CSR
                            117 	.globl _P2INP
                            118 	.globl _P1INP
                            119 	.globl _P2SEL
                            120 	.globl _P1SEL
                            121 	.globl _P0SEL
                            122 	.globl _APCFG
                            123 	.globl _ADCCFG
                            124 	.globl _PERCFG
                            125 	.globl _B
                            126 	.globl _T4CC1
                            127 	.globl _T4CCTL1
                            128 	.globl _T4CC0
                            129 	.globl _T4CCTL0
                            130 	.globl _T4CTL
                            131 	.globl _T4CNT
                            132 	.globl _RFIRQF0
                            133 	.globl _IRCON2
                            134 	.globl _T1CCTL2
                            135 	.globl _T1CCTL1
                            136 	.globl _T1CCTL0
                            137 	.globl _T1CTL
                            138 	.globl _T1CNTH
                            139 	.globl _T1CNTL
                            140 	.globl _RFST
                            141 	.globl _ACC
                            142 	.globl _T1CC2H
                            143 	.globl _T1CC2L
                            144 	.globl _T1CC1H
                            145 	.globl _T1CC1L
                            146 	.globl _T1CC0H
                            147 	.globl _T1CC0L
                            148 	.globl _RFD
                            149 	.globl _TIMIF
                            150 	.globl _DMAREQ
                            151 	.globl _DMAARM
                            152 	.globl _DMA0CFGH
                            153 	.globl _DMA0CFGL
                            154 	.globl _DMA1CFGH
                            155 	.globl _DMA1CFGL
                            156 	.globl _DMAIRQ
                            157 	.globl _PSW
                            158 	.globl _T3CC1
                            159 	.globl _T3CCTL1
                            160 	.globl _T3CC0
                            161 	.globl _T3CCTL0
                            162 	.globl _T3CTL
                            163 	.globl _T3CNT
                            164 	.globl _WDCTL
                            165 	.globl __SFRC8
                            166 	.globl _MEMCTR
                            167 	.globl _CLKCONCMD
                            168 	.globl _U0GCR
                            169 	.globl _U0UCR
                            170 	.globl _T2MSEL
                            171 	.globl _U0BAUD
                            172 	.globl _U0DBUF
                            173 	.globl _IRCON
                            174 	.globl _RFERRF
                            175 	.globl _SLEEPCMD
                            176 	.globl _RNDH
                            177 	.globl _RNDL
                            178 	.globl _ADCH
                            179 	.globl _ADCL
                            180 	.globl _IP1
                            181 	.globl _IEN1
                            182 	.globl __SFRB7
                            183 	.globl _ADCCON3
                            184 	.globl _ADCCON2
                            185 	.globl _ADCCON1
                            186 	.globl _ENCCS
                            187 	.globl _ENCDO
                            188 	.globl _ENCDI
                            189 	.globl __SFRB0
                            190 	.globl _T1STAT
                            191 	.globl _PMUX
                            192 	.globl _STLOAD
                            193 	.globl _P2IEN
                            194 	.globl _P0IEN
                            195 	.globl __SFRAA
                            196 	.globl _IP0
                            197 	.globl _IEN0
                            198 	.globl _T2IRQM
                            199 	.globl _T2MOVF2
                            200 	.globl _T2MOVF1
                            201 	.globl _T2MOVF0
                            202 	.globl _T2M1
                            203 	.globl _T2M0
                            204 	.globl _T2IRQF
                            205 	.globl _P2
                            206 	.globl _FMAP
                            207 	.globl _CLKCONSTA
                            208 	.globl _SLEEPSTA
                            209 	.globl _T2EVTCFG
                            210 	.globl _T2CSPCFG
                            211 	.globl _S1CON
                            212 	.globl _IEN2
                            213 	.globl __SFR99
                            214 	.globl _S0CON
                            215 	.globl _ST2
                            216 	.globl _ST1
                            217 	.globl _ST0
                            218 	.globl _T2CTRL
                            219 	.globl _MPAGE
                            220 	.globl _DPS
                            221 	.globl _RFIRQF1
                            222 	.globl _P1
                            223 	.globl _P0INP
                            224 	.globl __SFR8E
                            225 	.globl _P1IEN
                            226 	.globl _PICTL
                            227 	.globl _P2IFG
                            228 	.globl _P1IFG
                            229 	.globl _P0IFG
                            230 	.globl _TCON
                            231 	.globl _PCON
                            232 	.globl _U0CSR
                            233 	.globl _DPH1
                            234 	.globl _DPL1
                            235 	.globl _DPH0
                            236 	.globl _DPL0
                            237 	.globl _SP
                            238 	.globl _P0
                            239 	.globl _radioInit
                            240 	.globl _sendPacket
                            241 	.globl _receivePacket
                            242 	.globl _isPacketReady
                            243 ;--------------------------------------------------------
                            244 ; special function registers
                            245 ;--------------------------------------------------------
                            246 	.area RSEG    (ABS,DATA)
   0000                     247 	.org 0x0000
                     0080   248 _P0	=	0x0080
                     0081   249 _SP	=	0x0081
                     0082   250 _DPL0	=	0x0082
                     0083   251 _DPH0	=	0x0083
                     0084   252 _DPL1	=	0x0084
                     0085   253 _DPH1	=	0x0085
                     0086   254 _U0CSR	=	0x0086
                     0087   255 _PCON	=	0x0087
                     0088   256 _TCON	=	0x0088
                     0089   257 _P0IFG	=	0x0089
                     008A   258 _P1IFG	=	0x008a
                     008B   259 _P2IFG	=	0x008b
                     008C   260 _PICTL	=	0x008c
                     008D   261 _P1IEN	=	0x008d
                     008E   262 __SFR8E	=	0x008e
                     008F   263 _P0INP	=	0x008f
                     0090   264 _P1	=	0x0090
                     0091   265 _RFIRQF1	=	0x0091
                     0092   266 _DPS	=	0x0092
                     0093   267 _MPAGE	=	0x0093
                     0094   268 _T2CTRL	=	0x0094
                     0095   269 _ST0	=	0x0095
                     0096   270 _ST1	=	0x0096
                     0097   271 _ST2	=	0x0097
                     0098   272 _S0CON	=	0x0098
                     0099   273 __SFR99	=	0x0099
                     009A   274 _IEN2	=	0x009a
                     009B   275 _S1CON	=	0x009b
                     009C   276 _T2CSPCFG	=	0x009c
                     009C   277 _T2EVTCFG	=	0x009c
                     009D   278 _SLEEPSTA	=	0x009d
                     009E   279 _CLKCONSTA	=	0x009e
                     009F   280 _FMAP	=	0x009f
                     00A0   281 _P2	=	0x00a0
                     00A1   282 _T2IRQF	=	0x00a1
                     00A2   283 _T2M0	=	0x00a2
                     00A3   284 _T2M1	=	0x00a3
                     00A4   285 _T2MOVF0	=	0x00a4
                     00A5   286 _T2MOVF1	=	0x00a5
                     00A6   287 _T2MOVF2	=	0x00a6
                     00A7   288 _T2IRQM	=	0x00a7
                     00A8   289 _IEN0	=	0x00a8
                     00A9   290 _IP0	=	0x00a9
                     00AA   291 __SFRAA	=	0x00aa
                     00AB   292 _P0IEN	=	0x00ab
                     00AC   293 _P2IEN	=	0x00ac
                     00AD   294 _STLOAD	=	0x00ad
                     00AE   295 _PMUX	=	0x00ae
                     00AF   296 _T1STAT	=	0x00af
                     00B0   297 __SFRB0	=	0x00b0
                     00B1   298 _ENCDI	=	0x00b1
                     00B2   299 _ENCDO	=	0x00b2
                     00B3   300 _ENCCS	=	0x00b3
                     00B4   301 _ADCCON1	=	0x00b4
                     00B5   302 _ADCCON2	=	0x00b5
                     00B6   303 _ADCCON3	=	0x00b6
                     00B7   304 __SFRB7	=	0x00b7
                     00B8   305 _IEN1	=	0x00b8
                     00B9   306 _IP1	=	0x00b9
                     00BA   307 _ADCL	=	0x00ba
                     00BB   308 _ADCH	=	0x00bb
                     00BC   309 _RNDL	=	0x00bc
                     00BD   310 _RNDH	=	0x00bd
                     00BE   311 _SLEEPCMD	=	0x00be
                     00BF   312 _RFERRF	=	0x00bf
                     00C0   313 _IRCON	=	0x00c0
                     00C1   314 _U0DBUF	=	0x00c1
                     00C2   315 _U0BAUD	=	0x00c2
                     00C3   316 _T2MSEL	=	0x00c3
                     00C4   317 _U0UCR	=	0x00c4
                     00C5   318 _U0GCR	=	0x00c5
                     00C6   319 _CLKCONCMD	=	0x00c6
                     00C7   320 _MEMCTR	=	0x00c7
                     00C8   321 __SFRC8	=	0x00c8
                     00C9   322 _WDCTL	=	0x00c9
                     00CA   323 _T3CNT	=	0x00ca
                     00CB   324 _T3CTL	=	0x00cb
                     00CC   325 _T3CCTL0	=	0x00cc
                     00CD   326 _T3CC0	=	0x00cd
                     00CE   327 _T3CCTL1	=	0x00ce
                     00CF   328 _T3CC1	=	0x00cf
                     00D0   329 _PSW	=	0x00d0
                     00D1   330 _DMAIRQ	=	0x00d1
                     00D2   331 _DMA1CFGL	=	0x00d2
                     00D3   332 _DMA1CFGH	=	0x00d3
                     00D4   333 _DMA0CFGL	=	0x00d4
                     00D5   334 _DMA0CFGH	=	0x00d5
                     00D6   335 _DMAARM	=	0x00d6
                     00D7   336 _DMAREQ	=	0x00d7
                     00D8   337 _TIMIF	=	0x00d8
                     00D9   338 _RFD	=	0x00d9
                     00DA   339 _T1CC0L	=	0x00da
                     00DB   340 _T1CC0H	=	0x00db
                     00DC   341 _T1CC1L	=	0x00dc
                     00DD   342 _T1CC1H	=	0x00dd
                     00DE   343 _T1CC2L	=	0x00de
                     00DF   344 _T1CC2H	=	0x00df
                     00E0   345 _ACC	=	0x00e0
                     00E1   346 _RFST	=	0x00e1
                     00E2   347 _T1CNTL	=	0x00e2
                     00E3   348 _T1CNTH	=	0x00e3
                     00E4   349 _T1CTL	=	0x00e4
                     00E5   350 _T1CCTL0	=	0x00e5
                     00E6   351 _T1CCTL1	=	0x00e6
                     00E7   352 _T1CCTL2	=	0x00e7
                     00E8   353 _IRCON2	=	0x00e8
                     00E9   354 _RFIRQF0	=	0x00e9
                     00EA   355 _T4CNT	=	0x00ea
                     00EB   356 _T4CTL	=	0x00eb
                     00EC   357 _T4CCTL0	=	0x00ec
                     00ED   358 _T4CC0	=	0x00ed
                     00EE   359 _T4CCTL1	=	0x00ee
                     00EF   360 _T4CC1	=	0x00ef
                     00F0   361 _B	=	0x00f0
                     00F1   362 _PERCFG	=	0x00f1
                     00F2   363 _ADCCFG	=	0x00f2
                     00F2   364 _APCFG	=	0x00f2
                     00F3   365 _P0SEL	=	0x00f3
                     00F4   366 _P1SEL	=	0x00f4
                     00F5   367 _P2SEL	=	0x00f5
                     00F6   368 _P1INP	=	0x00f6
                     00F7   369 _P2INP	=	0x00f7
                     00F8   370 _U1CSR	=	0x00f8
                     00F9   371 _U1DBUF	=	0x00f9
                     00FA   372 _U1BAUD	=	0x00fa
                     00FB   373 _U1UCR	=	0x00fb
                     00FC   374 _U1GCR	=	0x00fc
                     00FD   375 _P0DIR	=	0x00fd
                     00FE   376 _P1DIR	=	0x00fe
                     00FF   377 _P2DIR	=	0x00ff
                            378 ;--------------------------------------------------------
                            379 ; special function bits
                            380 ;--------------------------------------------------------
                            381 	.area RSEG    (ABS,DATA)
   0000                     382 	.org 0x0000
                     0087   383 _P0_7	=	0x0087
                     0086   384 _P0_6	=	0x0086
                     0085   385 _P0_5	=	0x0085
                     0084   386 _P0_4	=	0x0084
                     0083   387 _P0_3	=	0x0083
                     0082   388 _P0_2	=	0x0082
                     0081   389 _P0_1	=	0x0081
                     0080   390 _P0_0	=	0x0080
                     008F   391 _URX1IF	=	0x008f
                     008E   392 __TCON6	=	0x008e
                     008D   393 _ADCIF	=	0x008d
                     008C   394 __TCON4	=	0x008c
                     008B   395 _URX0IF	=	0x008b
                     008A   396 _IT1	=	0x008a
                     0089   397 _RFERRIF	=	0x0089
                     0088   398 _IT0	=	0x0088
                     0097   399 _P1_7	=	0x0097
                     0096   400 _P1_6	=	0x0096
                     0095   401 _P1_5	=	0x0095
                     0094   402 _P1_4	=	0x0094
                     0093   403 _P1_3	=	0x0093
                     0092   404 _P1_2	=	0x0092
                     0091   405 _P1_1	=	0x0091
                     0090   406 _P1_0	=	0x0090
                     009F   407 __S0CON7	=	0x009f
                     009E   408 __S0CON6	=	0x009e
                     009D   409 __S0CON5	=	0x009d
                     009C   410 __S0CON4	=	0x009c
                     009B   411 __S0CON3	=	0x009b
                     009A   412 __S0CON2	=	0x009a
                     0099   413 _ENCIF_1	=	0x0099
                     0098   414 _ENCIF_0	=	0x0098
                     00A7   415 __P2_7	=	0x00a7
                     00A6   416 __P2_6	=	0x00a6
                     00A5   417 __P2_5	=	0x00a5
                     00A4   418 _P2_4	=	0x00a4
                     00A3   419 _P2_3	=	0x00a3
                     00A2   420 _P2_2	=	0x00a2
                     00A1   421 _P2_1	=	0x00a1
                     00A0   422 _P2_0	=	0x00a0
                     00AF   423 _EA	=	0x00af
                     00AE   424 __IEN06	=	0x00ae
                     00AD   425 _STIE	=	0x00ad
                     00AC   426 _ENCIE	=	0x00ac
                     00AB   427 _URX1IE	=	0x00ab
                     00AA   428 _URX0IE	=	0x00aa
                     00A9   429 _ADCIE	=	0x00a9
                     00A8   430 _RFERRIE	=	0x00a8
                     00BF   431 __IEN17	=	0x00bf
                     00BE   432 __IEN16	=	0x00be
                     00BD   433 _P0IE	=	0x00bd
                     00BC   434 _T4IE	=	0x00bc
                     00BB   435 _T3IE	=	0x00bb
                     00BA   436 _T2IE	=	0x00ba
                     00B9   437 _T1IE	=	0x00b9
                     00B8   438 _DMAIE	=	0x00b8
                     00C7   439 _STIF	=	0x00c7
                     00C6   440 __IRCON6	=	0x00c6
                     00C5   441 _P0IF	=	0x00c5
                     00C4   442 _T4IF	=	0x00c4
                     00C3   443 _T3IF	=	0x00c3
                     00C2   444 _T2IF	=	0x00c2
                     00C1   445 _T1IF	=	0x00c1
                     00C0   446 _DMAIF	=	0x00c0
                     00D7   447 _CY	=	0x00d7
                     00D6   448 _AC	=	0x00d6
                     00D5   449 _F0	=	0x00d5
                     00D4   450 _RS1	=	0x00d4
                     00D3   451 _RS0	=	0x00d3
                     00D2   452 _OV	=	0x00d2
                     00D1   453 _F1	=	0x00d1
                     00D0   454 _P	=	0x00d0
                     00DF   455 __TIMIF7	=	0x00df
                     00DE   456 _T1OVFIM	=	0x00de
                     00DD   457 _T4CH1IF	=	0x00dd
                     00DC   458 _T4CH0IF	=	0x00dc
                     00DB   459 _T4OVFIF	=	0x00db
                     00DA   460 _T3CH1IF	=	0x00da
                     00D9   461 _T3CH0IF	=	0x00d9
                     00D8   462 _T3OVFIF	=	0x00d8
                     00EF   463 __IRCON27	=	0x00ef
                     00EE   464 __IRCON26	=	0x00ee
                     00ED   465 __IRCON25	=	0x00ed
                     00EC   466 _WDTIF	=	0x00ec
                     00EB   467 _P1IF	=	0x00eb
                     00EA   468 _UTX1IF	=	0x00ea
                     00E9   469 _UTX0IF	=	0x00e9
                     00E8   470 _P2IF	=	0x00e8
                     00FF   471 _U1MODE	=	0x00ff
                     00FE   472 _U1RE	=	0x00fe
                     00FD   473 _U1SLAVE	=	0x00fd
                     00FC   474 _U1FE	=	0x00fc
                     00FB   475 _U1ERR	=	0x00fb
                     00FA   476 _U1RX_BYTE	=	0x00fa
                     00F9   477 _U1TX_BYTE	=	0x00f9
                     00F8   478 _U1ACTIVE	=	0x00f8
                            479 ;--------------------------------------------------------
                            480 ; overlayable register banks
                            481 ;--------------------------------------------------------
                            482 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     483 	.ds 8
                            484 ;--------------------------------------------------------
                            485 ; internal ram data
                            486 ;--------------------------------------------------------
                            487 	.area DSEG    (DATA)
                            488 ;--------------------------------------------------------
                            489 ; overlayable items in internal ram 
                            490 ;--------------------------------------------------------
                            491 ;--------------------------------------------------------
                            492 ; indirectly addressable internal ram data
                            493 ;--------------------------------------------------------
                            494 	.area ISEG    (DATA)
                            495 ;--------------------------------------------------------
                            496 ; absolute internal ram data
                            497 ;--------------------------------------------------------
                            498 	.area IABS    (ABS,DATA)
                            499 	.area IABS    (ABS,DATA)
                            500 ;--------------------------------------------------------
                            501 ; bit data
                            502 ;--------------------------------------------------------
                            503 	.area BSEG    (BIT)
                            504 ;--------------------------------------------------------
                            505 ; paged external ram data
                            506 ;--------------------------------------------------------
                            507 	.area PSEG    (PAG,XDATA)
                            508 ;--------------------------------------------------------
                            509 ; external ram data
                            510 ;--------------------------------------------------------
                            511 	.area XSEG    (XDATA)
   0025                     512 _sendPacket_seq_1_12:
   0025                     513 	.ds 1
                            514 ;--------------------------------------------------------
                            515 ; absolute external ram data
                            516 ;--------------------------------------------------------
                            517 	.area XABS    (ABS,XDATA)
                            518 ;--------------------------------------------------------
                            519 ; external initialized ram data
                            520 ;--------------------------------------------------------
                            521 	.area XISEG   (XDATA)
                            522 	.area HOME    (CODE)
                            523 	.area GSINIT0 (CODE)
                            524 	.area GSINIT1 (CODE)
                            525 	.area GSINIT2 (CODE)
                            526 	.area GSINIT3 (CODE)
                            527 	.area GSINIT4 (CODE)
                            528 	.area GSINIT5 (CODE)
                            529 	.area GSINIT  (CODE)
                            530 	.area GSFINAL (CODE)
                            531 	.area CSEG    (CODE)
                            532 ;--------------------------------------------------------
                            533 ; global & static initialisations
                            534 ;--------------------------------------------------------
                            535 	.area HOME    (CODE)
                            536 	.area GSINIT  (CODE)
                            537 	.area GSFINAL (CODE)
                            538 	.area GSINIT  (CODE)
                            539 ;--------------------------------------------------------
                            540 ; Home
                            541 ;--------------------------------------------------------
                            542 	.area HOME    (CODE)
                            543 	.area HOME    (CODE)
                            544 ;--------------------------------------------------------
                            545 ; code
                            546 ;--------------------------------------------------------
                            547 	.area CSEG    (CODE)
                            548 ;------------------------------------------------------------
                            549 ;Allocation info for local variables in function 'radioInit'
                            550 ;------------------------------------------------------------
                            551 ;rfConfig                  Allocated to registers r5 r6 r7 
                            552 ;------------------------------------------------------------
                            553 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:25: void radioInit(rfConfig_t *rfConfig)
                            554 ;	-----------------------------------------
                            555 ;	 function radioInit
                            556 ;	-----------------------------------------
   0657                     557 _radioInit:
                     0007   558 	ar7 = 0x07
                     0006   559 	ar6 = 0x06
                     0005   560 	ar5 = 0x05
                     0004   561 	ar4 = 0x04
                     0003   562 	ar3 = 0x03
                     0002   563 	ar2 = 0x02
                     0001   564 	ar1 = 0x01
                     0000   565 	ar0 = 0x00
   0657 AD 82         [24]  566 	mov	r5,dpl
   0659 AE 83         [24]  567 	mov	r6,dph
   065B AF F0         [24]  568 	mov	r7,b
                            569 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:33: MDMCTRL1 = CORR_THR;
   065D 90 61 A9      [24]  570 	mov	dptr,#0x61A9
   0660 74 14         [12]  571 	mov	a,#0x14
   0662 F0            [24]  572 	movx	@dptr,a
                            573 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:36: RXCTRL = 0x3F;
   0663 90 61 AB      [24]  574 	mov	dptr,#0x61AB
   0666 74 3F         [12]  575 	mov	a,#0x3F
   0668 F0            [24]  576 	movx	@dptr,a
                            577 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:45: MDMCTRL0 = 0x85;
   0669 90 61 A8      [24]  578 	mov	dptr,#0x61A8
   066C 74 85         [12]  579 	mov	a,#0x85
   066E F0            [24]  580 	movx	@dptr,a
                            581 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:48: FSCTRL = 0x5A;
   066F 90 61 AC      [24]  582 	mov	dptr,#0x61AC
   0672 74 5A         [12]  583 	mov	a,#0x5A
   0674 F0            [24]  584 	movx	@dptr,a
                            585 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:51: AGCCTRL1 = 0x15;
   0675 90 61 B2      [24]  586 	mov	dptr,#0x61B2
   0678 74 15         [12]  587 	mov	a,#0x15
   067A F0            [24]  588 	movx	@dptr,a
                            589 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:54: SRCMATCH = 0x00;
   067B 90 61 82      [24]  590 	mov	dptr,#0x6182
   067E E4            [12]  591 	clr	a
   067F F0            [24]  592 	movx	@dptr,a
                            593 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:57: ADCTEST0 = 0x10;
   0680 90 61 B5      [24]  594 	mov	dptr,#0x61B5
   0683 74 10         [12]  595 	mov	a,#0x10
   0685 F0            [24]  596 	movx	@dptr,a
                            597 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:58: ADCTEST1 = 0x0E;
   0686 90 61 B6      [24]  598 	mov	dptr,#0x61B6
   0689 74 0E         [12]  599 	mov	a,#0x0E
   068B F0            [24]  600 	movx	@dptr,a
                            601 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:59: ADCTEST2 = 0x03;
   068C 90 61 B7      [24]  602 	mov	dptr,#0x61B7
   068F 74 03         [12]  603 	mov	a,#0x03
   0691 F0            [24]  604 	movx	@dptr,a
                            605 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:64: TXFILTCFG = TXFILTCFG_RESET_VALUE;
   0692 90 61 FA      [24]  606 	mov	dptr,#0x61FA
   0695 74 09         [12]  607 	mov	a,#0x09
   0697 F0            [24]  608 	movx	@dptr,a
                            609 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:66: CSPT = 0xFF; //disable the CSPT register compare function
   0698 90 61 E5      [24]  610 	mov	dptr,#0x61E5
   069B 74 FF         [12]  611 	mov	a,#0xFF
   069D F0            [24]  612 	movx	@dptr,a
                            613 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:67: TXPOWER = rfConfig->txPower; //Transmitter Power
   069E 74 05         [12]  614 	mov	a,#0x05
   06A0 2D            [12]  615 	add	a,r5
   06A1 FA            [12]  616 	mov	r2,a
   06A2 E4            [12]  617 	clr	a
   06A3 3E            [12]  618 	addc	a,r6
   06A4 FB            [12]  619 	mov	r3,a
   06A5 8F 04         [24]  620 	mov	ar4,r7
   06A7 8A 82         [24]  621 	mov	dpl,r2
   06A9 8B 83         [24]  622 	mov	dph,r3
   06AB 8C F0         [24]  623 	mov	b,r4
   06AD 12 0A AC      [24]  624 	lcall	__gptrget
   06B0 90 61 90      [24]  625 	mov	dptr,#0x6190
   06B3 F0            [24]  626 	movx	@dptr,a
                            627 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:68: FREQCTRL = 11+5*(rfConfig->channel-11); //Frequency setup: f=(2394 + FREQCNTL) MHz
   06B4 74 04         [12]  628 	mov	a,#0x04
   06B6 2D            [12]  629 	add	a,r5
   06B7 FA            [12]  630 	mov	r2,a
   06B8 E4            [12]  631 	clr	a
   06B9 3E            [12]  632 	addc	a,r6
   06BA FB            [12]  633 	mov	r3,a
   06BB 8F 04         [24]  634 	mov	ar4,r7
   06BD 8A 82         [24]  635 	mov	dpl,r2
   06BF 8B 83         [24]  636 	mov	dph,r3
   06C1 8C F0         [24]  637 	mov	b,r4
   06C3 12 0A AC      [24]  638 	lcall	__gptrget
   06C6 24 F5         [12]  639 	add	a,#0xF5
   06C8 75 F0 05      [24]  640 	mov	b,#0x05
   06CB A4            [48]  641 	mul	ab
   06CC 24 0B         [12]  642 	add	a,#0x0B
   06CE 90 61 8F      [24]  643 	mov	dptr,#0x618F
   06D1 F0            [24]  644 	movx	@dptr,a
                            645 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:70: FRMCTRL0 |= 0x40; //Turn on auto CRC
   06D2 90 61 89      [24]  646 	mov	dptr,#0x6189
   06D5 74 40         [12]  647 	mov	a,#0x40
   06D7 F0            [24]  648 	movx	@dptr,a
                            649 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:73: SHORT_ADDRL = (char)rfConfig->addr;
   06D8 74 02         [12]  650 	mov	a,#0x02
   06DA 2D            [12]  651 	add	a,r5
   06DB FA            [12]  652 	mov	r2,a
   06DC E4            [12]  653 	clr	a
   06DD 3E            [12]  654 	addc	a,r6
   06DE FB            [12]  655 	mov	r3,a
   06DF 8F 04         [24]  656 	mov	ar4,r7
   06E1 8A 82         [24]  657 	mov	dpl,r2
   06E3 8B 83         [24]  658 	mov	dph,r3
   06E5 8C F0         [24]  659 	mov	b,r4
   06E7 12 0A AC      [24]  660 	lcall	__gptrget
   06EA F8            [12]  661 	mov	r0,a
   06EB A3            [24]  662 	inc	dptr
   06EC 12 0A AC      [24]  663 	lcall	__gptrget
   06EF 90 61 74      [24]  664 	mov	dptr,#0x6174
   06F2 E8            [12]  665 	mov	a,r0
   06F3 F0            [24]  666 	movx	@dptr,a
                            667 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:74: SHORT_ADDRH = (char)(rfConfig->addr>>8);
   06F4 8A 82         [24]  668 	mov	dpl,r2
   06F6 8B 83         [24]  669 	mov	dph,r3
   06F8 8C F0         [24]  670 	mov	b,r4
   06FA 12 0A AC      [24]  671 	lcall	__gptrget
   06FD A3            [24]  672 	inc	dptr
   06FE 12 0A AC      [24]  673 	lcall	__gptrget
   0701 FA            [12]  674 	mov	r2,a
   0702 90 61 75      [24]  675 	mov	dptr,#0x6175
   0705 EA            [12]  676 	mov	a,r2
   0706 F0            [24]  677 	movx	@dptr,a
                            678 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:75: PANL = (char)rfConfig->pan;
   0707 8D 82         [24]  679 	mov	dpl,r5
   0709 8E 83         [24]  680 	mov	dph,r6
   070B 8F F0         [24]  681 	mov	b,r7
   070D 12 0A AC      [24]  682 	lcall	__gptrget
   0710 FB            [12]  683 	mov	r3,a
   0711 A3            [24]  684 	inc	dptr
   0712 12 0A AC      [24]  685 	lcall	__gptrget
   0715 90 61 72      [24]  686 	mov	dptr,#0x6172
   0718 EB            [12]  687 	mov	a,r3
   0719 F0            [24]  688 	movx	@dptr,a
                            689 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:76: PANH = (char)(rfConfig->pan>>8);
   071A 8D 82         [24]  690 	mov	dpl,r5
   071C 8E 83         [24]  691 	mov	dph,r6
   071E 8F F0         [24]  692 	mov	b,r7
   0720 12 0A AC      [24]  693 	lcall	__gptrget
   0723 A3            [24]  694 	inc	dptr
   0724 12 0A AC      [24]  695 	lcall	__gptrget
   0727 FD            [12]  696 	mov	r5,a
   0728 90 61 73      [24]  697 	mov	dptr,#0x6173
   072B ED            [12]  698 	mov	a,r5
   072C F0            [24]  699 	movx	@dptr,a
                            700 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:79: FRMFILT0 = 0x0D; //Enable frame filt, max_fcf_version set to 11
   072D 90 61 80      [24]  701 	mov	dptr,#0x6180
   0730 74 0D         [12]  702 	mov	a,#0x0D
   0732 F0            [24]  703 	movx	@dptr,a
                            704 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:80: FRMFILT1 = 0x10; //Only allow for data packets (no beacons, no ack, etc)
   0733 90 61 81      [24]  705 	mov	dptr,#0x6181
   0736 74 10         [12]  706 	mov	a,#0x10
   0738 F0            [24]  707 	movx	@dptr,a
                            708 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:83: RFST = ISRXON;
   0739 75 E1 E3      [24]  709 	mov	_RFST,#0xE3
   073C 22            [24]  710 	ret
                            711 ;------------------------------------------------------------
                            712 ;Allocation info for local variables in function 'sendPacket'
                            713 ;------------------------------------------------------------
                            714 ;len                       Allocated to stack - _bp -4
                            715 ;pan                       Allocated to stack - _bp -6
                            716 ;dest                      Allocated to stack - _bp -8
                            717 ;src                       Allocated to stack - _bp -10
                            718 ;ptr                       Allocated to stack - _bp +1
                            719 ;i                         Allocated to registers r4 
                            720 ;seq                       Allocated with name '_sendPacket_seq_1_12'
                            721 ;------------------------------------------------------------
                            722 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:87: void sendPacket(char* ptr, short len, short pan, short dest, short src)
                            723 ;	-----------------------------------------
                            724 ;	 function sendPacket
                            725 ;	-----------------------------------------
   073D                     726 _sendPacket:
   073D C0 08         [24]  727 	push	_bp
   073F 85 81 08      [24]  728 	mov	_bp,sp
   0742 C0 82         [24]  729 	push	dpl
   0744 C0 83         [24]  730 	push	dph
   0746 C0 F0         [24]  731 	push	b
                            732 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:91: seq++;  //This auto increments every function call due to "static" declaration
   0748 90 00 25      [24]  733 	mov	dptr,#_sendPacket_seq_1_12
   074B E0            [24]  734 	movx	a,@dptr
   074C 24 01         [12]  735 	add	a,#0x01
   074E F0            [24]  736 	movx	@dptr,a
                            737 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:95: RFIRQF1 &= ~0x02; 
   074F AC 91         [24]  738 	mov	r4,_RFIRQF1
   0751 74 FD         [12]  739 	mov	a,#0xFD
   0753 5C            [12]  740 	anl	a,r4
   0754 F5 91         [12]  741 	mov	_RFIRQF1,a
                            742 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:98: RFST = ISRFOFF;
   0756 75 E1 EF      [24]  743 	mov	_RFST,#0xEF
                            744 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:101: RFST = ISFLUSHTX; RFST = ISFLUSHTX; 
   0759 75 E1 EE      [24]  745 	mov	_RFST,#0xEE
   075C 75 E1 EE      [24]  746 	mov	_RFST,#0xEE
                            747 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:105: RFD = 2+2+1+8+len;
   075F E5 08         [12]  748 	mov	a,_bp
   0761 24 FC         [12]  749 	add	a,#0xfc
   0763 F8            [12]  750 	mov	r0,a
   0764 86 04         [24]  751 	mov	ar4,@r0
   0766 74 0D         [12]  752 	mov	a,#0x0D
   0768 2C            [12]  753 	add	a,r4
   0769 F5 D9         [12]  754 	mov	_RFD,a
                            755 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:108: RFD = 0x01; //FCF1 - No security, compression, ack
   076B 75 D9 01      [24]  756 	mov	_RFD,#0x01
                            757 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:109: RFD = 0x88; //Use short addr and IEEE 802.15.4 2003 matching
   076E 75 D9 88      [24]  758 	mov	_RFD,#0x88
                            759 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:110: RFD = seq;
   0771 90 00 25      [24]  760 	mov	dptr,#_sendPacket_seq_1_12
   0774 E0            [24]  761 	movx	a,@dptr
   0775 F5 D9         [12]  762 	mov	_RFD,a
                            763 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:113: RFD = (char)pan; //LSB byte of pan
   0777 E5 08         [12]  764 	mov	a,_bp
   0779 24 FA         [12]  765 	add	a,#0xfa
   077B F8            [12]  766 	mov	r0,a
   077C 86 04         [24]  767 	mov	ar4,@r0
   077E 8C D9         [24]  768 	mov	_RFD,r4
                            769 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:114: RFD = (char)(pan >> 8); //MSB byte of pan 
   0780 E5 08         [12]  770 	mov	a,_bp
   0782 24 FA         [12]  771 	add	a,#0xfa
   0784 F8            [12]  772 	mov	r0,a
   0785 08            [12]  773 	inc	r0
   0786 86 03         [24]  774 	mov	ar3,@r0
   0788 8B D9         [24]  775 	mov	_RFD,r3
                            776 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:115: RFD = (char)dest; //LSB byte of pan
   078A E5 08         [12]  777 	mov	a,_bp
   078C 24 F8         [12]  778 	add	a,#0xf8
   078E F8            [12]  779 	mov	r0,a
   078F 86 D9         [24]  780 	mov	_RFD,@r0
                            781 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:116: RFD = (char)(dest >> 8); //MSB byte of pan
   0791 E5 08         [12]  782 	mov	a,_bp
   0793 24 F8         [12]  783 	add	a,#0xf8
   0795 F8            [12]  784 	mov	r0,a
   0796 08            [12]  785 	inc	r0
   0797 86 D9         [24]  786 	mov	_RFD,@r0
                            787 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:119: RFD = (char)pan; //LSB byte of pan
   0799 8C D9         [24]  788 	mov	_RFD,r4
                            789 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:120: RFD = (char)(pan >> 8); //MSB byte of pan
   079B 8B D9         [24]  790 	mov	_RFD,r3
                            791 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:121: RFD = (char)src; //LSB byte of pan
   079D E5 08         [12]  792 	mov	a,_bp
   079F 24 F6         [12]  793 	add	a,#0xf6
   07A1 F8            [12]  794 	mov	r0,a
   07A2 86 D9         [24]  795 	mov	_RFD,@r0
                            796 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:122: RFD = (char)(src >> 8); //MSB byte of pan
   07A4 E5 08         [12]  797 	mov	a,_bp
   07A6 24 F6         [12]  798 	add	a,#0xf6
   07A8 F8            [12]  799 	mov	r0,a
   07A9 08            [12]  800 	inc	r0
   07AA 86 D9         [24]  801 	mov	_RFD,@r0
                            802 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:125: for (i=0; i<len; i++)
   07AC 7C 00         [12]  803 	mov	r4,#0x00
   07AE                     804 00106$:
   07AE EC            [12]  805 	mov	a,r4
   07AF FA            [12]  806 	mov	r2,a
   07B0 33            [12]  807 	rlc	a
   07B1 95 E0         [12]  808 	subb	a,acc
   07B3 FB            [12]  809 	mov	r3,a
   07B4 E5 08         [12]  810 	mov	a,_bp
   07B6 24 FC         [12]  811 	add	a,#0xfc
   07B8 F8            [12]  812 	mov	r0,a
   07B9 C3            [12]  813 	clr	c
   07BA EA            [12]  814 	mov	a,r2
   07BB 96            [12]  815 	subb	a,@r0
   07BC EB            [12]  816 	mov	a,r3
   07BD 64 80         [12]  817 	xrl	a,#0x80
   07BF 08            [12]  818 	inc	r0
   07C0 86 F0         [24]  819 	mov	b,@r0
   07C2 63 F0 80      [24]  820 	xrl	b,#0x80
   07C5 95 F0         [12]  821 	subb	a,b
   07C7 50 1B         [24]  822 	jnc	00101$
                            823 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:127: RFD = ptr[i];
   07C9 A8 08         [24]  824 	mov	r0,_bp
   07CB 08            [12]  825 	inc	r0
   07CC EC            [12]  826 	mov	a,r4
   07CD 26            [12]  827 	add	a,@r0
   07CE FA            [12]  828 	mov	r2,a
   07CF E4            [12]  829 	clr	a
   07D0 08            [12]  830 	inc	r0
   07D1 36            [12]  831 	addc	a,@r0
   07D2 FB            [12]  832 	mov	r3,a
   07D3 08            [12]  833 	inc	r0
   07D4 86 07         [24]  834 	mov	ar7,@r0
   07D6 8A 82         [24]  835 	mov	dpl,r2
   07D8 8B 83         [24]  836 	mov	dph,r3
   07DA 8F F0         [24]  837 	mov	b,r7
   07DC 12 0A AC      [24]  838 	lcall	__gptrget
   07DF F5 D9         [12]  839 	mov	_RFD,a
                            840 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:125: for (i=0; i<len; i++)
   07E1 0C            [12]  841 	inc	r4
   07E2 80 CA         [24]  842 	sjmp	00106$
   07E4                     843 00101$:
                            844 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:131: RFST = ISTXON;
   07E4 75 E1 E9      [24]  845 	mov	_RFST,#0xE9
                            846 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:134: while (!(RFIRQF1 & 0x02));
   07E7                     847 00102$:
   07E7 E5 91         [12]  848 	mov	a,_RFIRQF1
   07E9 30 E1 FB      [24]  849 	jnb	acc.1,00102$
                            850 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:137: RFST = ISRXON;
   07EC 75 E1 E3      [24]  851 	mov	_RFST,#0xE3
   07EF 85 08 81      [24]  852 	mov	sp,_bp
   07F2 D0 08         [24]  853 	pop	_bp
   07F4 22            [24]  854 	ret
                            855 ;------------------------------------------------------------
                            856 ;Allocation info for local variables in function 'receivePacket'
                            857 ;------------------------------------------------------------
                            858 ;len                       Allocated to stack - _bp -3
                            859 ;rssi                      Allocated to stack - _bp -6
                            860 ;ptr                       Allocated to stack - _bp +1
                            861 ;i                         Allocated to registers r7 
                            862 ;------------------------------------------------------------
                            863 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:142: char receivePacket(char* ptr, char len, signed char* rssi)
                            864 ;	-----------------------------------------
                            865 ;	 function receivePacket
                            866 ;	-----------------------------------------
   07F5                     867 _receivePacket:
   07F5 C0 08         [24]  868 	push	_bp
   07F7 85 81 08      [24]  869 	mov	_bp,sp
   07FA C0 82         [24]  870 	push	dpl
   07FC C0 83         [24]  871 	push	dph
   07FE C0 F0         [24]  872 	push	b
                            873 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:147: RFIRQF0 = 0x00;
   0800 75 E9 00      [24]  874 	mov	_RFIRQF0,#0x00
                            875 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:148: blink(RXFIFOCNT + 1);
   0803 90 00 01      [24]  876 	mov	dptr,#0x0001
   0806 12 00 C7      [24]  877 	lcall	_blink
                            878 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:150: if(RXFIFOCNT != len+14)
   0809 E5 08         [12]  879 	mov	a,_bp
   080B 24 FD         [12]  880 	add	a,#0xfd
   080D F8            [12]  881 	mov	r0,a
   080E 86 03         [24]  882 	mov	ar3,@r0
   0810 E6            [12]  883 	mov	a,@r0
   0811 33            [12]  884 	rlc	a
   0812 95 E0         [12]  885 	subb	a,acc
   0814 FC            [12]  886 	mov	r4,a
   0815 74 0E         [12]  887 	mov	a,#0x0E
   0817 2B            [12]  888 	add	a,r3
   0818 FA            [12]  889 	mov	r2,a
   0819 E4            [12]  890 	clr	a
   081A 3C            [12]  891 	addc	a,r4
   081B FF            [12]  892 	mov	r7,a
   081C 4A            [12]  893 	orl	a,r2
   081D 60 0C         [24]  894 	jz	00120$
                            895 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:152: RFST = ISFLUSHRX; RFST = ISFLUSHRX; //Flush the FIFO - 2 times necessary
   081F 75 E1 ED      [24]  896 	mov	_RFST,#0xED
   0822 75 E1 ED      [24]  897 	mov	_RFST,#0xED
                            898 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:153: return 0; //Error
   0825 75 82 00      [24]  899 	mov	dpl,#0x00
   0828 02 08 A9      [24]  900 	ljmp	00117$
                            901 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:156: for (i = 0; i<12; i++)
   082B                     902 00120$:
   082B 7F 0C         [12]  903 	mov	r7,#0x0C
   082D                     904 00113$:
                            905 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:158: RFD; //Skip through the first 12 bytes, not useful here
   082D E5 D9         [12]  906 	mov	a,_RFD
   082F DF FC         [24]  907 	djnz	r7,00113$
                            908 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:156: for (i = 0; i<12; i++)
                            909 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:162: if(RXFIFOCNT != (len + 2))
   0831 74 02         [12]  910 	mov	a,#0x02
   0833 2B            [12]  911 	add	a,r3
   0834 FB            [12]  912 	mov	r3,a
   0835 E4            [12]  913 	clr	a
   0836 3C            [12]  914 	addc	a,r4
   0837 FC            [12]  915 	mov	r4,a
   0838 4B            [12]  916 	orl	a,r3
   0839 60 0B         [24]  917 	jz	00124$
                            918 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:164: RFST = ISFLUSHRX; RFST = ISFLUSHRX; //Flush the FIFO - 2 times necessary
   083B 75 E1 ED      [24]  919 	mov	_RFST,#0xED
   083E 75 E1 ED      [24]  920 	mov	_RFST,#0xED
                            921 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:165: return 0; //Error
   0841 75 82 00      [24]  922 	mov	dpl,#0x00
                            923 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:171: for(i=0;i<len;i++)
   0844 80 63         [24]  924 	sjmp	00117$
   0846                     925 00124$:
   0846 7F 00         [12]  926 	mov	r7,#0x00
   0848                     927 00115$:
   0848 E5 08         [12]  928 	mov	a,_bp
   084A 24 FD         [12]  929 	add	a,#0xfd
   084C F8            [12]  930 	mov	r0,a
   084D C3            [12]  931 	clr	c
   084E EF            [12]  932 	mov	a,r7
   084F 64 80         [12]  933 	xrl	a,#0x80
   0851 86 F0         [24]  934 	mov	b,@r0
   0853 63 F0 80      [24]  935 	xrl	b,#0x80
   0856 95 F0         [12]  936 	subb	a,b
   0858 50 1B         [24]  937 	jnc	00104$
                            938 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:173: ptr[i] = RFD;
   085A A8 08         [24]  939 	mov	r0,_bp
   085C 08            [12]  940 	inc	r0
   085D EF            [12]  941 	mov	a,r7
   085E 26            [12]  942 	add	a,@r0
   085F FC            [12]  943 	mov	r4,a
   0860 E4            [12]  944 	clr	a
   0861 08            [12]  945 	inc	r0
   0862 36            [12]  946 	addc	a,@r0
   0863 FD            [12]  947 	mov	r5,a
   0864 08            [12]  948 	inc	r0
   0865 86 06         [24]  949 	mov	ar6,@r0
   0867 8C 82         [24]  950 	mov	dpl,r4
   0869 8D 83         [24]  951 	mov	dph,r5
   086B 8E F0         [24]  952 	mov	b,r6
   086D E5 D9         [12]  953 	mov	a,_RFD
   086F 12 0A 71      [24]  954 	lcall	__gptrput
                            955 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:171: for(i=0;i<len;i++)
   0872 0F            [12]  956 	inc	r7
   0873 80 D3         [24]  957 	sjmp	00115$
   0875                     958 00104$:
                            959 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:177: *rssi = RFD + RSSI_OFFSET;
   0875 E5 08         [12]  960 	mov	a,_bp
   0877 24 FA         [12]  961 	add	a,#0xfa
   0879 F8            [12]  962 	mov	r0,a
   087A 86 05         [24]  963 	mov	ar5,@r0
   087C 08            [12]  964 	inc	r0
   087D 86 06         [24]  965 	mov	ar6,@r0
   087F 08            [12]  966 	inc	r0
   0880 86 07         [24]  967 	mov	ar7,@r0
   0882 AC D9         [24]  968 	mov	r4,_RFD
   0884 74 B4         [12]  969 	mov	a,#0xB4
   0886 2C            [12]  970 	add	a,r4
   0887 FC            [12]  971 	mov	r4,a
   0888 8D 82         [24]  972 	mov	dpl,r5
   088A 8E 83         [24]  973 	mov	dph,r6
   088C 8F F0         [24]  974 	mov	b,r7
   088E 12 0A 71      [24]  975 	lcall	__gptrput
                            976 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:180: i = RFD;
                            977 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:181: if(!(i & 0x80)) //MSB of last byte is CRC valid bit
   0891 E5 D9         [12]  978 	mov	a,_RFD
   0893 FF            [12]  979 	mov	r7,a
   0894 30 E7 02      [24]  980 	jnb	acc.7,00148$
   0897 80 09         [24]  981 	sjmp	00106$
   0899                     982 00148$:
                            983 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:182: return len; //0;
   0899 E5 08         [12]  984 	mov	a,_bp
   089B 24 FD         [12]  985 	add	a,#0xfd
   089D F8            [12]  986 	mov	r0,a
   089E 86 82         [24]  987 	mov	dpl,@r0
   08A0 80 07         [24]  988 	sjmp	00117$
   08A2                     989 00106$:
                            990 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:184: return len;
   08A2 E5 08         [12]  991 	mov	a,_bp
   08A4 24 FD         [12]  992 	add	a,#0xfd
   08A6 F8            [12]  993 	mov	r0,a
   08A7 86 82         [24]  994 	mov	dpl,@r0
   08A9                     995 00117$:
   08A9 85 08 81      [24]  996 	mov	sp,_bp
   08AC D0 08         [24]  997 	pop	_bp
   08AE 22            [24]  998 	ret
                            999 ;------------------------------------------------------------
                           1000 ;Allocation info for local variables in function 'isPacketReady'
                           1001 ;------------------------------------------------------------
                           1002 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:190: char isPacketReady(void)
                           1003 ;	-----------------------------------------
                           1004 ;	 function isPacketReady
                           1005 ;	-----------------------------------------
   08AF                    1006 _isPacketReady:
                           1007 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:193: if(RFIRQF0 & 0x40) //Bit 6 means frame accepted and loaded
   08AF E5 E9         [12] 1008 	mov	a,_RFIRQF0
   08B1 30 E6 04      [24] 1009 	jnb	acc.6,00102$
                           1010 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:194: return 1;
   08B4 75 82 01      [24] 1011 	mov	dpl,#0x01
   08B7 22            [24] 1012 	ret
   08B8                    1013 00102$:
                           1014 ;	/home/timvandermeij/Desktop/radio-tomography/projects/rf-node-project/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.c:196: return 0;
   08B8 75 82 00      [24] 1015 	mov	dpl,#0x00
   08BB 22            [24] 1016 	ret
                           1017 	.area CSEG    (CODE)
                           1018 	.area CONST   (CODE)
                           1019 	.area XINIT   (CODE)
                           1020 	.area CABS    (ABS,CODE)
