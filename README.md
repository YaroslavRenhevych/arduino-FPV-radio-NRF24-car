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
- FPV camera Radiolink 800TVL
- Fan 40x40mm 5V
- any analog FPV goggles
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

- Transmission power over +20 dBm, 50Ω, supports seven-channel reception, data rate up to 2 Mbps
- Operating voltage: 2.7 - 3.6V, but control pins are 5V tolerant (i.e., powered by up to 3.6V, but can connect control pins directly to Arduino)
- Multi-frequency points: 125 frequency points
- Supports retransmission of lost packets
- Operating frequency: 2400 - 2524 MHz
- Modulation: GMSK
- Receiver sensitivity: -95 dBm
- Maximum transmission current: 115 mA
- Maximum reception current: 45 mA
- Operating temperature range: industrial standard -45 to +85°C
- PA gain: 20 dB
- LNA gain: 10 dB

  
The module has a standard pinout, allowing it to be connected to Arduino boards that have an NRF24L01P+ module socket or simply to the SPI interface of an Arduino board.

| Pin	 |        | Description     |Direction|
|------|--------|-----------------|---------|
| Pin1 |	GND	  | Ground          |         |
| Pin2 |	VCC	  | Power, 2.7~3.6V |         |
| Pin3 |	CE    | Mode, RX/TX     |input    |
| Pin4 |	CSN	  | SPI chip select |input    |
| Pin5 |	SCK   | SPI clock       |input    |
| Pin6 |	MOSI  | SPI input       |input    |
| Pin7 |	MISO  | SPI output      |output   |
| Pin8 |	IROAM | Interrupt output|output   |

Datasheet: https://arduino.ua/docs/nRF24L01P_Product_Specification_1_0.pdf

Library: https://github.com/gcopeland/RF24

-----
# Description of NRF24L01 Adapter
The connection module allows convenient use of NRF24L01 receivers with 5V systems, such as Arduino.

It includes a voltage regulator that converts 5V input to 3.3V output and also contains decoupling capacitors for reliable operation. Dimensions: 18x26x10 mm.

---

# Description of FPV camera with analog transmitter Radiolink 800TVL
The ultra-miniature high-definition video camera with a 5.8 GHz transmitter is an ideal solution for building miniature FPV drones. The camera stands out from similar FPV video cameras with its high image quality, increased output power, ultra-miniature design, and simple one-button control for settings.

The camera connects to the power source via a single PH1.25 connector. The power voltage value is displayed in the telemetry.

For convenient installation on the drone, the camera features an image flip function, allowing a 180-degree rotation.

Features:

- 800TVL micro camera with a 5.8 GHz transmitter and on-screen menu

- Super mini size and lightweight

- Image flip function support

- 2 LEDs, 1 button

Specifications:

- Telemetry content: image transmission, working frequency, power supply voltage

- Transmission frequency: 5.8 GHz, 48 channels, 6 bands

- Camera resolution: 800 TVL (720P)

- Transmission power: adjustable, 25 mW / 100 mW / 200 mW (default 25 mW)

- Power supply voltage: from 3V to 5.2V DC

- Current consumption (at 4.2V): 320 mA (25 mW output), 400 mA (100 mW), 460 mA (200 mW)

- Video system: PAL

- Viewing angle: 150°

- Focal length: 1.2 mm

- Aspect ratio: 4:3

- Power:
  - Wire: 28AWG
  - Connector: PH1.25

- Size: 18.03 x 16.83 x 16.55 mm

- Weight: 4.4 g

- Frequency, channel, and band table: see in folder pictures/

- Camera configuration:

Switching frequency:

1. Press and hold the button for 5 seconds, the red LED will blink once to enter frequency switching mode.
2. Briefly press once to change the frequency from 1 to 8.
3. The blue LED blinks once for frequency 1, twice for frequency 2, and so on.

Switching bands:

1. Press and hold the button for 5 seconds, the red LED will blink twice to enter band switching mode.
2. Briefly press once to change the band from 1 to 6.
3. The blue LED blinks once for band 1, twice for band 2, and so on.

Switching transmission power:

1. Press and hold the button for 5 seconds, the red LED will blink three times to enter power switching mode.
2. Briefly press once to change the transmission power; AF is adjustable.
3. The blue LED blinks once to indicate 25 mW, twice for 100 mW, and three times for 200 mW. The higher the power, the greater the transmission range.
Note: The default transmission power is set to 25 mW due to legal restrictions and power consumption considerations. Please switch as needed.

Switching transmission mode:

1. Normal operation mode: The red and blue LEDs are steadily lit.
2. Low-power modulation mode (Pitmode): The red LED is lit, and the blue LED is off. In this mode, the transmission range is 1-2 meters.
3. Briefly press the button twice to switch modes.
Note: After setting all parameters, press and hold the button, and the red and blue LEDs will indicate entry into save mode, followed by working mode. Otherwise, the module will not exit the setup state and will not save the configured parameters.

---
