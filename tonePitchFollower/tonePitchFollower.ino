/*
  Pitch follower

  Plays a pitch that changes based on a changing analog input

  circuit:
  - 8 ohm speaker on digital pin 9
  - photoresistor on analog 0 to 5V
  - 4.7 kilohm resistor on analog 0 to ground

  created 21 Jan 2010
  modified 31 May 2012
  by Tom Igoe, with suggestion from Michael Flynn

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/tonePitchFollower
*/

const int buzzerPin = 9;
const int touchPin = 12;
const int ledPin = 13;

void setup() {
  Serial.begin(9600);

  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read state of touch sensor
  int touchReading = digitalRead(touchPin);
  Serial.print(touchReading);

  // read analog sensors
  int sensorReading = analogRead(A0);
  int sensorExposed = analogRead(A1);

  // print the sensor reading so you know its range
  Serial.println(sensorReading);

  // map the analog input range (in this case, 0 - 1023 from the potentiometer)
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below depending on the range
  // your sensor's giving:
  int thisPitch = map(sensorExposed, 0, 1023, 120, 1500);
  if (touchReading == 1) {
    thisPitch = map(sensorReading, 0, 1023, 120, 1500);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // play the pitch:
  tone(buzzerPin, thisPitch, 10);
  delay(1);  // delay in between reads for stability
}
