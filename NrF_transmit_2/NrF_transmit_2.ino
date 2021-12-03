
#include "nRF24L01.h"

#include "RF24.h"
int buttonPin = A0;
int msg[1];
int buttonState = 0; 
RF24 radio(7,8);

const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void) {

Serial.begin(9600);
pinMode(buttonPin, INPUT);
radio.begin();

radio.openWritingPipe(pipe);

}

void loop(void) {
buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
    // turn LED on:
   msg[0] = 1;
  } else {
    // turn LED off:
    msg[0] = 2;
  }


radio.write(msg, 1);

}
