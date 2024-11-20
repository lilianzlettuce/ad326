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
const double startRate = 400; // starting pulse rate
double rate1 = startRate; // current pulse rate
double interval1 = rate1 / (255 / 5);
int luminosity1 = 255; // current brightness
int lumIncr1 = -5; // increment by
double maxLum = 250; // maximum brightness

// Keep track if plant has died
bool dead = true; 

// Timing for 8-segment LED
unsigned long lastUpdate2 = 0;  // will store last time LED was updated
double rate2 = 100; // current pulse rate
double interval2 = rate2 ;// / (255 / 5);
int segNum = 0; // current displayed number

void loop() {

  // read state of light switch, change rgb led 
  int lightSwitchState = digitalRead(lightSwitch);
  if (lightSwitchState == HIGH) {
    // Turn on fake plant
    setColorRgb(254, 0, 104);
  } else {
    // Turn off fake plant
    setColorRgb(0, 0, 0);

    // Reset real plant pulse rate
    rate1 = startRate + 200;
    interval1 = rate1 / (255 / 5);
  }

  // read the state of the touch sensor into a local variable:
  int touchState = digitalRead(touchPin);

  // if a touch event is detected, revive plant
  if (touchState == HIGH) {
    //digitalWrite(ledPin, HIGH);
    dead = false;
  }


  /* Breathing light cycle */

  // current time
  unsigned long currTime = millis();

  if (!dead && currTime - lastUpdate1 >= interval1) {
    // save last heart update
    lastUpdate1 = currTime;

    // update to new brightness
    luminosity1 += lumIncr1;

    // update light increment if necessary
    if (luminosity1 > maxLum) {
      lumIncr1 = -5;
    } else if (luminosity1 <= 0) {
      luminosity1 = 0;
      lumIncr1 = 5;

      // Burn out at some point
      if (rate1 > 1500) {
        dead = true;
      }
    }

    analogWrite(ledPin, luminosity1);

    // Slow down pulse rate if light switch on
    if (lightSwitchState == HIGH) {
      rate1 *= 1.002;
      interval1 = rate1 / (255 / 5);
    }
  }

  // 8-segment LED cycle
  if (lightSwitchState == HIGH && currTime - lastUpdate2 >= interval2) {
    // save last heart update
    lastUpdate2 = currTime;

    // update to new display
    segNum = (segNum + 1) % (sizeof(number) / sizeof(number[0]));
    displayNum(segNum);
  }
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