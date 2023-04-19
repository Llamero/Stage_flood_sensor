EESchema Schematic File Version 5
EELAYER 43 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
Comment5 ""
Comment6 ""
Comment7 ""
Comment8 ""
Comment9 ""
$EndDescr
Connection ~ 3500 2500
Wire Wire Line
	3400 2500 3500 2500
Wire Wire Line
	3500 2500 3600 2500
Text Label 3200 2300 2    50   ~ 0
Sense
$Comp
L Stage~flood~sensor-rescue:Conn_01x01_Female-Connector J1
U 1 1 643C32F2
P 3800 2300
F 0 "J1" H 3828 2326 50  0000 L CNN
F 1 "Conn_01x01_Female" H 3828 2235 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_SMD_5x10mm" H 3800 2300 50  0001 C CNN
F 3 "~" H 3800 2300 50  0001 C CNN
	1    3800 2300
	1    0    0    -1  
$EndComp
$Comp
L Stage~flood~sensor-rescue:Conn_01x01_Female-Connector J2
U 1 1 643C46D3
P 3800 2500
F 0 "J2" H 3828 2526 50  0000 L CNN
F 1 "Conn_01x01_Female" H 3828 2435 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_SMD_5x10mm" H 3800 2500 50  0001 C CNN
F 3 "~" H 3800 2500 50  0001 C CNN
	1    3800 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 643C2712
P 3500 2500
F 0 "#PWR0101" H 3500 2250 50  0001 C CNN
F 1 "GND" H 3505 2327 50  0000 C CNN
F 2 "" H 3500 2500 50  0001 C CNN
F 3 "" H 3500 2500 50  0001 C CNN
	1    3500 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:Filter_EMI_C C1
U 1 1 00000000
P 3400 2400
F 0 "C1" H 3450 2700 50  0000 C CNN
F 1 "Filter_EMI_C" H 3450 2600 50  0000 C CNN
F 2 "" V 3400 2400 50  0001 C CNN
F 3 "http://www.murata.com/~/media/webrenewal/support/library/catalog/products/emc/emifil/c31e.ashx?la=en-gb" V 3400 2400 50  0001 C CNN
	1    3400 2400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
