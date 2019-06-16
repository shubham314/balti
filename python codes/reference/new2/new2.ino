#include <Servo.h>

Servo myservo;
  int lidarpin1 = 4;
  int lidarpin2 = 3;  //pwm
unsigned long pulse_width;
int pos = 0;
const int stepPin = 6; 
const int dirPin =7; 
int x = 0;
int a = 10;
int l = 0;
void setup()
{
  Serial.begin(115200); // Start serial communications
  pinMode(lidarpin1, OUTPUT); // Set pin 2 as trigger pin
  pinMode(lidarpin2, INPUT); // Set pin 3 as monitor pin
    // Set pin 4 to control power enable line
   //Turn sensor on
  digitalWrite(2, LOW); // Set trigger LOW for continuous read
myservo.attach(5);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  myservo.write(0);
   Serial.flush();
   
}

void lidar(){
  pulse_width = pulseIn(lidarpin2, HIGH); // Count how long the pulse is high in microseconds
  if(pulse_width != 0){ // If we get a reading that isn't zero, let's print it
        pulse_width = pulse_width/10; // 10usec = 1 cm of distance for LIDAR-Lite
     // Print the distance
    delay(10);
 
  }
}
  void step1()
  {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for( x = 0; x < 423; x++) {
    digitalWrite(stepPin,HIGH); 
    lidar();
 
    delay(500); 
    digitalWrite(stepPin,LOW); 
   lidar();
   
   //Serial.print("'");
   Serial.print(pulse_width);
   Serial.print(" , ");
   Serial.print(x);  
   Serial.print(" , ");
   Serial.print(pos);
   Serial.print(" , ");
   Serial.println(l);
   delay(500); 
    
  } 
     if(x=425)
    {
      l = l+1;
      if(l>9)
      {l = 0;
        }
     //pos = pos + a; 
    }
    if (pos == 90 || pos == 0)
      { a = -a ;
      }
       myservo.write(70);
      
    
}

  
void loop()
{  
 
  step1();
  //delay(10000);
 
}

