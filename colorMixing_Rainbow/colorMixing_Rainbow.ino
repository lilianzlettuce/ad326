/*
 * 
 * This code cycles an RGB LED through all the colors of the 
 * rainbow, slighlty adapted by F. Winkler to work with
 * the color mixing lamp circuit setup in the Arduino
 * Starter Kit Project Book.
 * 
 * Adapted from: https://gist.github.com/jimsynz/766994
 * 
 */

// rgb light
const int rgbRed = 10;
const int rgbGreen = 11;
const int rgbBlue = 12;

const int rgbRed = 10;
const int rgbGreen = 11;
const int rgbBlue = 12;

// normal light
const int light1 = 13;

// Timing for light1 pulse
unsigned long lastUpdate1 = 0;  // will store last time LED was updated
double rate1 = 100;
double interval1 = rate1 / (255 / 5);
int luminosity1 = 255; // current brightness
int lumIncr1 = -5; // increment by

void setup() {
  // Start off with the LED off.
  setColorRgb(0,0,0);

  pinMode(light1, OUTPUT);
  //digitalWrite(light1, HIGH);
}

void loop() {
  /* Breathing light cycle */

  // current time
  unsigned long currTime = millis();

  if (currTime - lastUpdate1 >= interval1) {
    // save last heart update
    lastUpdate1 = currTime;

    // update to new brightness
    luminosity1 += lumIncr1;
    analogWrite(light1, luminosity1);

    // update light increment if necessary
    if (luminosity1 > 250) {
      lumIncr1 = -5;
    } else if (luminosity1 == 0) {
      lumIncr1 = 5;
    }
  }
  
  /* RGB Light cycle */
  unsigned int rgbColor[3];

  // Start off with red.
  rgbColor[0] = 255; // red component
  rgbColor[1] = 0;   // green component
  rgbColor[2] = 0;   // blue component
    
  // Choose the colours to increment and decrement.
  for (int decColor = 0; decColor < 3; decColor += 1) {
    int incColor = (decColor == 2) ? 0 : decColor + 1;
    
    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColor[decColor] -= 1;
      rgbColor[incColor] += 1;
      setColorRgb(rgbColor[0], rgbColor[1], rgbColor[2]);
      delay(100);
    }
  }
}
void setColorRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(rgbRed, red);
  analogWrite(rgbGreen, green);
  analogWrite(rgbBlue, blue);
}