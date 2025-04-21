// Input pin
const int photoCellPin = A1;

// Test with serial output 
// Find a good range for every new environment
const int minLightVal = 4;
const int maxLightVal = 800;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(photoCellPin);
  int val = map(reading, minLightVal, maxLightVal, 0, 255);
  Serial.print("AVAL3_");
  Serial.println(val);

  delay(100); // give the A2D converter a moment to catch up
}
