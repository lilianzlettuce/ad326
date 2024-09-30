const int touchPin = 5;  
const int ledPin = 4; 

const int lightSwitch = 13;

// rgb light
const int rgbRed = 10;
const int rgbGreen = 11;
const int rgbBlue = 12;

int number[10][8] = {
  {0,0,0,1,0,0,0,1}, //display 0
  {0,1,1,1,1,1,0,1}, //display 1
  {0,0,1,0,0,0,1,1}, //display 2
  {0,0,1,0,1,0,0,1}, //display 3
  {0,1,0,0,1,1,0,1}, //display 4
  {1,0,0,0,1,0,0,1}, //display 5
  {1,0,0,0,0,0,0,1}, //display 6
  {0,0,1,1,1,1,0,1}, //display 7
  {0,0,0,0,0,0,0,0}, //display 8
  {0,0,0,0,1,1,0,1} //display 9
};

/*

pins:
- 2: e
- 3: d
- 4: c (dysfunct)
- 5: dp (dysfunct)
- 6: b
- 7: a
- 8: f
- 9: g

*/

void setup() {
  // declare the digital pins we are using as either input or output:
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, LOW);

  // Start off with the rgb LED off.
  pinMode(rgbRed,OUTPUT);
  pinMode(rgbGreen,OUTPUT);
  pinMode(rgbBlue,OUTPUT);
  setColorRgb(0,0,0);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read the state of the touch sensor into a local variable:
  int touchState = digitalRead(touchPin);

  // if a touch event is detected turn the LED on:
  if (touchState == 1) {
    digitalWrite(ledPin, HIGH);
  // if not, turn off the LED
  } else {
    digitalWrite(ledPin, LOW);
  }

  // read state of light switch, change rgb led 
  int lightSwitchState = digitalRead(lightSwitch);
  if (lightSwitchState == HIGH) {
    setColorRgb(254, 254, 254);
  } else {
    setColorRgb(0, 0, 0);
  }
}

// Change RGB LED color
void setColorRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(rgbRed, red);
  analogWrite(rgbGreen, green);
  analogWrite(rgbBlue, blue);
}