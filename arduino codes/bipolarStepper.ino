//  bipolar stepper code 
// the changable values



#define stepPin1 14
#define dirPin1 15

#define stepPin2 16
#define dirPin2 17


int delayStep = 50;
int stepInt  = 0;
void setup()
{
	pinMode(stepPin1,OUTPUT);
	pinMode(dirPin1,OUTPUT);
	pinMode(stepPin2,OUTPUT);
	pinMode(dirPin2,OUTPUT);
}



int bipolarStepper1(int drpn, int step)
{
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
	bipolarStepper1(0,10);
	delay(3000);
	bipolarStepper2(1,20);
delay(2000);
}