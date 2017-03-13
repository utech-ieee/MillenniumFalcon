// 9/3/17
int relay[] = {13, 12, 11, 10, 9};
void setup() {
  //true g's set baud at 19200 :)
  Serial.begin(19200);
  Serial.write("enter r to read component value");
  
  pinMode(relay[0], OUTPUT); 
  pinMode(relay[1], OUTPUT); 
  pinMode(relay[2], OUTPUT); 
  pinMode(relay[3], OUTPUT); 
  pinMode(relay[4], OUTPUT); 
}

void loop() {
  
  if (Serial.available() > 0) {  
    Serial.write("\n");
    
    char command = Serial.read();
    if ( command != 'r') {
      Serial.write("enter r to read component value");
      char command = Serial.read();
    } else {
      for (int i = 0; i<=4; i++){
        
        digitalWrite(relay[i], HIGH);
        determine(i);
        digitalWrite(relay[i], LOW);   
        delay(1000);  
        
      }    
    }
  }
}

  // function to be called when the command r is entered
  int determine (int i) {
    
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
  int sensorvalue = analogRead(A0);
  
   //wire
   if (sensorvalue < (wire + 5)) {
    Serial.print("wire ");
    Serial.print(sensorvalue);
    Serial.print("\n");
    return 1;
   }
  //resistor 
  if ( sensorvalue > (resistor - 50) && sensorvalue < (resistor + 50)) {
    Serial.print("resistor ");
    Serial.print(sensorvalue);
    Serial.print("\n");
    return 2;
   }
  //capacitor
  if ( sensorvalue > (capacitor - 70) && sensorvalue < (capacitor + 70)) {
    Serial.print("capacitor ");
    Serial.print(sensorvalue);
    Serial.print("\n");
    return 3;
   }
   
  //inductor
   if ( sensorvalue > (inductor - 60) && sensorvalue < (inductor + 60)) {
    Serial.print("inductor ");
    Serial.print(sensorvalue);
    Serial.print("\n");
    return 4;
   }
  
    //diode reverse biased
   if ( sensorvalue > (diode_rb - 10) ) {
    Serial.print("diode reverse biased ");
    Serial.print(sensorvalue);
    Serial.print("\n");
    return 5;
   }

  //diode biased
   if ( sensorvalue > (diode_fb - 20) && sensorvalue < (diode_fb + 20)) {
    Serial.print("diode forward biased ");
    Serial.print(sensorvalue);
    Serial.print("\n");
    return 5;
   }

 }
