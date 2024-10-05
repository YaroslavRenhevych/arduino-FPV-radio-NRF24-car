#include <SPI.h>
#include <RF24.h>

const int RF24_CE = 7;
const int RF24_CSN = 8;

const int leftJoystickVrxPin = A0;
const int rightJoystickVrxPin = A1;

const int LEFT_JOYSTICK_CENTER_VALUE = 510;
const int RIGHT_JOYSTICK_CENTER_VALUE = 506;

const byte radio_address[6] = "99999";

RF24 radio(RF24_CE, RF24_CSN);

struct commandStruct {
  bool leftForward;
  byte leftSpeed;
  bool rightForward;
  byte rightSpeed;
};

void setup() {
  Serial.begin(115200);

  Serial.print("radio.begin: ");
  Serial.println(radio.begin());

  while (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
  }
  
  radio.setAutoAck(false); // non-original NRF24 modules do not work with enabled auto-ack

  radio.setPALevel(RF24_PA_MAX);

  radio.setPayloadSize(sizeof(commandStruct));

  radio.openWritingPipe(radio_address);

  radio.stopListening();

  // For debugging info
  //printf_begin();             // needed only once for printing details
  //radio.printDetails();       // (smaller) function that prints raw register values
  //radio.printPrettyDetails(); // (larger) function that prints human readable data
}



struct commandStruct command;

void loop() {

  int leftThrottle = analogRead(leftJoystickVrxPin);
  int rightThrottle = analogRead(rightJoystickVrxPin);

  Serial.print("LeftThrottle: ");
  Serial.print(leftThrottle);

  Serial.print("; RightThrottle: ");
  Serial.print(rightThrottle);

  Serial.print(" Connected. Command: ");

  if (leftThrottle >= LEFT_JOYSTICK_CENTER_VALUE) {
    command.leftForward = false;
    command.leftSpeed = map(leftThrottle, LEFT_JOYSTICK_CENTER_VALUE, 1023, 0, 255);
  } else {
    command.leftForward = true;
    command.leftSpeed = map(leftThrottle, LEFT_JOYSTICK_CENTER_VALUE, 0, 0, 255);
  }

  Serial.print(command.leftForward);
  Serial.print(" ");
  Serial.print(command.leftSpeed);

  if (rightThrottle >= RIGHT_JOYSTICK_CENTER_VALUE) {
    command.rightForward = false;
    command.rightSpeed = map(rightThrottle, RIGHT_JOYSTICK_CENTER_VALUE, 1023, 0, 255);
  } else {
    command.rightForward = true;
    command.rightSpeed = map(rightThrottle, RIGHT_JOYSTICK_CENTER_VALUE, 0, 0, 255);
  }

  Serial.print(" | ");
  Serial.print(command.rightForward);
  Serial.print(" ");
  Serial.print(command.rightSpeed);

  bool report = radio.write(&command, sizeof(command));
  delay(50);

  Serial.println();
}
