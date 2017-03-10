// 9/3/17
void setup() {
  //true g's set baud at 19200 :)
  Serial.begin(19200);
  Serial.write("enter r to read component value");
}

void loop() {
  if (Serial.available() > 0) {  
    Serial.write("\n");
    int sensorvalue = analogRead(A0);
    char command = Serial.read();
    if ( command != 'r') {
      Serial.write("enter r to read component value");
      char command = Serial.read();
    } else {
      determine(sensorvalue);
    }
  }
}

  // function to be called when the command r is entered
  int determine (int sensorvalue) {
    
    //pre determined values based on input voltages 
  int wire = 0;
  int diode_rb = 850;
  int diode_fb = 50;
  int capacitor = 739;
  int inductor = 300;
  int resistor = 600;
  
  // set component code values
  const int wire_value = 1;
  const int resistor_code = 2;
  const int capacitor_code = 3;
  const int inductor_code = 4;
  const int diode_code = 5;

  
  Serial.write("reading ");
  delay(1000);
  
  //diode reverse biased
   if ( sensorvalue > (diode_rb - 10) ) {
    Serial.print("diode reverse biased ");
 
   }

  //diode biased
   if ( sensorvalue > (diode_fb - 20) && sensorvalue < (diode_fb + 20)) {
    Serial.print("diode forward biased ");
   }
  
  //capacitor
  if ( sensorvalue > (capacitor - 70) && sensorvalue < (capacitor + 70)) {
    Serial.print("capacitor ");
   }
  
  //resistor 
  if ( sensorvalue > (resistor - 50) && sensorvalue < (resistor + 50)) {
    Serial.print("resistor ");
   }
  
  //inductor
   if ( sensorvalue > (inductor - 60) && sensorvalue < (inductor + 60)) {
    Serial.print("inductor ");
   }
  
  //wire
   if (sensorvalue < (wire + 5)) {
    Serial.print("wire ");
   }
   
   Serial.print(sensorvalue);
   Serial.print("\n");
   Serial.write("enter r to read component value");
   Serial.write("\n");
 }
