#include <SPI.h>

int sendData = 0;

#define P1 D0

void setup() {
    Serial.begin(9600);
    pinMode(D0, OUTPUT);
}

void LEDSoff() {
  digitalWrite(P1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    sendData = Serial.read();

  switch(sendData) {
    case 97:
      LEDSoff();
      digitalWrite(P1, HIGH);
      Serial.println(sendData, DEC);
      break;
    case 'b':
      LEDSoff();
  
      Serial.println(sendData, DEC);
      break;
    case 99:
      LEDSoff();  
      Serial.println(sendData, DEC);
      break;
    case 100:
      LEDSoff();

      Serial.println(sendData, DEC);
      break;
    case 101:
      LEDSoff();

      Serial.println(sendData, DEC);
      break;
  default: 
    LEDSoff();
    Serial.println(sendData, DEC);
    break;
  }
  }
}
