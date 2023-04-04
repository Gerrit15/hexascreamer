#include "IRremote.hpp"
// #include <AccelStepper.h>

int IR_RECEIVE_PIN = 12;

// #define HALFSTEP 8
// #define motorPin1  3     // IN1 on the ULN2003 driver 1
// #define motorPin2  4     // IN2 on the ULN2003 driver 1
// #define motorPin3  5     // IN3 on the ULN2003 driver 1
// #define motorPin4  6     // IN4 on the ULN2003 driver 1

// AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  // stepper1.setMaxSpeed(2100);
  // stepper1.setAcceleration(50);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
  // stepper1.runSpeed();
  if (IrReceiver.decode()) {
      /* USE NEW 3.x FUNCTIONS */
      IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
      IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
      // Serial.println();
      if (IrReceiver.decodedIRData.command == 0x2) {
        digitalWrite(6, HIGH);
      } else if (IrReceiver.decodedIRData.command == 0x0) {
        digitalWrite(6, LOW);
      }
      // if (IrReceiver.decodedIRData.command == 0x44) {
      //     stepper1.setSpeed(500);
      //   } else if (IrReceiver.decodedIRData.command = 0x43) {
      //       stepper1.setSpeed(-500);
      //     }
      IrReceiver.resume(); // Enable receiving of the next value
  }
}
