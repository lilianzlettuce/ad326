/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  Circuit and original tutorial at: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce

  This is modified so we use the Serial Monitor window to see how many times the button has been pushed
  NO LED is necessary for this example but it can be easily added in the lines indicated below

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi
  modified for AD32600 27 Sep 2022
  by Fabian Winkler

  This example code is in the public domain.
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

int counter = 0; // variable that keeps track how many times we have pushed the button

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);

  // open teh Serial communication:
  Serial.begin(9600);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed, e.g from OFF to ON or from ON to OFF:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        // increase the counter:
        counter = counter + 1;

        // here we only want to cycle through 5 different "sequences" of event with the 
        // each push of the button, that why we reset the counter value if it becomes
        // greater than 5:

        if (counter > 5) {
          counter = 1;
        }

        // based on the value of counter (counting the button push events) do different things:
        switch(counter) {
          case 1:
          // do something in case the button is pushed for the first time
          // e.g. turn on LEDs, or - in this case, print something to the 
          // Serial Monitor window:
          Serial.println("Button pushed once");
          break;
          case 2:
          // do something else...
          Serial.println("Button pushed a second time");
          break;
          case 3:
          // do something else...
          Serial.println("Button pushed three times");
          break;
          case 4:
          // do something else...
          Serial.println("Button pushed a forth time");
          break;
          case 5:
          // do something else...
          Serial.println("Button pushed for the fifth time - next time we pushe it the counter resets...");
          break;
        }
        
      }
    }
  }

  // set the LED:
  // digitalWrite(ledPin, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
