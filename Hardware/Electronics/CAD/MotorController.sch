EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:74xgxx
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:ESP8266
LIBS:HiLink
LIBS:Nema
LIBS:TMC2130
LIBS:MotorController-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Motor Controller"
Date "2018-02-10"
Rev "1.1.0"
Comp "Felix Kübler"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP-12E U4
U 1 1 592BD8DB
P 3850 6200
F 0 "U4" H 3850 6925 50  0000 C CNN
F 1 "ESP-12E" H 3850 6850 50  0000 C CNN
F 2 "ESP8266:ESP-12E_SMD" H 3850 6200 50  0001 C CNN
F 3 "" H 3850 6200 50  0001 C CNN
	1    3850 6200
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 J1
U 1 1 592BDEB8
P 3200 1525
F 0 "J1" H 3200 1950 50  0000 C CNN
F 1 "MPE 094-1-006" H 3475 1875 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm_SMD_Pin1Right" H 3200 1525 50  0001 C CNN
F 3 "" H 3200 1525 50  0001 C CNN
	1    3200 1525
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 592C2849
P 4950 6600
F 0 "#PWR01" H 4950 6350 50  0001 C CNN
F 1 "GND" V 4850 6525 50  0000 C CNN
F 2 "" H 4950 6600 50  0001 C CNN
F 3 "" H 4950 6600 50  0001 C CNN
	1    4950 6600
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 592C2C75
P 2750 6600
F 0 "#PWR02" H 2750 6450 50  0001 C CNN
F 1 "+3.3V" V 2650 6675 50  0000 C CNN
F 2 "" H 2750 6600 50  0001 C CNN
F 3 "" H 2750 6600 50  0001 C CNN
	1    2750 6600
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 592C2CAB
P 2750 6100
F 0 "#PWR03" H 2750 5950 50  0001 C CNN
F 1 "+3.3V" V 2750 6350 50  0000 C CNN
F 2 "" H 2750 6100 50  0001 C CNN
F 3 "" H 2750 6100 50  0001 C CNN
	1    2750 6100
	0    -1   -1   0   
$EndComp
Text GLabel 5300 5750 2    60   Input ~ 0
TX
Text GLabel 5300 5900 2    60   Input ~ 0
RX
Text GLabel 4900 6300 2    60   Input ~ 0
MODE
Text GLabel 2300 6450 0    60   Input ~ 0
MOTOR_STEP
Text GLabel 2300 6600 0    60   Input ~ 0
MOTOR_DIR
NoConn ~ 2950 5900
NoConn ~ 3800 7100
NoConn ~ 3900 7100
$Comp
L GND #PWR04
U 1 1 592C460C
P 2850 1775
F 0 "#PWR04" H 2850 1525 50  0001 C CNN
F 1 "GND" V 2900 1575 50  0000 C CNN
F 2 "" H 2850 1775 50  0001 C CNN
F 3 "" H 2850 1775 50  0001 C CNN
	1    2850 1775
	0    1    1    0   
$EndComp
Text GLabel 2600 1475 0    60   Input ~ 0
RX
Text GLabel 2600 1325 0    60   Input ~ 0
TX
NoConn ~ 3000 1275
NoConn ~ 3000 1675
Text GLabel 2525 2525 0    60   Input ~ 0
MODE
$Comp
L GND #PWR05
U 1 1 592C5F8F
P 2900 2425
F 0 "#PWR05" H 2900 2175 50  0001 C CNN
F 1 "GND" V 2900 2225 50  0000 C CNN
F 2 "" H 2900 2425 50  0001 C CNN
F 3 "" H 2900 2425 50  0001 C CNN
	1    2900 2425
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR06
U 1 1 592C600F
P 2900 2625
F 0 "#PWR06" H 2900 2475 50  0001 C CNN
F 1 "+3.3V" V 2900 2875 50  0000 C CNN
F 2 "" H 2900 2625 50  0001 C CNN
F 3 "" H 2900 2625 50  0001 C CNN
	1    2900 2625
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR07
U 1 1 595EB4E9
P 5300 6400
F 0 "#PWR07" H 5300 6250 50  0001 C CNN
F 1 "+3.3V" V 5350 6600 50  0000 C CNN
F 2 "" H 5300 6400 50  0001 C CNN
F 3 "" H 5300 6400 50  0001 C CNN
	1    5300 6400
	0    1    1    0   
$EndComp
$Comp
L SW_DPST_x2 SW2
U 1 1 599EBC5A
P 2450 3200
F 0 "SW2" H 2450 3100 50  0000 C CNN
F 1 "Taster 9314" H 2450 3025 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_SKQG" H 2450 3200 50  0001 C CNN
F 3 "" H 2450 3200 50  0001 C CNN
	1    2450 3200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR08
U 1 1 599EBD49
P 2100 3200
F 0 "#PWR08" H 2100 3050 50  0001 C CNN
F 1 "+3.3V" V 2100 3450 50  0000 C CNN
F 2 "" H 2100 3200 50  0001 C CNN
F 3 "" H 2100 3200 50  0001 C CNN
	1    2100 3200
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 599EC273
P 3000 3350
F 0 "R5" V 3080 3350 50  0000 C CNN
F 1 "RND 0805 1 10K" V 3150 3625 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2930 3350 50  0001 C CNN
F 3 "" H 3000 3350 50  0001 C CNN
	1    3000 3350
	0    1    1    0   
$EndComp
$Comp
L GND #PWR09
U 1 1 599EC69C
P 3300 3350
F 0 "#PWR09" H 3300 3100 50  0001 C CNN
F 1 "GND" V 3300 3150 50  0000 C CNN
F 2 "" H 3300 3350 50  0001 C CNN
F 3 "" H 3300 3350 50  0001 C CNN
	1    3300 3350
	0    -1   -1   0   
$EndComp
Text GLabel 3100 3200 2    60   Input ~ 0
RESET
Text GLabel 5300 6200 2    60   Input ~ 0
RESET
$Comp
L +3.3V #PWR010
U 1 1 5A1C2463
P 2850 1575
F 0 "#PWR010" H 2850 1425 50  0001 C CNN
F 1 "+3.3V" V 2775 1800 50  0000 C CNN
F 2 "" H 2850 1575 50  0001 C CNN
F 3 "" H 2850 1575 50  0001 C CNN
	1    2850 1575
	0    -1   -1   0   
$EndComp
Text GLabel 2300 6300 0    60   Input ~ 0
MOTOR_ENABLE
$Comp
L LD1117S33CTR U1
U 1 1 5A294B4E
P 5775 3025
F 0 "U1" H 5775 3300 50  0000 C CNN
F 1 "LD1117S33CTR" H 5775 3225 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 5775 3125 50  0001 C CNN
F 3 "" H 5775 3025 50  0001 C CNN
	1    5775 3025
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR011
U 1 1 5A294EEF
P 6325 2975
F 0 "#PWR011" H 6325 2825 50  0001 C CNN
F 1 "+3.3V" V 6325 3200 50  0000 C CNN
F 2 "" H 6325 2975 50  0001 C CNN
F 3 "" H 6325 2975 50  0001 C CNN
	1    6325 2975
	0    1    1    0   
$EndComp
$Comp
L +12V #PWR012
U 1 1 5A294F1E
P 5225 2975
F 0 "#PWR012" H 5225 2825 50  0001 C CNN
F 1 "+12V" V 5225 3200 50  0000 C CNN
F 2 "" H 5225 2975 50  0001 C CNN
F 3 "" H 5225 2975 50  0001 C CNN
	1    5225 2975
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 5A294F4D
P 5775 3425
F 0 "#PWR013" H 5775 3175 50  0001 C CNN
F 1 "GND" V 5775 3225 50  0000 C CNN
F 2 "" H 5775 3425 50  0001 C CNN
F 3 "" H 5775 3425 50  0001 C CNN
	1    5775 3425
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5A295074
P 6025 3325
F 0 "C2" H 6050 3425 50  0000 L CNN
F 1 "C" H 6050 3225 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6063 3175 50  0001 C CNN
F 3 "" H 6025 3325 50  0001 C CNN
	1    6025 3325
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 5A295100
P 5525 3325
F 0 "C1" H 5550 3425 50  0000 L CNN
F 1 "C" H 5550 3225 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5563 3175 50  0001 C CNN
F 3 "" H 5525 3325 50  0001 C CNN
	1    5525 3325
	0    1    1    0   
$EndComp
Text GLabel 8400 4275 2    60   Input ~ 0
MOTOR_DIR
Text GLabel 8400 4425 2    60   Input ~ 0
MOTOR_STEP
$Comp
L +3.3V #PWR014
U 1 1 5A2EB86A
P 6900 4425
F 0 "#PWR014" H 6900 4275 50  0001 C CNN
F 1 "+3.3V" V 6900 4675 50  0000 C CNN
F 2 "" H 6900 4425 50  0001 C CNN
F 3 "" H 6900 4425 50  0001 C CNN
	1    6900 4425
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR015
U 1 1 5A2EB8A2
P 6900 4325
F 0 "#PWR015" H 6900 4075 50  0001 C CNN
F 1 "GND" V 6900 4100 50  0000 C CNN
F 2 "" H 6900 4325 50  0001 C CNN
F 3 "" H 6900 4325 50  0001 C CNN
	1    6900 4325
	0    1    1    0   
$EndComp
Text GLabel 8400 5125 2    60   Input ~ 0
MOTOR_ENABLE
$Comp
L CONN_01X04 J5
U 1 1 5A2EBF8D
P 6350 4675
F 0 "J5" H 6350 5025 50  0000 C CNN
F 1 "CONN_01X04" H 6525 4925 50  0000 C CNN
F 2 "Terminal:Pin_Header_SMD_Angled_2.54mm" H 6350 4675 50  0001 C CNN
F 3 "" H 6350 4675 50  0001 C CNN
	1    6350 4675
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5A2EC268
P 6900 4925
F 0 "#PWR016" H 6900 4675 50  0001 C CNN
F 1 "GND" V 6900 4700 50  0000 C CNN
F 2 "" H 6900 4925 50  0001 C CNN
F 3 "" H 6900 4925 50  0001 C CNN
	1    6900 4925
	0    1    1    0   
$EndComp
$Comp
L +12V #PWR017
U 1 1 5A2EC2F3
P 6900 5025
F 0 "#PWR017" H 6900 4875 50  0001 C CNN
F 1 "+12V" V 6900 5250 50  0000 C CNN
F 2 "" H 6900 5025 50  0001 C CNN
F 3 "" H 6900 5025 50  0001 C CNN
	1    6900 5025
	0    -1   -1   0   
$EndComp
$Comp
L TMC2130 U3
U 1 1 5A56765A
P 7650 4675
F 0 "U3" H 7650 5200 60  0000 C CNN
F 1 "TMC2130" H 7650 5125 50  0000 C CNN
F 2 "StepStick:TMC2230_SMD" H 7650 4675 60  0001 C CNN
F 3 "" H 7650 4675 60  0001 C CNN
	1    7650 4675
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 J2
U 1 1 5A5683AA
P 3200 2525
F 0 "J2" H 3200 2800 50  0000 C CNN
F 1 "CONN_01X03" H 3400 2725 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm_SMD_Pin1Right" H 3200 2525 50  0001 C CNN
F 3 "" H 3200 2525 50  0001 C CNN
	1    3200 2525
	1    0    0    -1  
$EndComp
NoConn ~ 8250 4525
NoConn ~ 8250 4625
NoConn ~ 8250 4725
NoConn ~ 8250 4825
NoConn ~ 8250 4925
NoConn ~ 4750 6100
NoConn ~ 2950 6200
NoConn ~ 4000 7100
NoConn ~ 4100 7100
NoConn ~ 3700 7100
NoConn ~ 3600 7100
Text GLabel 2275 6000 0    60   Input ~ 0
CURRENT_FEEDBACK
$Comp
L HiLink U5
U 1 1 5AA9B92D
P 6625 2000
F 0 "U5" H 6625 2300 60  0000 C CNN
F 1 "HiLink" H 6625 2225 60  0000 C CNN
F 2 "HiLink:HLK-PM01" H 6625 2000 60  0001 C CNN
F 3 "" H 6625 2000 60  0001 C CNN
	1    6625 2000
	1    0    0    -1  
$EndComp
$Comp
L MAX471 U2
U 1 1 5AC699A6
P 7975 2300
F 0 "U2" H 7950 2725 50  0000 L CNN
F 1 "MAX471" H 7850 2650 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 7975 2300 50  0001 C CNN
F 3 "" H 7975 2300 50  0001 C CNN
	1    7975 2300
	1    0    0    -1  
$EndComp
$Comp
L Screw_Terminal_1x02 J3
U 1 1 5AC69CD5
P 5925 2000
F 0 "J3" H 5975 1725 50  0000 C TNN
F 1 "SolderTerminal" H 5750 1800 50  0000 C TNN
F 2 "Terminal:SolderTerminal" H 5925 1775 50  0001 C CNN
F 3 "" H 5900 2000 50  0001 C CNN
	1    5925 2000
	1    0    0    1   
$EndComp
$Comp
L +12V #PWR018
U 1 1 5AC69F04
P 8475 2100
F 0 "#PWR018" H 8475 1950 50  0001 C CNN
F 1 "+12V" V 8475 2325 50  0000 C CNN
F 2 "" H 8475 2100 50  0001 C CNN
F 3 "" H 8475 2100 50  0001 C CNN
	1    8475 2100
	0    1    1    0   
$EndComp
$Comp
L GND #PWR019
U 1 1 5AC69F36
P 7125 1900
F 0 "#PWR019" H 7125 1650 50  0001 C CNN
F 1 "GND" V 7125 1700 50  0000 C CNN
F 2 "" H 7125 1900 50  0001 C CNN
F 3 "" H 7125 1900 50  0001 C CNN
	1    7125 1900
	0    -1   -1   0   
$EndComp
Text GLabel 8875 2500 2    60   Input ~ 0
CURRENT_FEEDBACK
NoConn ~ 8375 2400
$Comp
L GND #PWR020
U 1 1 5AC6B0DF
P 7475 2500
F 0 "#PWR020" H 7475 2250 50  0001 C CNN
F 1 "GND" V 7475 2300 50  0000 C CNN
F 2 "" H 7475 2500 50  0001 C CNN
F 3 "" H 7475 2500 50  0001 C CNN
	1    7475 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	4750 6600 4950 6600
Wire Wire Line
	4750 6500 4850 6500
Wire Wire Line
	4850 6500 4850 6600
Connection ~ 4850 6600
Wire Wire Line
	2950 6100 2750 6100
Wire Wire Line
	2750 6600 2950 6600
Wire Wire Line
	2950 6400 2450 6400
Wire Wire Line
	2450 6400 2450 6450
Wire Wire Line
	2500 6600 2500 6500
Wire Wire Line
	2500 6500 2950 6500
Wire Wire Line
	2450 6450 2300 6450
Wire Wire Line
	2300 6600 2500 6600
Wire Wire Line
	4900 6300 4750 6300
Wire Wire Line
	3000 1475 2600 1475
Wire Wire Line
	3000 1375 2750 1375
Wire Wire Line
	2750 1375 2750 1325
Wire Wire Line
	2750 1325 2600 1325
Wire Wire Line
	2850 1575 3000 1575
Wire Wire Line
	3000 1775 2850 1775
Wire Wire Line
	2525 2525 3000 2525
Wire Wire Line
	4750 6400 5300 6400
Wire Wire Line
	2100 3200 2250 3200
Wire Wire Line
	3150 3350 3300 3350
Wire Wire Line
	2650 3200 3100 3200
Wire Wire Line
	2850 3350 2850 3200
Connection ~ 2850 3200
Wire Wire Line
	5300 6200 4750 6200
Wire Wire Line
	4750 6000 5050 6000
Wire Wire Line
	5050 6000 5050 5900
Wire Wire Line
	5050 5900 5300 5900
Wire Wire Line
	4750 5900 4950 5900
Wire Wire Line
	4950 5900 4950 5750
Wire Wire Line
	4950 5750 5300 5750
Wire Wire Line
	5775 3275 5775 3425
Wire Wire Line
	6175 2975 6325 2975
Wire Wire Line
	5225 2975 5375 2975
Wire Wire Line
	6175 3325 6250 3325
Wire Wire Line
	6250 3325 6250 2975
Connection ~ 6250 2975
Wire Wire Line
	5325 2975 5325 3325
Wire Wire Line
	5325 3325 5375 3325
Connection ~ 5325 2975
Wire Wire Line
	5675 3325 5875 3325
Connection ~ 5775 3325
Wire Wire Line
	8250 4325 8325 4325
Wire Wire Line
	8325 4325 8325 4275
Wire Wire Line
	8325 4275 8400 4275
Wire Wire Line
	8400 4425 8250 4425
Wire Wire Line
	7050 4325 6900 4325
Wire Wire Line
	6900 4425 7050 4425
Wire Wire Line
	6550 4525 7050 4525
Wire Wire Line
	7050 4625 6550 4625
Wire Wire Line
	6550 4725 7050 4725
Wire Wire Line
	7050 4825 6550 4825
Wire Wire Line
	6900 4925 7050 4925
Wire Wire Line
	7050 5025 6900 5025
Wire Wire Line
	8250 5025 8325 5025
Wire Wire Line
	8325 5025 8325 5125
Wire Wire Line
	8325 5125 8400 5125
Wire Wire Line
	2900 2425 3000 2425
Wire Wire Line
	3000 2625 2900 2625
Wire Wire Line
	2950 6300 2300 6300
Wire Wire Line
	2950 6000 2275 6000
Wire Wire Line
	6125 1900 6225 1900
Wire Wire Line
	6225 2100 6125 2100
Wire Wire Line
	7025 1900 7125 1900
Wire Wire Line
	7575 2200 7525 2200
Wire Wire Line
	7525 2200 7525 2100
Connection ~ 7525 2100
Wire Wire Line
	8475 2100 8375 2100
Wire Wire Line
	8375 2200 8425 2200
Wire Wire Line
	8425 2200 8425 2100
Connection ~ 8425 2100
Wire Wire Line
	7025 2100 7575 2100
Wire Wire Line
	8375 2500 8475 2500
Wire Wire Line
	7475 2500 7575 2500
Wire Wire Line
	7575 2400 7525 2400
Wire Wire Line
	7525 2400 7525 2500
Connection ~ 7525 2500
$Comp
L Nema U6
U 1 1 5AC97FEF
P 2750 4325
F 0 "U6" H 2750 4525 60  0000 C CNN
F 1 "Nema" H 2750 4425 60  0000 C CNN
F 2 "Nema:Nema17" H 2750 4325 60  0001 C CNN
F 3 "" H 2750 4325 60  0001 C CNN
	1    2750 4325
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5ACA9F3E
P 8625 2500
F 0 "R1" V 8705 2500 50  0000 C CNN
F 1 "RND 0805 1 10K" V 8775 2775 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8555 2500 50  0001 C CNN
F 3 "" H 8625 2500 50  0001 C CNN
	1    8625 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	8775 2500 8875 2500
$Comp
L R R2
U 1 1 5ACAA259
P 8625 2800
F 0 "R2" V 8705 2800 50  0000 C CNN
F 1 "RND 0805 1 10K" V 8775 3075 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8555 2800 50  0001 C CNN
F 3 "" H 8625 2800 50  0001 C CNN
	1    8625 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	8475 2800 8425 2800
Wire Wire Line
	8425 2800 8425 2500
Connection ~ 8425 2500
$Comp
L GND #PWR021
U 1 1 5ACAA303
P 8875 2800
F 0 "#PWR021" H 8875 2550 50  0001 C CNN
F 1 "GND" V 8875 2600 50  0000 C CNN
F 2 "" H 8875 2800 50  0001 C CNN
F 3 "" H 8875 2800 50  0001 C CNN
	1    8875 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8775 2800 8875 2800
$EndSCHEMATC
