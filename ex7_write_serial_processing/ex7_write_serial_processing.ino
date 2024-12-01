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

// Struct for sending data through serial
struct Data {
  uint8_t id;    // 1 byte
  uint8_t value; // 1 byte
};
Data data;

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
  /*Serial.print("SWITCH");
  Serial.println(switchState);*/
  data.id = 5;
  data.value = switchState;
  Serial.write((uint8_t *) &data, sizeof(data));

  // Update LED based on switch state
  if (switchState == HIGH) {
    // Turn LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn LED off
    digitalWrite(ledPin, LOW);
  }

  // Loop through all analog inputs
  for (int i = 0; i < numInputs; i++) {
    // Read each input, put in range 0 to 255
    /*int reading = analogRead(analogInputs[i]);
    data.id = i;
    data.value = map(reading, 0, 1023, 0, 255);

    Serial.write((uint8_t *) &data, sizeof(data));*/

    int reading = analogRead(analogInputs[i]);
    int val = map(reading, 0, 1023, 0, 255);

    // Prepend distinguishing id
    Serial.print("AVAL");
    Serial.print(i);
    Serial.print("_");

    // Send value
    Serial.println(val);
  }

  delay(100); // give the A2D converter a moment to catch up
}