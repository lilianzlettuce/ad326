//Project eleven controllable servo
#include <Servo.h> // insert the Servo.h library
Servo myservo; // create servo object to control servo

int potPin = 0; // connect potentiometer to digital pin0
int potVal; // variable value to read value from analog pin

int pos = 0; // position of servo

void setup() {
  myservo.attach(9); //Attach the servo on pin 9 to the servo object.
}

void loop() {
  // Control rotation with potentiometer
  potVal = analogRead(potPin); //reads the value of the potentiommeter (value between 0 and 1023)
  pos = map(potVal, 0, 1023, 0, 179); // scale it to use it with the servo (value between 0 and 180)
  myservo.write(pos); // sets the servo position according to the scaled value
  delay(15); // wait for 15 ms to turn to certain position*/

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