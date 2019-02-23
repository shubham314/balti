// unipolar stepper code for balti
// changable area for values

#define pin1 8
#define pin2 9
#define pin3 10
#define pin4 11
#define unipolarDelay 10

void setup()
{
    pinMode(pin1,OUTPUT);
    pinMode(pin2,OUTPUT);
    pinMode(pin3,OUTPUT);
    pinMode(pin4,OUTPUT);
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

void loop()
{
unipolarStepper();

}
