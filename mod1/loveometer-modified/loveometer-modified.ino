const int sensorPin = A0;
const float baselineTemp = 20.0;

int led1 = 10;
int led2 = 11;
int led3 = 12;

void setup(){
  /*led1 = 2;
  led2 = 3;
  led3 = 4;*/

  Serial.begin(9600); // open a serial port
  for(int pinNumber = led1; pinNumber <= led3; pinNumber++){ 
    pinMode(pinNumber,OUTPUT); digitalWrite(pinNumber, LOW);
  }
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // convert the ADC reading to voltage
  //float voltage = (sensorVal/1024.0) * 5.0;

  //convert the ADC readingto temperature in degrees
  Serial.print(", degrees C: ");
  float temperature = (float)sensorVal * (5/10.24);
  Serial.println(temperature);

  int diff = 1;
  if (temperature < baselineTemp){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW); 
  } else if (temperature < baselineTemp + diff){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (temperature < baselineTemp + diff * 2){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } 
  delay(1);
}