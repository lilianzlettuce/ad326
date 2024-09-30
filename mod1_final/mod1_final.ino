const int touchPin = 4;  
const int ledPin = 5; 

const int lightSwitch = 13;

// rgb light
const int rgbRed = 12;
const int rgbGreen = 11;
const int rgbBlue = 10;

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

  for (int pin = 2 ; pin <= 9 ; pin++){ // define digital pins 2 to 9 as output
    if (pin != ledPin && pin != touchPin) {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, HIGH);
    }
  }
}

// Timing for ledPin pulse
unsigned long lastUpdate1 = 0;  // will store last time LED was updated
double rate1 = 1000;
double interval1 = rate1 / (255 / 5);
int luminosity1 = 255; // current brightness
int lumIncr1 = -5; // increment by

void loop() {

  // read state of light switch, change rgb led 
  int lightSwitchState = digitalRead(lightSwitch);
  if (lightSwitchState == HIGH) {
    setColorRgb(254, 0, 104);
  } else {
    setColorRgb(0, 0, 0);
  }

  // read the state of the touch sensor into a local variable:
  int touchState = digitalRead(touchPin);

  // if a touch event is detected turn the LED on:
  /*if (touchState == 1) {
    digitalWrite(ledPin, HIGH);
  // if not, turn off the LED
  } else {
    digitalWrite(ledPin, LOW);
  }*/


  /* Breathing light cycle */

  // current time
  unsigned long currTime = millis();

  if (currTime - lastUpdate1 >= interval1) {
    // save last heart update
    lastUpdate1 = currTime;

    // update to new brightness
    luminosity1 += lumIncr1;

    // update light increment if necessary
    if (luminosity1 > 250) {
      luminosity1 = 255;
      lumIncr1 = -5;
    } else if (luminosity1 <= 0) {
      luminosity1 = 0;
      lumIncr1 = 5;
    }

    analogWrite(ledPin, luminosity1);

    // Slow down pulse rate if light switch on
    /*if (countDownStarted && heartRate > 10) {
      heartRate--;
      heartInterval = heartRate / (255 / 5);
    }*/
  }




  displayNum(8);
  /*for (int j = 0; j <= 9 ; j++){
    displayNum(j); // call displayNum() function to display 0-9.
    delay(500);
  }*/
}

// Change RGB LED color
void setColorRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(rgbRed, red);
  analogWrite(rgbGreen, green);
  analogWrite(rgbBlue, blue);
}

void displayNum(int i){ //call this function to display numbers
  for (int pin = 2; pin <= 9 ; pin++){
    if (pin != ledPin && pin != touchPin) {
      digitalWrite(pin, number[i][pin - 2]);
    }
  }
}