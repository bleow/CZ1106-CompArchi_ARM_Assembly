int tx_char = 'U';

void setup() {
  // baud rate = 19200bps, 1 START, 8 DATA, Even Parity, 1 STOP bit
  Serial.begin(19200, SERIAL_8E1);   
  while (!Serial);      // Wait until Serial is ready 
  Serial.println("Serial Port ready");  
}

void loop() {
  Serial.write(tx_char);//TX ASCII value of tx_char
  delay(1000);          //Delay for 1000ms
}


