// code for the lidar sensor for the machine
// changable area
int lidarPin1  = 2;  // the pin for low values
int lidarPin2 = 3; // the pin fro the pwm

unsigned long pulseWidth;

void setup()
{
  Serial.begin(115200); // Start serial communications

  pinMode(lidarPin1, OUTPUT); // Set pin 2 as trigger pin
  digitalWrite(lidarPin1, LOW); // Set trigger LOW for continuous read

  pinMode(lidarPin2, INPUT); // Set pin 3 as monitor pin
}

void lidar()
{
  pulseWidth = pulseIn(lidarPin2, HIGH); // Count how long the pulse is high in microseconds

  // If we get a reading that isn't zero, let's print it
  if(pulseWidth != 0)
  {
    pulseWidth = pulseWidth / 10; // 10usec = 1 cm of distance
    Serial.println(pulseWidth); // Print the distance
  }
}

void loop()
{
  lidar();
}
