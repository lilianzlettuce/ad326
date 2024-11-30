// Code to read an analog value, in this case from a potentiometer and write it to the serial port
int input1 = A0;
int input2 = A4;

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  //Serial.println(analogRead(input1));

  // Read analog input pin for sample rate, put in range 0 to 255
  int reading1 = analogRead(input1);
  int rateVal = map(reading1, 0, 1023, 0, 255);
  
  // Send the value
  Serial.print("RATE");
  Serial.println(rateVal);

  // Read analog input pin, put in range 0 to 255
  int reading2 = analogRead(input2);
  int rotationVal = map(reading2, 0, 1023, 0, 255);
  
  // Send the value
  Serial.print("ROT");
  Serial.println(rotationVal);

  delay(100); // give the A2D converter a moment to catch up
}