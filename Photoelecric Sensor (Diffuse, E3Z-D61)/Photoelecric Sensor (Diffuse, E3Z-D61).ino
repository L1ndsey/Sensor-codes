void setup() {
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop(){

  if(digitalRead(7))
    Serial.println("Object Detected");
  else
    Serial.println("No Object");

    delay(1000);
}