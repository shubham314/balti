//  bipolar stepper code 
// the changable values



/*#define stepPin1 14
#define dirPin1 15

#define stepPin2 16
#define dirPin2 17*/
int delayStep = 50;


class StepperBi{
	public :
int stepPin;
	int dirPin;	
	int directions;
	int steps;     
	
	int getBipolarStepper(void);
void setStepPin(int sp);
void setDirPin(int dp);	
	void setdirections(int dn);
	void setSteps(int st);
	
};
void StepperBi::setdirections(int dn){	directions=dn;}
void StepperBi::setSteps(int st){	steps=st;}

int StepperBi::getBipolarStepper(void)
{
	if (directions ==1){
		digitalWrite(dirPin1,HIGH);
	}
	else if (directions ==2)
		
	{
		digitalWrite(dirPin1,LOW);	
	}
	else if (directions ==3){
		digitalWrite(dirPin2,HIGH);
	}
	else{
		digitalWrite(dirPin2,LOW);	
	}
	
	int stepInt  = steps;
	
	for(int i =0;i<stepInt;i++)
	{
		digitalWrite(stepPin1,HIGH);
		delay(delayStep);
		digitalWrite(stepPin1,LOW);
		delay(delayStep);   
	}
	return 0;
}

void StepperBi::setStepPin(int sp){stepPin=sp;}
void StepperBi::setDirPin(int dp){dirPin=dp;}



void setup()
{
	
Serial.begin(9600);
	
}

void loop()
{
	
	StepperBi stepper1;
	StepperBi stepper2;

int stepPin1 =   stepper1.setStepPin(14);
int dirPin1 =    stepper1.setDirPin(15);
int stepPin2 =   stepper2.setStepPin(16);
int dirPin2 =     stepper2.setDirPin(17);

        pinMode(stepPin1,OUTPUT);
	pinMode(dirPin1,OUTPUT);
	pinMode(stepPin2,OUTPUT);
	pinMode(dirPin2,OUTPUT);
   
	stepper1.setdirections(1);
	stepper1.setSteps(20);
	
	stepper2.setdirections(0);
	stepper2.setSteps(20);

	stepper1.getBipolarStepper();
	stepper2.getBipolarStepper();
	delay(3000);
	
	
	
}`