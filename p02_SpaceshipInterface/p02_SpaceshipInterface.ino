/*
  Arduino Starter Kit example
  Project 2 - Spaceship Interface

  This sketch is written to accompany Project 2 in the Arduino Starter Kit

  Parts required:
  - one green LED
  - two red LEDs
  - pushbutton
  - 10 kilohm resistor
  - three 220 ohm resistors

  created 13 Sep 2012
  by Scott Fitzgerald

  https://store.arduino.cc/genuino-starter-kit

  This example code is part of the public domain.
*/

// Create a global variable to hold the state of the switch. This variable is
// persistent throughout the program. Whenever you refer to switchState, you’re
// talking about the number it holds
int switchstate = 0;

int button = 2;

int greenLight = 3;
int redLight1 = 4;
int redLight2 = 5;

void setup() {
  // declare the LED pins as outputs
  pinMode(greenLight, OUTPUT);
  pinMode(redLight1, OUTPUT);
  pinMode(redLight2, OUTPUT);

  // declare the switch pin as an input
  pinMode(2, INPUT);
}

void loop() {

  // read the value of the switch
  // digitalRead() checks to see if there is voltage on the pin or not
  switchstate = digitalRead(button);

  // if the button is not pressed turn on the green LED and off the red LEDs
  if (switchstate == LOW) {
    digitalWrite(greenLight, HIGH);  // turn the green LED on pin 3 on
    digitalWrite(redLight1, LOW);   // turn the red LED on pin 4 off
    digitalWrite(redLight2, LOW);   // turn the red LED on pin 5 off
  }
  // if the switch is not LOW (the button is pressed) turn off the green LED and
  // blink alternatively the red LEDs
  else {
    digitalWrite(greenLight, LOW);   // turn the green LED on pin 3 off
    digitalWrite(redLight1, LOW);   // turn the red LED on pin 4 off
    digitalWrite(redLight2, HIGH);  // turn the red LED on pin 5 on
    // wait for a quarter second before changing the light
    delay(250);
    digitalWrite(redLight1, HIGH);  // turn the red LED on pin 4 on
    digitalWrite(redLight2, LOW);   // turn the red LED on pin 5 off
    // wait for a quarter second before changing the light
    delay(250);
  }
}
