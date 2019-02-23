// main code in a single file 

//  bipolar stepper code 
// the changable values
#define stepPin 3
#define dirPin 4
#define stepInt 200
#define delayStep 50

//unipolar stepper code

#define pin1 8
#define pin2 9
#define pin3 10
#define pin4 11
#define unipolarDelay 10

//buzzer and led

#define buzzer 4
#define red 5
#define green 6

// servo motor codes
// dependent libraries
#include<Servo.h>

// changable are for the code
#define servoPin1 9
#define servoPin2 10
#define servoPin3 11
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
Servo servo1;
Servo servo2;
Servo servo3;

// lidar codes
int lidarPin1  = 2;  // the pin for low values
int lidarPin2 = 3; // the pin fro the pwm

unsigned long pulseWidth;


void setup()
{
    // bipolar
    pinMode(stepPin,OUTPUT);
    pinMode(dirPin,OUTPUT);

    //unipolar
    pinMode(pin1,OUTPUT);
    pinMode(pin2,OUTPUT);
    pinMode(pin3,OUTPUT);
    pinMode(pin4,OUTPUT);

    // buzzer and led
    pinMode(buzzer,OUTPUT);
    pinMode(red,OUTPUT);
    pinMode(green,OUTPUT);

    // servo motor
servo1.attach(servoPin1);
servo2.attach(servoPin2);
servo3.attach(servoPin3);

  Serial.begin(115200); // Start serial communications
  pinMode(lidarPin1, OUTPUT); // Set pin 2 as trigger pin
  digitalWrite(lidarPin1, LOW); // Set trigger LOW for continuous read
  pinMode(lidarPin2, INPUT); // Set pin 3 as monitor pin

}


void bipolarStepper()
{
digitalWrite(dirPin,HIGH);

for(int i =0;i<stepInt;i++)
{
    digitalWrite(stepPin,HIGH);
    delay(delayStep);
    digitalWrite(stepPin,LOW);
    delay(delayStep);
    
}
}


void unipolarStepper()
{
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    delay(unipolarDelay);

    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    delay(unipolarDelay);

    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    delay(unipolarDelay);

    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    delay(unipolarDelay);

}



void indicators()
{
    digitalWrite(buzzer,HIGH);
    digitalWrite(red,HIGH);
    digitalWrite(green,HIGH);
}

void baltiServo()
{
    servo1.write(pos1);
    servo2.write(pos2);
    servo3.write(pos3);
}

void loop()
{
baltiServo();
indicators();
unipolarStepper();
bipolarStepper();
}
