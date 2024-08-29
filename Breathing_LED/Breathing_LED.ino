// Project 4
int ledPin = 9;
void setup() {
  pinMode(ledPin,OUTPUT);
}
void loop(){
  fadeOn(400,5);
  fadeOff(400,5);
  /*fadeOn(1000,5);
  fadeOff(1000,5);*/
}
void fadeOn(unsigned int time,int increment){
for (byte value = 0 ; value < 255; value+=increment){
  analogWrite(ledPin, value);
  delay(time/(255/5));
 }
}
void fadeOff(unsigned int time,int decrement){
for (byte value = 255; value >0; value-=decrement){
  analogWrite(ledPin, value);
  delay(time/(255/5));
 }
}