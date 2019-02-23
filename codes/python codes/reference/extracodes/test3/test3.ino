int i = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  int g[] = {"78","46","44","13","38"};
  int h[] = {"78","46","44","13","38"};
  int j[] = {"78","46","44","13","38"};
  int k[] = {"78","46","44","13","38"};
 for(i=0;i<5;i++)
 {
  Serial.print(g[i]);

  Serial.print(",");

 Serial.print(h[i]);

 Serial.print(",");

 Serial.print(j[i]);

 Serial.print(",");

 Serial.print(k[i]);

  }

}
