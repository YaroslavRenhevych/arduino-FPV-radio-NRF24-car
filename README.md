# arduino-FPV-radio-NRF24-car
FPV car with radio remote controller based on Arduino and NFR24 modules.

Communication technology: radio

## Libraries:
- https://github.com/AndreaLombardo/L298N
- RF24 by TMRh20 https://www.arduino.cc/reference/en/libraries/rf24/ (https://github.com/nRF24/RF24)

## Components for a remote controller:
- Arduino Nano Every
- NRF24L01
- Adapter for NRF24L01
- 2 x Joystick
- jumpers
- powerbank for powering Arduino

## Components for a car:
- Arduino UNO
- NRF24L01
- Adapter for NRF24L01
- DC/DC converter XL4015 5A
- Motor driver L298N
- 2 x batteries 18650
- 4 x motors
- jumpers
- 4 x wheels
- chassis

## How to set up the car and controller:
1) build the car
2) set DC/DC converter's output voltage to 5V
3) build the remote controller
4) upload the sketch car.ino to the car
5) upload the sketch controller.ino to the controller
6) power the car by 18650 battaries
7) power the remote controller by powerbank

  
Max RC working distance: 160 meters
Max video transmitting distance: 15 meters

--------------------------------------------------

# Description of XL4015

The XL4015 adjustable step-down DC-DC converter module is equipped with a digital display unit – voltmeter + ammeter + wattmeter.
The display features a three-digit LED indicator, seven-segment with a dot, red color, and a symbol height of 9mm.
For charging mobile devices, the XL4005 step-down converter module board includes a USB port.
Additionally, the XL4005 adjustable step-down converter module board has LED indicators:

Input-output voltage display mode
Current limit indicator
Charging indicator
Charging complete indicator
The XL4015 step-down adjustable converter allows users to calibrate the voltmeter and ammeter readings if desired.
The XL4015 step-down adjustable converter is designed to provide an output voltage from 1.25 to 32 volts.
The XL4015 step-down voltage converter with a voltmeter, ammeter, and wattmeter is capable of delivering up to 5 amps of current with adjustable control.
This step-down converter is useful for hobbyists when building a DIY laboratory power supply.
The adjustable power supply device uses the XL4015 chip, which includes built-in protection against short circuits, overheating, and output current limitation.

Specifications:

Input voltage: from 8 to 36 volts
Output voltage: from 1.25 to 32 volts (adjustable)
Output current: up to 5A
Fixed conversion frequency: 180KHz
Converter chip: XL4015
Protection: short circuit, overheating, output current limitation
Operating temperature: -40°C to +85°C
Efficiency: 96%
Dimensions: 54 x 23 x 15 mm

---
# Description of NRF24L01
The NRF24L01P+ wireless module with an amplifier and external antenna operates on an unlicensed frequency of 2.4GHz and can work at distances up to 1100 meters. Each module can be programmed as a receiver or transmitter, and it also allows building star-type networks. The module is compact (45.54 x 16.46 mm) and is controlled via the SPI protocol.

Manufacturer code: NF-02-PA-SMA

Note: The modules use standard pinout. Do not rely on secondary markings (the pinout on the modules themselves may be incorrectly labeled).

Specifications:

Transmission power over +20 dBm, 50Ω, supports seven-channel reception, data rate up to 2 Mbps
Operating voltage: 2.7 - 3.6V, but control pins are 5V tolerant (i.e., powered by up to 3.6V, but can connect control pins directly to Arduino)
Multi-frequency points: 125 frequency points
Supports retransmission of lost packets
Operating frequency: 2400 - 2524 MHz
Modulation: GMSK
Receiver sensitivity: -95 dBm
Maximum transmission current: 115 mA
Maximum reception current: 45 mA
Operating temperature range: industrial standard -45 to +85°C
PA gain: 20 dB
LNA gain: 10 dB The module has a standard pinout, allowing it to be connected to Arduino boards that have an NRF24L01P+ module socket or simply to the SPI interface of an Arduino board.

Pin	Description	Direction
Pin1	GND	Ground
Pin2	VCC	Power, 2.7~3.6V
Pin3	CE	Mode, RX/TX
Pin4	CSN	SPI chip select
Pin5	SCK	SPI clock
Pin6	MOSI	SPI input
Pin7	MISO	SPI output
Pin8	IROAM	Interrupt output

Datasheet: https://arduino.ua/docs/nRF24L01P_Product_Specification_1_0.pdf
Library: https://github.com/gcopeland/RF24

-----
