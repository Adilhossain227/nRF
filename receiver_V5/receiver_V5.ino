//Actuators
int mot1_1=9;
int mot1_2=10;
int mot2_1=11;
int mot2_2=12;
int mot3_1=2;
int mot3_2=3;
int mot4_1=4;
int mot4_2=5;
char data;
//Actuators
int light=38;
int buttonState=0;
#include "nRF24L01.h"
#include "RF24.h"
int msg[10];
RF24 radio(7,8);//7-CE,8-cs, 50-MISO,51-MOSI,52-sck
const uint64_t pipe = 0xE8E8F0F0E1LL;
void setup(void) {
pinMode(mot1_1,OUTPUT);
pinMode(mot1_2,OUTPUT);
pinMode(mot2_1,OUTPUT);
pinMode(mot2_2,OUTPUT);
pinMode(mot3_1,OUTPUT);
pinMode(mot3_2,OUTPUT);
pinMode(mot4_1,OUTPUT);
pinMode(mot4_2,OUTPUT);
pinMode(light,OUTPUT);
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(1, pipe);
radio.startListening();
delay(100);
}
void loop(void) {
if (radio.available()) {
bool done = false;
while (!done) {
if(Serial.available()){
data=Serial.read();
}
if(data=='w'){
  forward();
 }
 else if(data=='x'){
  stops();
 }
  
radio.read(msg, sizeof(msg));
Serial.print(msg[0]); 
Serial.print(msg[1]);
Serial.print(msg[2]);
Serial.print(msg[3]);
Serial.print(msg[4]);
Serial.println();
delay(10);
if(msg[0]==1){
 back();
}
if(msg[0]==2){
 forward();
}
if(msg[0]==3){
 right();
}
if(msg[0]==4){
 left();
}
if(msg[0]==0 || data=='b'){
 stops();
}
}

}
else
{
Serial.println("No radio available");
}
}
void forward(){
 digitalWrite(mot1_1,LOW);
 digitalWrite(mot1_2,HIGH);
 digitalWrite(mot2_1,LOW);
 digitalWrite(mot2_2,HIGH);
 
 digitalWrite(mot3_1,LOW);
 digitalWrite(mot3_2,HIGH);
 digitalWrite(mot4_1,LOW);
 digitalWrite(mot4_2,HIGH);
}


void left(){
 digitalWrite(mot1_1,LOW);
 digitalWrite(mot1_2,HIGH);
 digitalWrite(mot2_1,HIGH);
 digitalWrite(mot2_2,LOW);
 
 digitalWrite(mot3_1,HIGH);
 digitalWrite(mot3_2,LOW);
 digitalWrite(mot4_1,LOW);
 digitalWrite(mot4_2,HIGH);
}

void right(){
  digitalWrite(mot1_1,HIGH);
 digitalWrite(mot1_2,LOW);
 digitalWrite(mot2_1,LOW);
 digitalWrite(mot2_2,HIGH);
 
 digitalWrite(mot3_1,LOW);
 digitalWrite(mot3_2,HIGH);
 digitalWrite(mot4_1,HIGH);
 digitalWrite(mot4_2,LOW);
}
void back(){
 digitalWrite(mot1_1,HIGH);
 digitalWrite(mot1_2,LOW);
 digitalWrite(mot2_1,HIGH);
 digitalWrite(mot2_2,LOW);
 
 digitalWrite(mot3_1,HIGH);
 digitalWrite(mot3_2,LOW);
 digitalWrite(mot4_1,HIGH);
 digitalWrite(mot4_2,LOW);
}
void stops(){
  digitalWrite(mot1_1,LOW);
 digitalWrite(mot1_2,LOW);
 digitalWrite(mot2_1,LOW);
 digitalWrite(mot2_2,LOW);
 digitalWrite(mot3_1,LOW);
 digitalWrite(mot3_2,LOW);
 digitalWrite(mot4_1,LOW);
 digitalWrite(mot4_2,LOW);
}
void lighting(){
  digitalWrite(light,HIGH);
  delay(50);
  digitalWrite(light,LOW);
  delay(50);
}
