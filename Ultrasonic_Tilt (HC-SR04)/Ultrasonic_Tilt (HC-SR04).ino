const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 7; // Echo Pin of Ultrasonic Sensor
void setup() {
  Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
  long duration, inches, cm;
  int diff;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin,LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  diff = 40-cm;
  

  if (diff > 0){
  //Serial.print(inches);
  //Serial.print("in, ");
  //Serial.print(cm);
  //Serial.print("cm, ");
  Serial.print("load detected, tilt of: ");
  Serial.print(diff);
  Serial.println();
  delay(250);
  }

  else{
  //Serial.print(inches);
  //Serial.print("in, ");
  //Serial.print(cm);
  //Serial.print("cm ");
  Serial.print("No load, ");
  Serial.print(diff);
  Serial.print(" tilt");
  Serial.println();
  delay(250);
  }
 
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 /2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}