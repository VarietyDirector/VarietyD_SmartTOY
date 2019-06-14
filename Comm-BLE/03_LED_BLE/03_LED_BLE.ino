#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4, 5);



void setup()
{
  BTSerial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);   
}
 
void loop()
{
  if(BTSerial.available())
  {
    int incomingByte = BTSerial.read();
    if(incomingByte=='1')
    {
      digitalWrite(LED_BUILTIN,HIGH);
    }
    else if(incomingByte=='0')
    {
      digitalWrite(LED_BUILTIN,LOW);
    }
    
  }

}
