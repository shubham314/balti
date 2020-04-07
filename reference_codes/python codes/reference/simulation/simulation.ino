
int i = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 int g[] = {78,46,44,13,38};
  //int g[] = {"78","46","44","13","38"};
  /*int h[] = {"78","46","44","13","38"};
  int j[] = {"78","46","44","13","38"};
  int k[] = {"78","46","44","13","38"};
  */
  
 for(i=0;i<5;i++)
 {

//Serial.print("'");
  Serial.println(g[i]);
  /*Serial.print("'");
Serial.print(",");
Serial.print("'");
 Serial.print(h[i]+2);
 Serial.println("'");  */
 delay(50);
  }
}
