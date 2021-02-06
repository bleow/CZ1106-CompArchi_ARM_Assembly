
/*****************************************/
const int ledPin = 5;//the led attach to
int ballSwitchPin = 8;

void setup()
{ 
  pinMode(ledPin,OUTPUT);//initialize the ledPin as an output
  pinMode(ballSwitchPin,INPUT);
  digitalWrite(ballSwitchPin, HIGH);
} 
/******************************************/
void loop() 
{  
  int digitalVal = digitalRead(ballSwitchPin);
  if(HIGH == digitalVal)
  {
    digitalWrite(ledPin,LOW);//turn the led off
  }
  else
  {
    digitalWrite(ledPin,HIGH);//turn the led on 
  }
}
/**********************************************/

