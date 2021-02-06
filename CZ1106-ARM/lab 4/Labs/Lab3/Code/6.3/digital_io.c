
int ledPin = 5;
int buttonApin = 4; //9;
int buttonBpin = 3; //8;

byte leds = 0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  

  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready - Leonardo
  Serial.println("Serial Port ready");  
}

void loop() 
{
  Serial.println("Pin Status");
  Serial.println(digitalRead(buttonApin));
  Serial.println(digitalRead(buttonBpin));
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}