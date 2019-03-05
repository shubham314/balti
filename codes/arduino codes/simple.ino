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

int j ,k,l,m = 0;
String a ;
Servo servo1;
Servo servo2;
Servo servo3;
int pos1 =10;
int pos2 = 30;
int pos3 = 45;
int delta = 30;

int delayStep = 50;
int stepInt  = 0;

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
	
	
	//  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
	
	
	return /*found>index ?*/data.substring(strIndex[0], strIndex[1]) /*: ""*/;
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
		
	}
	
	if (step>19)
	{	pos1=pos1+delta;
		step = 0;
		
		if(pos1 >159||pos1<20)
		{	delta =-delta;}
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
	

	
	if (Serial.available() > 0) {
		
		a = Serial.readString(); // read the incoming byte:
		
		Serial.println(a);}
	Serial.println("coming strings are :");
	String part01 = getValue(a,';',0);
	String part02 = getValue(a,';',1);
	j = part01.toInt(); 
	k = part02.toInt();
	m = j+k;
	Serial.print("m is   :");
	Serial.println(m);
	servo2.write(m);
		bipolarStepper1(0,20);
	
}