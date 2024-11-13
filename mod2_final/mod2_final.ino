//Project eleven controllable servo
#include <Servo.h> // insert the Servo.h library
Servo gearServo; // create servo object to control servo
Servo handServo;

const int servoGearPin = 10;
const int servoHandPin = 11;
const int touchPin = 12;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

int pos = 0; // position of servo

void setup() {
  gearServo.attach(servoGearPin); //Attach the servo on pin 9 to the servo object.
  handServo.attach(servoHandPin);

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

  // if a touch event is detected 
  if (reading == 1) {
    digitalWrite(ledPin, HIGH);
    if (pos < 180) pos ++;
    handServo.write(pos);
    delay(2);
  // if not, turn off the LED
  } else {
    digitalWrite(ledPin, LOW);
    if (pos >= 0) pos--;
    handServo.write(pos);
    delay(10);
  }

  // Rotate loop
  for(pos = 0; pos < 180; pos += 1){ //servo turns from 0 to 180 in steps of 1 degree
    gearServo.write(pos); //tell servo to go to position in variable 'pos'
    delay(1); //waits 15ms for the servo to reach the position
  }
  delay(1000);
  for(pos = 180; pos>=1; pos-=1) { // servo turns from 180 to 0 in steps of 1 degree
    gearServo.write(pos); //tell servo to go to position in variable 'pos'
    delay(15); //waits 15ms for the servo to reach the position
  }
  delay(400);
}