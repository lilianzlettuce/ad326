#include <NewPing.h>

/* Ultrasonic sensor vars */
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 250 // max measurable distance (cm)

// Create NewPing sonar object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Speed of sound = 0.0343 cm / microsecond
const float speed = 0.0343;
int lastDistanceVal = -1;


/* Photocell vars */
const int photoCellPin = A1; // input pin
int lastLightVal = -1;

// Test with serial output 
// Find a good range for every new environment
const int minLightVal = 200;
const int maxLightVal = 900;


// Analog input pins
int input0 = A0; // Reading from cable connected to second arduino
int input1 = A2; // potentiometer 1
int input2 = A3; // pot 2
int input3 = A4; // pot 3

int analogInputs[] = { A0, A2, A3, A4 };
int numInputs = sizeof(analogInputs) / sizeof(analogInputs[0]);
int lastAnalogVals[4] = {-1};

// Digital pins
const int switchPin = 5;  // box switch
const int ledPin = 13;    // box LED

int switchState = 0;  // switch status
int lastSwitchState = -1; // last switch status

// Struct for sending data through serial
struct Data {
  uint8_t id;    // 1 byte
  uint8_t value; // 1 byte
};
Data data;

void setup() {
  // Initialize LED as output
  pinMode(ledPin, OUTPUT);

  // Initialize switch as input
  pinMode(switchPin, INPUT);

  // Start serial communication at 9600 bps
  Serial.begin(9600);
}

void loop() {
  /* Digital signals */

  // Get median duration in ms
  float duration = sonar.ping_median(5, MAX_DISTANCE);

  // Calculate distance using speed and time
  // Halve to account for distance there and back
  int distance = (int) (duration * speed) / 2;
  int distanceVal = map(distance, 0, MAX_DISTANCE, 0, 255);
  if (distanceVal == 0) distanceVal = 255; // default to largest value when invalid
  if (distanceVal != lastDistanceVal) {
    // Send new state over serial if updated
    Serial.print("DVAL0_");
    Serial.println(distanceVal);

    lastDistanceVal = distanceVal;
  }

  // Read the state of the switch
  switchState = digitalRead(switchPin);
  if (switchState != lastSwitchState) {
    // Send new state over serial if updated
    Serial.print("SVAL0_");
    Serial.println(switchState);

    lastSwitchState = switchState;
  }

  // Update LED based on switch state
  if (switchState == HIGH) {
    // Turn LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn LED off
    digitalWrite(ledPin, LOW);
  }

  /* Analog signals */

  // Read photocell light value
  int lightReading = analogRead(photoCellPin);
  int lightVal = map(lightReading, minLightVal, maxLightVal, 0, 255);
  if (lightVal != lastLightVal) {
    Serial.print("LVAL0_");
    Serial.println(lightVal);

    lastLightVal = lightVal;
  }

  // Loop through all analog inputs
  for (int i = 0; i < numInputs; i++) {
    // Read each input, put in range 0 to 255
    int reading = analogRead(analogInputs[i]);
    int val = map(reading, 0, 1023, 0, 255);

    // Derive rotary switch position for 12 position switch (A3)
    if (i == 2) {
      val = ((float) val / 23) + 0.5; // round to nearest int
    }

    // Update over serial if different from previous
    if (val != lastAnalogVals[i]) {
      // Prepend distinguishing id
      Serial.print("AVAL");
      Serial.print(i);
      Serial.print("_");

      // Send value
      Serial.println(val);

      lastAnalogVals[i] = val;
    }
  }

  delay(100); // give the A2D converter a moment to catch up
}