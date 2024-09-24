//project 8 – Vibration sensor
#include "pitches.h"

// Define input pins
int light1 = 10; 
int SensorINPUT = 3; // connect tilt sensor to interrupt 1 in digital pin 3
unsigned char state = 0; // state for sensor

int speaker = 1;

// 8-segment LED displays
int number[10][8] = {
  {0,0,0,1,0,0,0,1}, //display 0
  {0,1,1,1,1,1,0,1}, //display 1
  {0,0,1,0,0,0,1,1}, //display 2
  {0,0,1,0,1,0,0,1}, //display 3
  {0,1,0,0,1,1,0,1}, //display 4
  {1,0,0,0,1,0,0,1}, //display 5
  {1,0,0,0,0,0,0,1}, //display 6
  {0,0,1,1,1,1,0,1}, //display 7
  {0,0,0,0,0,0,0,1}, //display 8
  {0,0,0,0,1,1,0,1} //display 9
};

// Displays numbers on 8-segment LED
void numberShow(int i){ 
  if (i >= 0 && i <= 9) {
    // Display 1 thru 9
    for (int pin = 2; pin <= 9 ; pin++){
      digitalWrite(pin, number[i][pin - 2]);
    }
  } else {
    // Clear display
    for (int pin = 2; pin <= 9 ; pin++){
      digitalWrite(pin, 1);
    }
  }
}

void setup() {
  pinMode(light1, OUTPUT); //configure LED as output mode
  pinMode(SensorINPUT, INPUT); //configure tilt sensor as input mode
  
  pinMode(speaker, OUTPUT);

  //when low voltage changes to high voltage, it triggers interrupt 1 and runs the blink function
  attachInterrupt(1, blink, RISING);

  // 8-segment
  for (int pin = 2 ; pin <= 9 ; pin++){ // define digital pins 2 to 9 as output
    if (pin != 3) { // ignore 3 for sensor input
      pinMode(pin, OUTPUT);
      digitalWrite(pin, HIGH);
    }
  }
}

int countdown = 9;

void loop() {
  if (state != 0){ // if state is not 0
    state = 0; // assign state value 0
    digitalWrite(light1, HIGH); // turn on LED
    tone(speaker, NOTE_A7, 100); // beep
    if (countdown >= 0) numberShow(countdown); // 8-segment display
    countdown--;

    delay(250); 
    digitalWrite(light1, LOW);
    delay(250);
  } else {
    digitalWrite(light1, LOW); // if not, turn off LED

    // Reset countdown and clear display
    countdown = 9;
    numberShow(-1);
  }
}
void blink() { // interrupt function blink()
  state++; //once trigger the interrupt, the state keeps increment
}