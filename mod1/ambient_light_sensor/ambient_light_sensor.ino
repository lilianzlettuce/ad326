// Project 9– Light the lamp

int LED = 5; 
int val = 0; //define the voltage value of photo diode in digital pin 0
int sensorPin = A1;

// rgb light
int rgbRed = 10;
int rgbGreen = 11;
int rgbBlue = 12;

void setup(){
  setColorRgb(0,0,0);

  pinMode(LED,OUTPUT);

  Serial.begin(9600); //Configure baud rate 9600
}

void loop(){
  val = analogRead(sensorPin); // Read voltage value ranging from 0 -1023
  Serial.println(val); // read voltage value from serial monitor

  if (val < 300){ // If lower than 1000, turn off LED
    digitalWrite(LED,LOW);
    //setColorRgb(200, 200, 10);
  } else{ // Otherwise turn on LED
    digitalWrite(LED,HIGH);
    //setColorRgb(20, 20, 200);
  }
  delay(10); // delay for 10ms
}

void setColorRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(rgbRed, red);
  analogWrite(rgbGreen, green);
  analogWrite(rgbBlue, blue);
}