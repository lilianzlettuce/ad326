// Analog input pins
int input0 = A0; // Reading from cable connected to second arduino
int input1 = A2; // potentiometer 1
int input2 = A3; // pot 2
int input3 = A4; // pot 3

int analogInputs[] = { A0, A2, A3, A4 };
int numInputs = sizeof(analogInputs) / sizeof(analogInputs[0]);

// Digital pins
const int switchPin = 5;  // box switch
const int ledPin = 13;    // box LED

int switchState = 0;  // switch status

void setup() {
  // Initialize LED as output
  pinMode(ledPin, OUTPUT);

  // Initialize switch as input
  pinMode(switchPin, INPUT);

  // Start serial communication at 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Read the state of the switch
  switchState = digitalRead(switchPin);
  Serial.print("SWITCH");
  Serial.println(switchState);

  // Update LED based on switch state
  if (switchState == HIGH) {
    // Turn LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn LED off
    digitalWrite(ledPin, LOW);
  }

  //Serial.println(analogRead(input1));

  // Loop through all analog inputs
  for (int i = 0; i < numInputs; i++) {
    // Read each input, put in range 0 to 255
    int reading = analogRead(analogInputs[i]);
    int val = map(reading, 0, 1023, 0, 255);

    // Prepend distinguishing id
    Serial.print("AVAL");
    Serial.print(i);
    Serial.print("_");

    // Send value
    Serial.println(val);
  }

  // Read analog inputs, put in range 0 to 255
  /*int reading0 = analogRead(input0);
  int val0 = map(reading0, 0, 1023, 0, 255);

  int reading1 = analogRead(input1);
  int val1 = map(reading1, 0, 1023, 0, 255);
  
  // Send read values
  Serial.print("RATE");
  Serial.println(val0);
  Serial.print("ROT");
  Serial.println(val1);*/

  delay(100); // give the A2D converter a moment to catch up
}