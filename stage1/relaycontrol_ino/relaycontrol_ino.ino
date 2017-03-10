//digital pins the relay controlls are connected to
int relay[] = {13, 12, 11, 10, 9};
void setup() {                
  // initialize the digital pin as an output.
  pinMode(relay[0], OUTPUT); 
  pinMode(relay[1], OUTPUT); 
  pinMode(relay[2], OUTPUT); 
  pinMode(relay[3], OUTPUT); 
  pinMode(relay[4], OUTPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i = 0; i<4; i++){
    
    digitalWrite(relay[i], HIGH);
    delay(1000); 
    digitalWrite(relay[i], LOW);   
    delay(1000);  
    
  }    
}
