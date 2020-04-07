
String application_command = "1012; 45; 2";
int j ,k,l,m = 0;

void setup()
{Serial.begin(9600);
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
void loop()
{
  String part01 = getValue(application_command,';',0);
  String part02 = getValue(application_command,';',1);
String part03 = getValue(application_command,';',2);
  j = part01.toInt(); 
  k = part02.toInt();
  l = part03.toInt();
  m = j+k;
  Serial.println(m);
}
