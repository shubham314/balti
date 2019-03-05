//  bipolar stepper code 
// the changable values



#define stepPin1 14
#define dirPin1 15

#define stepPin2 16
#define dirPin2 17

// dependent libraries
#include<Servo.h>

// changable are for the code
#define servoPin1 9
#define servoPin2 10
#define servoPin3 11

Servo servo1;
Servo servo2;
Servo servo3;
int pos1 =10;
int pos2 = 30;
int pos3 = 45;
int delta = 30;

int delayStep = 50;
int stepInt  = 0;

String a ;
String b ;
void setup()
{
	pinMode(stepPin1,OUTPUT);
	pinMode(dirPin1,OUTPUT);
	pinMode(stepPin2,OUTPUT);
	pinMode(dirPin2,OUTPUT);
		servo1.attach(servoPin1);
	servo2.attach(servoPin2);
	servo3.attach(servoPin3);
    Serial.begin(9600);	

}

String serRead(void)
        {// send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                a = Serial.readStringUntil(',');
                b = Serial.readStringUntil('\0');

 				// convert string to int
 				int aa = a.toInt();
 				int bb = b.toInt();
 				int cc = aa+bb;
 				Serial.println(cc);
         return a ;    
        }
}
int bipolarStepper1(int drpn, int step)
{
	// for direction 
	if (drpn ==1){
	digitalWrite(dirPin1,HIGH);
	}
	else{
	digitalWrite(dirPin1,LOW);	
	}
 stepInt = step;

	for(int i =0;i<stepInt;i++)
	{
		digitalWrite(stepPin1,HIGH);
		delay(delayStep);
		digitalWrite(stepPin1,LOW);
		delay(delayStep);   

		serRead();
	}

	if (step>19)
		{pos1=pos1+delta;
			step = 0;

			if(pos1 >159||pos1<20)
				{delta =-delta;}
			servo1.write(pos1);
		}
	return 0;
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


void loop()
{

	bipolarStepper1(0,20);
	
}