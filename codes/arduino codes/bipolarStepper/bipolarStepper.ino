//  bipolar stepper code 
// the changable values
#define stepPin 3
#define dirPin 4
#define stepInt 200
#define delayStep 50

void setup()
{
    pinMode(stepPin,OUTPUT);
    pinMode(dirPin,OUTPUT);
}

// write class for the program

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


void loop()
{
  bipolarStepper();
}
