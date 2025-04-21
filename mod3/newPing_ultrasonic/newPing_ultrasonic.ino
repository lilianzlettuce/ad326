#include <NewPing.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 400 // max measurable distance (cm)

// Create NewPing sonar object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Speed of sound = 0.0343 cm / microsecond
const float speed = 0.0343;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Wait 50ms between pings
  delay(50);

  // Send ping, get distance in cm
  //int distance = sonar.ping_cm(); 

  // Get median duration in ms
  float duration = sonar.ping_median(5, MAX_DISTANCE);

  // Calculate distance using speed and time
  // Halve to account for distance there and back
  float distance = (duration * speed) / 2;

  // Print result (0 = outside set distance range)
  /*Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");*/

  Serial.print("AVAL3_");
  // Send value
  Serial.println((int) distance);
}
