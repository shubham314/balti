// buzzer and led code fro the board
// may be in he main file

#define buzzer 18
#define red 12
#define green 19

void setup()
{
    pinMode(buzzer,OUTPUT);
    pinMode(red,OUTPUT);
    pinMode(green,OUTPUT);

}

// function for the led

int indicators(int r,int g ,int b)
{
	if(r >5){
    digitalWrite(red,HIGH);
    }
    else if(g >6)
    	{digitalWrite(green,HIGH);}
    else if(b >7){
    digitalWrite(buzzer,HIGH);}
    return 0;
}

void loop()
{
  indicators(6,5,8);
  delay(1000);
  indicators(4,7,1);
  delay(1000);
}
