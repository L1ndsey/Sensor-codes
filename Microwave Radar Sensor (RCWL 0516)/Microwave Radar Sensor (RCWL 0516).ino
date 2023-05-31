int Sensor = 2;     // RCWL-0516 Input Pin


int LED = 3;       // LED Output Pin


void setup() {


  pinMode (Sensor, INPUT);  // RCWL-0516 as input


  pinMode (LED, OUTPUT);    // LED as OUTPUT


  digitalWrite(LED, LOW);   // Turn LED Off


}


void loop() {


  bool SensValue = digitalRead(Sensor);  // Read Sensor value


  if (SensValue == HIGH) {       


    digitalWrite(LED, HIGH);  // Turn LED On


  }




  /*else {       


    digitalWrite(LED, LOW);  // Turn LED Off


  }*/


}


