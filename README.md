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

