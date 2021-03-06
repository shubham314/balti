#define IN1  10
#define IN2  11    
#define IN3  12
#define IN4  13  
int Steps = 0;
boolean Direction = true;
unsigned long last_time1=0;
long currentMillis=0 ;
int steps_left=4095;
long time1=0;
void setup()
{
	Serial.begin(9600);
	pinMode(IN1, OUTPUT); 
	pinMode(IN2, OUTPUT); 
	pinMode(IN3, OUTPUT); 
	pinMode(IN4, OUTPUT); 
	// delay(1000);
	
}
void loop()
{
	while(steps_left>0){
		currentMillis = micros();
		if(currentMillis-last_time1>=1000){
			stepper(1); 
			time1=time1+micros()-last_time1;
			last_time1=micros();
			steps_left--;
		}
	}
	Serial.println(time1 );
	Serial.println("Wait...!");
	delay(1000);
	Direction=!Direction;
	steps_left=4095;
}

void stepper(int xw){
	for (int x=0;x<xw;x++){
		switch(Steps){
			case 0:
				digitalWrite(IN1, LOW); 
				digitalWrite(IN2, LOW);
				digitalWrite(IN3, LOW);
				digitalWrite(IN4, HIGH);
				break; 
			case 1:
				digitalWrite(IN1, LOW); 
				digitalWrite(IN2, LOW);
				digitalWrite(IN3, HIGH);
				digitalWrite(IN4, HIGH);
				break; 
			case 2:
				digitalWrite(IN1, LOW); 
				digitalWrite(IN2, LOW);
				digitalWrite(IN3, HIGH);
				digitalWrite(IN4, LOW);
				break; 
			case 3:
				digitalWrite(IN1, LOW); 
				digitalWrite(IN2, HIGH);
				digitalWrite(IN3, HIGH);
				digitalWrite(IN4, LOW);
				break; 
			case 4:
				digitalWrite(IN1, LOW); 
				digitalWrite(IN2, HIGH);
				digitalWrite(IN3, LOW);
				digitalWrite(IN4, LOW);
				break; 
			case 5:
				digitalWrite(IN1, HIGH); 
				digitalWrite(IN2, HIGH);
				digitalWrite(IN3, LOW);
				digitalWrite(IN4, LOW);
				break; 
			case 6:
				digitalWrite(IN1, HIGH); 
				digitalWrite(IN2, LOW);
				digitalWrite(IN3, LOW);
				digitalWrite(IN4, LOW);
				break; 
			case 7:
				digitalWrite(IN1, HIGH); 
				digitalWrite(IN2, LOW);
				digitalWrite(IN3, LOW);
				digitalWrite(IN4, HIGH);
				break; 
			default:
				digitalWrite(IN1, LOW); 
				digitalWrite(IN2, LOW);
				digitalWrite(IN3, LOW);
				digitalWrite(IN4, LOW);
				break; 
		}
		SetDirection();
	}
} 
void SetDirection(){
	if(Direction==1){	Steps++;}
	if(Direction==0){	Steps--; }
	if(Steps>7){	Steps=0;}
	if(Steps<0){	Steps=7; }
}