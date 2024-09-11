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

// normal light
const int light1 = 13;

void setup() {
 // Start off with the LED off.
 setColorRgb(0,0,0);
}

void loop() {
 // unsigned means we only have positive number values: 
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