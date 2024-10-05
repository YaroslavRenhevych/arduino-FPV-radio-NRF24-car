# arduino-FPV-radio-NRF24-car
FPV car with radio remote controller based on Arduino and NFR24 modules.

Communication technology: radio

Libraries:
- https://github.com/AndreaLombardo/L298N
- RF24 by TMRh20 https://www.arduino.cc/reference/en/libraries/rf24/ (https://github.com/nRF24/RF24)

Components for a remote controller:
- Arduino Nano Every
- NRF24L01
- Adapter for NRF24L01
- 2 x Joystick
- jumpers
- powerbank for powering Arduino

Components for a car:
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

How to set up the car and controller:
1) build the car
2) set DC/DC converter's output voltage to 5V
3) build the remote controller
4) upload the sketch car.ino to the car
5) upload the sketch controller.ino to the controller
6) power the car by 18650 battaries
7) power the remote controller by powerbank

  
Max RC working distance: 160 meters
Max video transmitting distance: 15 meters
