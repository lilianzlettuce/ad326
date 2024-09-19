// Project 9– Light the lamp

int LED = 5; 
int val = 0; //define the voltage value of photo diode in digital pin 0
int sensorPin = A1;

void setup(){
  pinMode(LED,OUTPUT);
  Serial.begin(9600); //Configure baud rate 9600
}
void loop(){
  val = analogRead(sensorPin); // Read voltage value ranging from 0 -1023
  Serial.println(val); // read voltage value from serial monitor
  if (val < 1000){ // If lower than 1000, turn off LED
    digitalWrite(LED,LOW);
  } else{ // Otherwise turn on LED
    digitalWrite(LED,HIGH);
  }
  delay(10); // delay for 10ms
}