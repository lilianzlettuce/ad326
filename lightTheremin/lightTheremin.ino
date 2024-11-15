int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);

  // Do the calibration of the light sensor:
  // it gives you a good sound response
  // even under differnt lighting conditions
  // this will take 5 seconds and the Arduino's
  // on board LED (pin 13) will be on during
  // the calibration period. In this time period
  // move your hand up and down over the sensor
  // - the closer you replicate the motions you
  // expect while playing the instrument, the
  // better the calibration will be.

  digitalWrite(ledPin, HIGH);
  while (millis() < 5000) { // see: arduino.cc/while for mor information
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    } 
  }
  digitalWrite(ledPin, LOW); // calibration is done, turn off onboard LED
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue,sensorLow,sensorHigh, 50, 4000);
  tone(8,pitch,20);
  delay(10); 
}


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