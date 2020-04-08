#include <UnipolarStepper.h>

const int stepsPerRevolution = 4095;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
UnipolarStepper firstStepper(stepsPerRevolution, 8, 9, 10, 11);
UnipolarStepper secondStepper(stepsPerRevolution, 4, 5, 6, 7);

void setup() {
}

void loop() {

  for(int s=0; s<stepsPerRevolution; s++)
  {
   //the motors are never really synchronous but this is a good workaround
   firstStepper.step(1);
   secondStepper.step(1);
  }
  
}
