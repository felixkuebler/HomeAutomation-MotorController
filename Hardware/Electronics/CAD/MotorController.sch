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
P 7650 3050
F 0 "U4" H 7650 3775 50  0000 C CNN
F 1 "ESP-12E" H 7650 3700 50  0000 C CNN
F 2 "ESP8266:ESP-12E_SMD" H 7650 3050 50  0001 C CNN
F 3 "" H 7650 3050 50  0001 C CNN
	1    7650 3050
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 J1
U 1 1 592BDEB8
P 3200 1525
F 0 "J1" H 3200 1950 50  0000 C CNN
F 1 "MPE 094-1-006" H 3475 1875 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Angled_1x06_Pitch2.54mm" H 3200 1525 50  0001 C CNN
F 3 "" H 3200 1525 50  0001 C CNN
	1    3200 1525
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 592C2849
P 8750 3450
F 0 "#PWR01" H 8750 3200 50  0001 C CNN
F 1 "GND" V 8650 3375 50  0000 C CNN
F 2 "" H 8750 3450 50  0001 C CNN
F 3 "" H 8750 3450 50  0001 C CNN
	1    8750 3450
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 592C2C75
P 6550 3450
F 0 "#PWR02" H 6550 3300 50  0001 C CNN
F 1 "+3.3V" V 6450 3525 50  0000 C CNN
F 2 "" H 6550 3450 50  0001 C CNN
F 3 "" H 6550 3450 50  0001 C CNN
	1    6550 3450
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 592C2CAB
P 6550 2950
F 0 "#PWR03" H 6550 2800 50  0001 C CNN
F 1 "+3.3V" V 6550 3200 50  0000 C CNN
F 2 "" H 6550 2950 50  0001 C CNN
F 3 "" H 6550 2950 50  0001 C CNN
	1    6550 2950
	0    -1   -1   0   
$EndComp
Text GLabel 9100 2600 2    60   Input ~ 0
TX
Text GLabel 9100 2750 2    60   Input ~ 0
RX
Text GLabel 8700 3150 2    60   Input ~ 0
MODE
Text GLabel 6100 3300 0    60   Input ~ 0
MOTOR_STEP
Text GLabel 6100 3450 0    60   Input ~ 0
MOTOR_DIR
NoConn ~ 6750 2750
NoConn ~ 7600 3950
NoConn ~ 7700 3950
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
P 9100 3250
F 0 "#PWR07" H 9100 3100 50  0001 C CNN
F 1 "+3.3V" V 9150 3450 50  0000 C CNN
F 2 "" H 9100 3250 50  0001 C CNN
F 3 "" H 9100 3250 50  0001 C CNN
	1    9100 3250
	0    1    1    0   
$EndComp
$Comp
L SW_DPST_x2 SW2
U 1 1 599EBC5A
P 2450 3200
F 0 "SW2" H 2450 3100 50  0000 C CNN
F 1 "SW_DPST_x2" H 2450 3000 50  0000 C CNN
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
F 1 "RND 0805 1 10K" V 3150 3350 50  0000 C CNN
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
Text GLabel 9100 3050 2    60   Input ~ 0
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
Text GLabel 6100 3150 0    60   Input ~ 0
MOTOR_ENABLE
$Comp
L LD1117S33CTR U1
U 1 1 5A294B4E
P 9425 1425
F 0 "U1" H 9425 1675 50  0000 C CNN
F 1 "LD1117S33CTR" H 9425 1625 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 9425 1525 50  0001 C CNN
F 3 "" H 9425 1425 50  0001 C CNN
	1    9425 1425
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR011
U 1 1 5A294EEF
P 9975 1375
F 0 "#PWR011" H 9975 1225 50  0001 C CNN
F 1 "+3.3V" V 9975 1600 50  0000 C CNN
F 2 "" H 9975 1375 50  0001 C CNN
F 3 "" H 9975 1375 50  0001 C CNN
	1    9975 1375
	0    1    1    0   
$EndComp
$Comp
L +12V #PWR012
U 1 1 5A294F1E
P 8875 1375
F 0 "#PWR012" H 8875 1225 50  0001 C CNN
F 1 "+12V" V 8875 1600 50  0000 C CNN
F 2 "" H 8875 1375 50  0001 C CNN
F 3 "" H 8875 1375 50  0001 C CNN
	1    8875 1375
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 5A294F4D
P 9425 1825
F 0 "#PWR013" H 9425 1575 50  0001 C CNN
F 1 "GND" V 9425 1625 50  0000 C CNN
F 2 "" H 9425 1825 50  0001 C CNN
F 3 "" H 9425 1825 50  0001 C CNN
	1    9425 1825
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5A295074
P 9675 1725
F 0 "C2" H 9700 1825 50  0000 L CNN
F 1 "C" H 9700 1625 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 9713 1575 50  0001 C CNN
F 3 "" H 9675 1725 50  0001 C CNN
	1    9675 1725
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 5A295100
P 9175 1725
F 0 "C1" H 9200 1825 50  0000 L CNN
F 1 "C" H 9200 1625 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 9213 1575 50  0001 C CNN
F 3 "" H 9175 1725 50  0001 C CNN
	1    9175 1725
	0    1    1    0   
$EndComp
Text GLabel 8400 4825 2    60   Input ~ 0
MOTOR_DIR
Text GLabel 8400 4975 2    60   Input ~ 0
MOTOR_STEP
$Comp
L +3.3V #PWR014
U 1 1 5A2EB86A
P 6900 4975
F 0 "#PWR014" H 6900 4825 50  0001 C CNN
F 1 "+3.3V" V 6900 5225 50  0000 C CNN
F 2 "" H 6900 4975 50  0001 C CNN
F 3 "" H 6900 4975 50  0001 C CNN
	1    6900 4975
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR015
U 1 1 5A2EB8A2
P 6900 4875
F 0 "#PWR015" H 6900 4625 50  0001 C CNN
F 1 "GND" V 6900 4650 50  0000 C CNN
F 2 "" H 6900 4875 50  0001 C CNN
F 3 "" H 6900 4875 50  0001 C CNN
	1    6900 4875
	0    1    1    0   
$EndComp
Text GLabel 8400 5675 2    60   Input ~ 0
MOTOR_ENABLE
$Comp
L CONN_01X04 J5
U 1 1 5A2EBF8D
P 6350 5225
F 0 "J5" H 6575 4900 50  0000 C CNN
F 1 "CONN_01X04" H 6600 4975 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x04_Pitch2.54mm" H 6350 5225 50  0001 C CNN
F 3 "" H 6350 5225 50  0001 C CNN
	1    6350 5225
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR016
U 1 1 5A2EC268
P 6900 5475
F 0 "#PWR016" H 6900 5225 50  0001 C CNN
F 1 "GND" V 6900 5250 50  0000 C CNN
F 2 "" H 6900 5475 50  0001 C CNN
F 3 "" H 6900 5475 50  0001 C CNN
	1    6900 5475
	0    1    1    0   
$EndComp
$Comp
L +12V #PWR017
U 1 1 5A2EC2F3
P 6900 5575
F 0 "#PWR017" H 6900 5425 50  0001 C CNN
F 1 "+12V" V 6900 5800 50  0000 C CNN
F 2 "" H 6900 5575 50  0001 C CNN
F 3 "" H 6900 5575 50  0001 C CNN
	1    6900 5575
	0    -1   -1   0   
$EndComp
$Comp
L TMC2130 U3
U 1 1 5A56765A
P 7650 5225
F 0 "U3" H 7650 5675 60  0000 C CNN
F 1 "TMC2130" V 7650 5225 50  0000 C CNN
F 2 "StepStick:TMC2130_SMD" H 7650 5225 60  0001 C CNN
F 3 "" H 7650 5225 60  0001 C CNN
	1    7650 5225
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 J2
U 1 1 5A5683AA
P 3200 2525
F 0 "J2" H 3200 2725 50  0000 C CNN
F 1 "CONN_01X03" V 3300 2525 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x03_Pitch2.54mm" H 3200 2525 50  0001 C CNN
F 3 "" H 3200 2525 50  0001 C CNN
	1    3200 2525
	1    0    0    -1  
$EndComp
NoConn ~ 8250 5075
NoConn ~ 8250 5175
NoConn ~ 8250 5275
NoConn ~ 8250 5375
NoConn ~ 8250 5475
NoConn ~ 8550 2950
NoConn ~ 6750 3050
NoConn ~ 7800 3950
NoConn ~ 7900 3950
NoConn ~ 7500 3950
NoConn ~ 7400 3950
Text GLabel 6075 2850 0    60   Input ~ 0
CURRENT_FEEDBACK
$Comp
L HiLink U5
U 1 1 5AA9B92D
P 5950 1300
F 0 "U5" H 5950 1075 60  0000 C CNN
F 1 "HiLink" H 5950 1525 60  0000 C CNN
F 2 "HiLink:HiLink" H 5950 1300 60  0001 C CNN
F 3 "" H 5950 1300 60  0001 C CNN
	1    5950 1300
	1    0    0    -1  
$EndComp
$Comp
L MAX471 U2
U 1 1 5AC699A6
P 7300 1600
F 0 "U2" H 7000 1950 50  0000 L CNN
F 1 "MAX471" H 7000 1250 50  0000 L CNN
F 2 "SOP:SOP-8" H 7300 1600 50  0001 C CNN
F 3 "" H 7300 1600 50  0001 C CNN
	1    7300 1600
	1    0    0    -1  
$EndComp
$Comp
L Screw_Terminal_1x02 J3
U 1 1 5AC69CD5
P 5250 1300
F 0 "J3" H 5250 1550 50  0000 C TNN
F 1 "Screw_Terminal_1x02" V 5100 1300 50  0000 C TNN
F 2 "WAGO:WAGO_2pin" H 5250 1075 50  0001 C CNN
F 3 "" H 5225 1300 50  0001 C CNN
	1    5250 1300
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR018
U 1 1 5AC69F04
P 7800 1400
F 0 "#PWR018" H 7800 1250 50  0001 C CNN
F 1 "+12V" V 7800 1625 50  0000 C CNN
F 2 "" H 7800 1400 50  0001 C CNN
F 3 "" H 7800 1400 50  0001 C CNN
	1    7800 1400
	0    1    1    0   
$EndComp
$Comp
L GND #PWR019
U 1 1 5AC69F36
P 6450 1200
F 0 "#PWR019" H 6450 950 50  0001 C CNN
F 1 "GND" V 6450 1000 50  0000 C CNN
F 2 "" H 6450 1200 50  0001 C CNN
F 3 "" H 6450 1200 50  0001 C CNN
	1    6450 1200
	0    -1   -1   0   
$EndComp
Text GLabel 7800 1800 2    60   Input ~ 0
CURRENT_FEEDBACK
NoConn ~ 7700 1700
$Comp
L GND #PWR020
U 1 1 5AC6B0DF
P 6800 1800
F 0 "#PWR020" H 6800 1550 50  0001 C CNN
F 1 "GND" V 6800 1600 50  0000 C CNN
F 2 "" H 6800 1800 50  0001 C CNN
F 3 "" H 6800 1800 50  0001 C CNN
	1    6800 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	8550 3450 8750 3450
Wire Wire Line
	8550 3350 8650 3350
Wire Wire Line
	8650 3350 8650 3450
Connection ~ 8650 3450
Wire Wire Line
	6750 2950 6550 2950
Wire Wire Line
	6550 3450 6750 3450
Wire Wire Line
	6750 3250 6250 3250
Wire Wire Line
	6250 3250 6250 3300
Wire Wire Line
	6300 3450 6300 3350
Wire Wire Line
	6300 3350 6750 3350
Wire Wire Line
	6250 3300 6100 3300
Wire Wire Line
	6100 3450 6300 3450
Wire Wire Line
	8700 3150 8550 3150
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
	8550 3250 9100 3250
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
	9100 3050 8550 3050
Wire Wire Line
	8550 2850 8850 2850
Wire Wire Line
	8850 2850 8850 2750
Wire Wire Line
	8850 2750 9100 2750
Wire Wire Line
	8550 2750 8750 2750
Wire Wire Line
	8750 2750 8750 2600
Wire Wire Line
	8750 2600 9100 2600
Wire Wire Line
	9425 1675 9425 1825
Wire Wire Line
	9825 1375 9975 1375
Wire Wire Line
	8875 1375 9025 1375
Wire Wire Line
	9825 1725 9900 1725
Wire Wire Line
	9900 1725 9900 1375
Connection ~ 9900 1375
Wire Wire Line
	8975 1375 8975 1725
Wire Wire Line
	8975 1725 9025 1725
Connection ~ 8975 1375
Wire Wire Line
	9325 1725 9525 1725
Connection ~ 9425 1725
Wire Wire Line
	8250 4875 8325 4875
Wire Wire Line
	8325 4875 8325 4825
Wire Wire Line
	8325 4825 8400 4825
Wire Wire Line
	8400 4975 8250 4975
Wire Wire Line
	7050 4875 6900 4875
Wire Wire Line
	6900 4975 7050 4975
Wire Wire Line
	6550 5075 7050 5075
Wire Wire Line
	7050 5175 6550 5175
Wire Wire Line
	6550 5275 7050 5275
Wire Wire Line
	7050 5375 6550 5375
Wire Wire Line
	6900 5475 7050 5475
Wire Wire Line
	7050 5575 6900 5575
Wire Wire Line
	8250 5575 8325 5575
Wire Wire Line
	8325 5575 8325 5675
Wire Wire Line
	8325 5675 8400 5675
Wire Wire Line
	2900 2425 3000 2425
Wire Wire Line
	3000 2625 2900 2625
Wire Wire Line
	6750 3150 6100 3150
Wire Wire Line
	6750 2850 6075 2850
Wire Wire Line
	5450 1200 5550 1200
Wire Wire Line
	5550 1400 5450 1400
Wire Wire Line
	6350 1200 6450 1200
Wire Wire Line
	6900 1500 6850 1500
Wire Wire Line
	6850 1500 6850 1400
Connection ~ 6850 1400
Wire Wire Line
	7800 1400 7700 1400
Wire Wire Line
	7700 1500 7750 1500
Wire Wire Line
	7750 1500 7750 1400
Connection ~ 7750 1400
Wire Wire Line
	6350 1400 6900 1400
Wire Wire Line
	7700 1800 7800 1800
Wire Wire Line
	6800 1800 6900 1800
Wire Wire Line
	6900 1700 6850 1700
Wire Wire Line
	6850 1700 6850 1800
Connection ~ 6850 1800
$Comp
L Nema U6
U 1 1 5AC97FEF
P 3625 4575
F 0 "U6" H 3625 4775 60  0000 C CNN
F 1 "Nema" H 3625 4675 60  0000 C CNN
F 2 "Nema:Nema17" H 3625 4575 60  0001 C CNN
F 3 "" H 3625 4575 60  0001 C CNN
	1    3625 4575
	1    0    0    -1  
$EndComp
$EndSCHEMATC
