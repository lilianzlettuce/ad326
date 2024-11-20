//Item 11 - digital tube digital display
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

void numberShow(int i){ //call this function to display numbers
  for (int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin, number[i][pin - 2]);
  }
}
void setup(){
  for (int pin = 2 ; pin <= 9 ; pin++){ // define digital pins 2 to 9 as output
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}

void loop() {
  numberShow(8);
  /*for (int j = 0; j <= 9 ; j++){
    numberShow(j); // call numberShow() function to display 0-9.
    delay(500);
  }*/
}