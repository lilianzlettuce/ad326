//Project eleven controllable servo
#include <Servo.h> // insert the Servo.h library
Servo myservo; // create servo object to control servo

const int servoPin = 9;
const int touchPin = 10;  // the number of the pushbutton pin
const int ledPin = 11;    // the number of the LED pin

int pos = 0; // position of servo

void setup() {
  myservo.attach(servoPin); //Attach the servo on pin 9 to the servo object.

  // declare the digital pins we are using as either input or output:
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, HIGH);
}

void loop() {
  // read the state of the touch sensor into a local variable:
  int reading = digitalRead(touchPin);
  Serial.print(reading);

  // if a touch event is detected turn the LED on:
  if (reading == 1) {
    digitalWrite(ledPin, HIGH);
    if (pos < 180) pos ++;
    myservo.write(pos);
    delay(2);
  // if not, turn off the LED
  } else {
    digitalWrite(ledPin, LOW);
    if (pos >= 0) pos--;
    myservo.write(pos);
    delay(10);
  }

  // Rotate loop
  /*for(pos = 0; pos < 180; pos += 1){ //servo turns from 0 to 180 in steps of 1 degree
    myservo.write(pos); //tell servo to go to position in variable 'pos'
    delay(1); //waits 15ms for the servo to reach the position
  }
  delay(1000);
  for(pos = 180; pos>=1; pos-=1) { // servo turns from 180 to 0 in steps of 1 degree
    myservo.write(pos); //tell servo to go to position in variable 'pos'
    delay(15); //waits 15ms for the servo to reach the position
  }
  delay(400);*/
}