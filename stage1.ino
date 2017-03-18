

void setup() {
  
  // put your setup code here, to run once:
  //true g's set baud at 19200 :)
  Serial.begin(19200);
  Serial.write("enter r to read component value");
}

void loop() {
  delay(2000);
  if (Serial.available() > 0) {
    //Serial.write("\n");
    Serial.write("\n");
    int sensorvalue = analogRead(A0);
    //delay(3000);
    //get command from the console
    char command = Serial.read();
    if ( command == 'r') {
      determine(sensorvalue);
    }
  }
  
  // put your main code here, to run repeatedly
}


  int determine (int sensorvalue) {
  //pre determined values based on input voltages 
  int wire = 0;
  int diode_rb = 800;
  int diode_fb = 15;
  int capacitor = 650;
  int inductor = 335;
  int resistor = 517;
    
    Serial.write("reading ");
    
  //diode reverse biased
   if ( sensorvalue > (diode_rb - 10) ) {
    Serial.print("diode reverse biased ");
   }

  //diode biased
   if ( sensorvalue > (diode_fb - 8) && sensorvalue < (diode_fb + 10)) {
    Serial.print("diode forward biased ");
   }
  
  //capacitor
  if ( sensorvalue > (capacitor - 70) && sensorvalue < (capacitor + 70)) {
    Serial.print("capacitor ");
   }
  
  //resistor 
  if ( sensorvalue > (resistor - 80) && sensorvalue < (resistor + 80)) {
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
