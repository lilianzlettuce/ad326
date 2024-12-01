const int buzzerPin = 9;
const int buzzerPin2 = 10;
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
  //Serial.print(touchReading);

  // read analog sensors
  int analog0 = analogRead(A0);
  int analog1 = analogRead(A1);

  // test for tv plug
  int analog5 = analogRead(A5);

  // print the sensor reading so you know its range
  Serial.print("A0");
  Serial.println(analog0);
  //Serial.println(analog1);
  Serial.print("A5");
  Serial.println(analog5);

  //int max = map(analog0, 0, 1023, 0, 5000);
  /*int max = map(analog0, 0, 40, 0, 5000);
  tone(buzzerPin, random(0, max), 10);
  delay(10);
  */

  int diff = map(analog0, 0, 40, 0, 5000);
  int mid = 69;
  tone(buzzerPin, random(mid - diff, mid + diff), 10);
  delay(0);

  int pitch2 = map(analog1, 0, 40, 0, 1000);
  tone(buzzerPin2, random(0, pitch2), 10);

  // map the analog input range (in this case, 0 - 1023 from the potentiometer)
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below depending on the range
  /*if (touchReading == 1) {
    int thisPitch = map(analog1, 0, 1023, 120, 1500);
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, thisPitch, 10);
  } else {
    // Random noise
    digitalWrite(ledPin, LOW);

    int max = map(analog1, 0, 1023, 0, 5000);
    tone(buzzerPin, random(0, max), 10);
    //tone(buzzerPin, random(0, 2000), 10);
    //noTone(buzzerPin);
  }*/

  // play the pitch:
  //tone(buzzerPin, thisPitch, 10);
  //delay(1);  // delay in between reads for stability
}