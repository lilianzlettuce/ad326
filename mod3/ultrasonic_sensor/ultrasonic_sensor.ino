// Ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

float duration; // length of sound wave
float distance; // distance of detection

// Speed of sound = 0.0343 cm / microsecond
const float speed = 0.0343;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send out sonic burst
  // 10 microseconds -> 8 cycles
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Detect how long the waves travelled (in ms)
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance using speed and time
  // Halve to account for distance there and back
  distance = (duration * speed) / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
