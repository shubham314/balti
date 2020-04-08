
//make a pin layout of the machine here

#define stepPin1 14
#define dirPin1 15

#define stepPin2 16
#define dirPin2 17

// dependent libraries
#include<Servo.h>
#include <UnipolarStepper.h>

const int stepsPerRevolution = 4095;  // change this to fit the number of steps per revolution
// for your motor

#define servoPin1 9
#define servoPin2 10
#define servoPin3 11
int step1,pos1 = 0;
int step2, dir2,pos2 = 0;
int ir1 = 12;
ir2 = 19;
// red and green leds are replaced by ir1 and ir2 for finding origin
String a ;
Servo servo1;
Servo servo2;
Servo servo3;
  int trigpin = 3;
  int lidarpwmpin = 2;  //pwm
unsigned long pulse_width;
unsigned long distance1;

// initialize the stepper library on pins 8 through 11:
UnipolarStepper myStepper(stepsPerRevolution, 8, 9, 10, 11);



int delta = 30;

int delayStep = 50;
int stepInt  = 200;

void setup()
{   pinMode(trigpin, OUTPUT); // Set pin 2 as trigger pin
    pinMode(lidarpwmpin, INPUT); // Set pin 3 as monitor pin
	pinMode(stepPin1,OUTPUT);
	pinMode(dirPin1,OUTPUT);
	pinMode(stepPin2,OUTPUT);
	pinMode(dirPin2,OUTPUT);
	pinMode(ir1,INPUT);  //top deck
	pinMode(ir2,INPUT);  //middle deck
		servo1.attach(servoPin1);
	servo2.attach(servoPin2);
	servo3.attach(servoPin3);
    Serial.begin(9600);	
    Serial.setTimeout(20);

}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

 
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";


}

int bipolarStepper1()
{


	for(int i =0;i<stepInt;i++)
	{
		digitalWrite(stepPin1,HIGH);
		delay(delayStep);
		digitalWrite(stepPin1,LOW);
		delay(delayStep);   

	  step1 = i;
	  distance1= lidar();
	if (i>19)
		{pos1=pos1+delta;
			i = 0;

			if(pos1 >159||pos1<20)
				{delta =-delta;}
			servo1.write(pos1);

		}
}  return step1,distance1;
}



int bipolarStepper2(int drpn, int step)
{
	if (drpn ==1){
	digitalWrite(dirPin2,HIGH);
	}
	else{
	digitalWrite(dirPin2,LOW);	
	}
 stepInt = step;

	for(int i =0;i<stepInt;i++)
	{
		digitalWrite(stepPin2,HIGH);
		delay(delayStep);
		digitalWrite(stepPin2,LOW);
		delay(delayStep);   
	}
	return 0;
}


int lidar()
{
  pulse_width = pulseIn(lidarpwmpin, HIGH); // Count how long the pulse is high in microseconds
  if(pulse_width != 0){ // If we get a reading that isn't zero, let's print it
        pulse_width = pulse_width/10; // 10usec = 1 cm of distance for LIDAR-Lite
    //Serial.println(pulse_width); // Print the distance
  delay(1); //Delay so we don't overload the serial port
 }
 return pulse_width;
}

void loop()
{
int ir1State = digitalRead(ir1);
int ir2State = digitalRead(ir2);

if(ir1State==0)
{
	// bipolar stepper  ko move karna he ek direction me

	bipolarStepper1();
}

else
{

//serial write format step1,pos1,distance1;  20,65,122;
  Serial.println((step1,",",pos1,",",distance1));


}


if(ir2State==0)
{	//unipolar ko move karna he ek direction me
    
  myStepper.step(step2);
}

if(ir1State==0&&ir2State==1)
{

bipolarStepper1();
 myStepper.step(0);
}

if(ir1State==1&&ir2State==0 )
{
//bipolarStepper1();
 myStepper.step(step2);

}

if(ir1State==1&&ir2State==1)
{

if (Serial.available() > 0) {

a = Serial.readString(); // read the incoming byte:

Serial.println(a);

}
//serial read format 35,1,90,  where 35 = step2, 1 = dir2, 90 = pos2
  String part01 = getValue(a,';',0);
  String part02 = getValue(a,';',1);
  String part03 = getValue(a,';',2);
  step2 = part01.toInt(); 
  dir2 = part02.toInt();
  pos2 = part03.toInt();
 
if (dir2 ==1)
 {
step2= -stepsPerRevolution/14;	
//  myStepper.step(-stepsPerRevolution/14);

 }
 else if(dir2 ==0)
 	{step2 = stepsPerRevolution;}

  myStepper.step(step2);
  servo2.write(pos2);


}
}