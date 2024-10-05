#include <SPI.h>
#include <RF24.h>
#include <L298NX2.h>

const int RF24_CE = 7;
const int RF24_CSN = 8;

const int EN_A = 9;
const int IN1_A = 3;
const int IN2_A = 4;

const int EN_B = 10;
const int IN1_B = 5;
const int IN2_B = 6;

const int COMMAND_EXECUTION_INTERVAL = 150;

const byte radio_address[6] = "99999";
RF24 radio(RF24_CE, RF24_CSN);

// Initialize both motors
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

unsigned long lastCommandTimestamp = 0;

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
  
  radio.setAutoAck(false); // non-original NRF24 modules work only with disabled auto-ack

  radio.setPALevel(RF24_PA_MAX);

  radio.setPayloadSize(sizeof(commandStruct));

  radio.openReadingPipe(1, radio_address);

  radio.startListening();

  // For debugging info
  //printf_begin();             // needed only once for printing details
  //radio.printDetails();       // (smaller) function that prints raw register values
  //radio.printPrettyDetails(); // (larger) function that prints human readable data
}


struct commandStruct command;

struct commandStruct receiveNextCommand() {
    struct commandStruct command;

    radio.read(&command, sizeof(command));

    return command;
}

void loop() {
    if (radio.available()) {

      struct commandStruct nextCommand = receiveNextCommand();

      lastCommandTimestamp = millis();
        
      motors.setSpeedB(nextCommand.leftSpeed);

      Serial.print(" speedB: ");
      Serial.print(nextCommand.leftSpeed);
      Serial.print(" ");
      Serial.print(nextCommand.leftForward);

      if (nextCommand.leftForward) {
        motors.forwardB();
      } else {
        motors.backwardB();
      }

      motors.setSpeedA(nextCommand.rightSpeed);

      Serial.print(" speedA: ");
      Serial.print(nextCommand.rightSpeed);
      Serial.print(" ");
      Serial.print(nextCommand.rightForward);

      if (nextCommand.rightForward) {
        motors.forwardA();
      } else {
        motors.backwardA();
      }

      Serial.println();
    }
  if (millis() - lastCommandTimestamp > COMMAND_EXECUTION_INTERVAL) {
    Serial.println("STOP");
    motors.stop();
  }
}
