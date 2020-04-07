int i = 0;
  int h = 0;
  int d = 0;
  int r = 0;
  
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  int mySensVals1[] = {2,4,8,3,2,5,7,3,9,2,6,1,8,3,7,5,8,16,15,17,22,28,21,29};
  int mySensVals2[] = {2, 4, -8, 3, 2,77,55,44,66,44,66,4,2,4,5,6,3,55,33,66,11,44};
  int mySensVals3[] = {2, 4, -8, 3, 2,6,8,2,9,3,8,4,6,3,6,1,97,55,33,66,33,99,33,66};
  int mySensVals4[] = {2, 4, -8, 3, 2,8,3,7,5,9,2,4,6,7,8,2,77,66,22,88,33,77,33,44,};
  
  for(i = 0 ;  i<20; i++)
 {   
  if (i> 359)
  { h =  h+d;
    i = 0;
  }
    if(h>19)
    {d = -5;
    r = 2;
      }
  
    if(h <1)
    {d = 5;
      r = 1;
      }
          Serial.print(mySensVals1[i]);
           Serial.print(",");
              Serial.println(i);
         
  delay(25);
}
}
