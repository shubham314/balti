/*
/4/20
Author Shubham panchal

project structure
    init of all parts
    setup
    each functions
    main function

*/

#include <Servo.h>
#include <UnipolarStepper.h>

#define servo_pin 6
#define stepper_dir_pin 4
#define stepper_step_pin 3
#define lidar_pwm_pin 9
#define lidar_trig_pin 8  //needs to be defined

int pos = 30;
const int unipolar_steps = 4095;  // change this to fit the number of steps per revolution
unsigned long pulse_width;
unsigned long distance1;

int delta = 30;
int delayStep = 500;
int stepInt  = 200;
int step1;

Servo myservo;
UnipolarStepper myStepper(unipolar_steps, 8, 9, 10, 11);

void setup()
{
    Serial.begin(115200);
    myservo.attach(servo_pin);
    pinMode(lidar_trig_pin, OUTPUT); // Set pin 2 as trigger pin
    pinMode(lidar_trig_pin, INPUT); // Set pin 3 as monitor pin
    pinMode(stepper_dir_pin,OUTPUT);
    pinMode(stepper_step_pin,OUTPUT);
    digitalWrite(lidar_trig_pin,LOW);
}

int lidar()
{
  pulse_width = pulseIn(lidar_pwm_pin, HIGH); // Count how long the pulse is high in microseconds
  if(pulse_width != 0){ // If we get a reading that isn't zero, let's print it
        pulse_width = pulse_width/10; // 10usec = 1 cm of distance for LIDAR-Lite
    //Serial.println(pulse_width); // Print the distance
  delay(1); //Delay so we don't overload the serial port
 }
 //Serial.print(pulse_width);
 //Serial.print("\t");
 return pulse_width;
}


int stepper_func()
{
  for(int i =0;i<stepInt;i++)
  {
    digitalWrite(stepper_dir_pin,HIGH); 
    digitalWrite(stepper_step_pin,HIGH);
    delayMicroseconds(delayStep);
    digitalWrite(stepper_step_pin,LOW);
    delayMicroseconds(delayStep);   

    step1 = i;
    distance1=60;// lidar();
    
Serial.print(step1);
Serial.print(",");
Serial.print(pos);
Serial.print(",");
Serial.println(distance1);

delay(50);
  if (i==199)
    {
pos=pos+delta;
      i = 0;
      if(pos >129||pos<20)
        {delta =-delta;}
      myservo.write(pos);

    }
 
}

}


void loop()
{
stepper_func();
}



