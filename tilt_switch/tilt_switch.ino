//project 8 – Vibration sensor
int light1 = 10; 
int SensorINPUT = 13; // connect tilt sensor to interrupt 1 in digital pin 3
unsigned char state = 0;

void setup() {
  pinMode(light1, OUTPUT); //configure LED as output mode
  pinMode(SensorINPUT, INPUT); //configure tilt sensor as input mode
  digitalWrite(light1, HIGH);

  //when low voltage changes to high voltage, it triggers interrupt 1 and runs the blink function
  attachInterrupt(1, blink, RISING);
}

void loop() {
  if (state != 0){ // if state is not 0
    state = 0; // assign state value 0
    digitalWrite(light1, HIGH); // turn on LED
    delay(500); // delay for 500ms
  } else {
    digitalWrite(light1, LOW); // if not, turn off LED
  }
}
void blink() { // interrupt function blink()
  state++; //once trigger the interrupt, the state keeps increment
}