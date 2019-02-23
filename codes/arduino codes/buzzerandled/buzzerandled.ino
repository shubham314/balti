// buzzer and led code fro the board
// may be in he main file

#define buzzer 4
#define red 5
#define green 6

void setup()
{
    pinMode(buzzer,OUTPUT);
    pinMode(red,OUTPUT);
    pinMode(green,OUTPUT);

}

// function for the led

void indicators()
{
    digitalWrite(buzzer,HIGH);
    digitalWrite(red,HIGH);
    digitalWrite(green,HIGH);
}

void loop()
{
  indicators();
}
