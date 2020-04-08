#include <UnipolarStepper.h>

const int stepsPerRevolution = 4095;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
UnipolarStepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution/14);
  delay(1000);
}
