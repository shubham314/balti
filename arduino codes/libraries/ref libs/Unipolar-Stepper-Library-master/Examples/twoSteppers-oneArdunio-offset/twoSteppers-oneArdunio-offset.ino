/* in this sketch we have two motors doing one revolution at
 *  two different speed
 *  !!!!!!doesn't work that well!!!!!
 */
#include <UnipolarStepper.h>

const int stepsPerRevolution = 4095;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
UnipolarStepper firstStepper(stepsPerRevolution, 8, 9, 10, 11);
UnipolarStepper secondStepper(stepsPerRevolution, 4, 5, 6, 7);

float step1Inc;
float step2Inc; 

void setup() {

  // initialize the serial port:
  Serial.begin(9600);
  step1Inc =  90.0/360.0;
  step2Inc = 360.0/360.0;
}

void loop() {
  
  float step1Pos = 0.0;
  float step2Pos = 0.0;

  for(int i=0; i<4095; i++)
  {
    
    firstStepper.step((int)step1Pos);
    secondStepper.step((int)step2Pos);    
    
    step1Pos += step1Inc;
    step2Pos += step2Inc;
  }
}
