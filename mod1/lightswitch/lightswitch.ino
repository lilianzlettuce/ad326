/*
  Lightswitch
  (based on the "Button" example in File > Examples > 02.Digital > Button)

  Turns on and off a light emitting diode(LED) connected to digital pin 5,
  when flipping a household light switch attached to pin 9.

*/

const int switchPin = 5;  // the number of the lightswitch pin
const int ledPin = 13;    // the number of the LED pin

// variables will change:
int switchState = 0;  // variable for reading the lightswitch status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(switchPin, INPUT);
  digitalWrite(ledPin, HIGH);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  switchState = digitalRead(switchPin);
  Serial.println(switchState);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (switchState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
