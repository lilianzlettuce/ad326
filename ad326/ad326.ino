/*

  Melody

  Plays a melody

  circuit:

  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/Tone

*/

#include "pitches.h"

// notes in the melody:
/*int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};*/
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_A4, NOTE_A4, NOTE_G4, 
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4,
  NOTE_C4, NOTE_G4,NOTE_F4,

  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_A4, NOTE_A4, NOTE_G4, 
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_C5, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4,
  NOTE_C4, NOTE_G4,NOTE_F4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  16, 16, 16, 16, 16/3, 16/3, 8/3,
  16, 16, 16, 16, 16/3, 16/3, 16/3, 16, 4,
  16, 16, 16, 16, 4, 8, 16/3, 16, 4,
  8, 4, 2,

  16, 16, 16, 16, 16/3, 16/3, 8/3,
  16, 16, 16, 16, 4, 8, 16/3, 16, 8,
  16, 16, 16, 16, 4, 8, 16/3, 16, 4,
  8, 4, 2
};

// Alarm
float sinVal;
int toneVal;

// Global constants for pins
const int button = 2;

const int greenLight = 3;
const int yellowLight = 4;
const int redLight = 5;
const int light4 = 7;
const int light5 = 6;

const int heartPin = 9;

const int lights[] = {greenLight, redLight, yellowLight, heartPin, light4};

// wall buttons
const int wallBtn1 = 10;
const int wallBtn2 = 11;
const int wallBtn3 = 12;

// rgb light
/*const int rgbRed = 10;
const int rgbBlue = 11;
const int rgbGreen = 12;*/

// Speaker sound pin
const int speaker = 13;


// Global variables
int ledState = LOW;  // ledState used to set the LED
int redState = HIGH;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 250;  // interval at which to blink (milliseconds)

unsigned long heartLastUpdate = 0;  // will store last time LED was updated
double heartRate = 1000;
double heartInterval = heartRate / (255 / 5);
int heartLuminosity = 255; // current brightness
int heartLumIncr = -5; // increment by

void setup() {
  // declare the LED and speaker pins as outputs
  pinMode(greenLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(redLight, OUTPUT);
  pinMode(light4, OUTPUT);
  //pinMode(light5, OUTPUT);

  pinMode(heartPin,OUTPUT);
  pinMode(speaker, OUTPUT);

  analogWrite(greenLight, 255);

  /*digitalWrite(greenLight, HIGH);
  digitalWrite(yellowLight, HIGH);
  digitalWrite(redLight, HIGH);
  digitalWrite(light4, HIGH);*/

  // declare the switch pins as an input
  pinMode(button, INPUT);
  pinMode(wallBtn1, INPUT);
  pinMode(wallBtn2, INPUT);
  pinMode(wallBtn3, INPUT);
}

int countDownStarted = false;

void loop() {
  // current time
  unsigned long currTime = millis();

  if (currTime - heartLastUpdate >= heartInterval) {
    // save last heart update
    heartLastUpdate = currTime;

    // update to new brightness
    heartLuminosity += heartLumIncr;
    analogWrite(heartPin, heartLuminosity);

    // update light increment if necessary
    if (heartLuminosity > 250) {
      heartLumIncr = -5;
    } else if (heartLuminosity == 0) {
      heartLumIncr = 5;
    }

    // play sound periodically
    if (heartLuminosity == 0) {
      tone(speaker, NOTE_A7, 100);
    }

    // Speed up pulse rate if count down started 
    if (countDownStarted && heartRate > 10) {
      heartRate--;
      heartInterval = heartRate / (255 / 5);
    }
  }

  /* switch stuff */
  // read the value of the switch
  int switchstate = digitalRead(button);

  // Test button switch state
  if(switchstate == HIGH){
    // If button pressed, play tune
    playTune();
    analogWrite(heartPin, 255);
    tone(speaker, NOTE_A7, 6000);
    heartRate = 100000000;
    heartInterval = heartRate / (255 / 5);
    analogWrite(heartPin, 0);
  } else {
    // Idle state when button isn't pressed
    // check to see if it's time to blink the LED

    /*if (currTime - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currTime;

      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW) {
        //colorRGB(random(0,255),random(0,255),random(0,255));
        ledState = HIGH;
        redState = LOW;
      } else {
        //colorRGB(0, 0, 0);
        ledState = LOW;
        redState = HIGH;
      }

      // set the LED with the ledState of the variable:
      digitalWrite(greenLight, ledState);
      digitalWrite(redLight, ledState);
      //digitalWrite(light5, ledState);

      digitalWrite(yellowLight, redState);
      digitalWrite(light4, redState);
    } */
  }

  // wall btn 2
  int wallBtnState1 = digitalRead(wallBtn1);
  int wallBtnState2 = digitalRead(wallBtn2);
  int wallBtnState3 = digitalRead(wallBtn3);
  if (wallBtnState1 == HIGH) {
    // If button pressed, speed up heart rate
    /*heartRate = 400;
    heartInterval = heartRate / (255 / 5);*/

    // Update buttons
    analogWrite(greenLight, 0);
    analogWrite(yellowLight, random(256));
    analogWrite(redLight, random(256));
    analogWrite(light4, random(256));
  }
  if (wallBtnState2 == HIGH) {
    // If button pressed, speed up heart rate
    /*heartRate = 700;
    heartInterval = heartRate / (255 / 5);*/

    // Update buttons
    analogWrite(greenLight, random(256));
    analogWrite(yellowLight, 0);
    analogWrite(redLight, random(256));
    analogWrite(light4, random(256));

    countDownStarted = true;
  }
  if (wallBtnState3 == HIGH) {
    // If button pressed, speed up heart rate
    /*heartRate = 100;
    heartInterval = heartRate / (255 / 5);*/

    // Update buttons
    analogWrite(greenLight, random(256));
    analogWrite(yellowLight, random(256));
    analogWrite(redLight, 0);
    analogWrite(light4, 0);
  }
}

// Change color of RGB LED
/*void colorRGB(int red, int green, int blue){
  analogWrite(rgbRed,constrain(red,0,255));
  analogWrite(rgbGreen,constrain(green,0,255));
  analogWrite(rgbBlue,constrain(blue,0,255));
}*/

// sound alarm
void alarm() {
  for(int x=0; x<180; x++){
    //convert angle of sinusoidal to radian measure
    sinVal = (sin(x*(3.1412/180)));
    //generate sound of different frequencies by sinusoidal value
    toneVal = 2000+(int(sinVal*1000));
    //Set a frequency for Pin-out 8
    tone(speaker, toneVal);
    delay(2);
  } 
}

// Play the tune
void playTune() {
  int currLightIndex = 0; // keeps track of which light is on right now
  int numLights = sizeof(lights) / sizeof(lights[0]);

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
    // Update lights
    for (int i = 0; i < numLights; i++) {
      if (i == currLightIndex) {
        // turn on
        digitalWrite(lights[i], HIGH);
      } else {
        // turn off 
        digitalWrite(lights[i], LOW);
      }
    }
    currLightIndex++;
    currLightIndex %= numLights;

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1800 / noteDurations[thisNote];

    tone(speaker, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.05;

    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(speaker);
  }
}