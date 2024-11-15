// Code to read an analog value, in this case from a potentiometer and write it to the serial port
int inputPin = A0;                // Set the input to analog in pin 0

void setup() {
  Serial.begin(9600);            // Start serial communication at 9600 bps
}

void loop() {
  //Serial.println(analogRead(inputPin));
  //sensorReading = analogRead(inputPin);
  int sensorReading = analogRead(inputPin);
  int mappedVal = map(sensorReading, 0, 1023, 0, 255); //analogRead(inputPin) / 4;  // Read analog input pin, put in range 0 to 255
  //Serial.println(mappedVal);
  
  Serial.write(mappedVal);             // Send the value
  //Serial.println(mappedVal);
  delay(100);                    // give the A2D converter a moment to catch up
}