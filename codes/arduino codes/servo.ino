// code for the servo for the balti

// dependent libraries
#include<Servo.h>

// changable are for the code
#define servoPin1 9
#define servoPin2 10
#define servoPin3 11

Servo servo1;
Servo servo2;
Servo servo3;

void setup()
{
	servo1.attach(servoPin1);
	servo2.attach(servoPin2);
	servo3.attach(servoPin3);
    Serial.begin(9600);	
}



	servo1.write(pos1);
	servo2.write(pos2);
	servo3.write(pos3);
	

void loop()
{

}
