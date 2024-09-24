// constants won't change. They're used here to set pin numbers:
const int touchPin = 10;  // the number of the pushbutton pin
const int ledPin = 11;    // the number of the LED pin


void setup() {
  // put your setup code here, to run once:

  // declare the digital pins we are using as either input or output:
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read the state of the touch sensor into a local variable:
  int reading = digitalRead(touchPin);

  // if a touch event is detected turn the LED on:
  if (reading == 1) {
    digitalWrite(ledPin, HIGH);
  // if not, turn off the LED
  } else {
    digitalWrite(ledPin, LOW);
  }

}
