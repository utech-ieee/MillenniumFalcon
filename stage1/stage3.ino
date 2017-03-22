int motorPin1 = 8;  
int motorPin2 = 9;    
int motorPin3 = 10;   
int motorPin4 = 11;    

int counter = 0;
int pass = 0;
int motorSpeed = 1200;  
int count = 0;          // count of steps made
int countsperrev = 512; // number of steps per full revolution
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

int code[] = {3, 1, 4, 5, 2};

void setup() {
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}


void loop(){
  for (int i=0; i<=4; i++) {
    switch (i) {
      case 0:
        Serial.println("case 1");
        while (counter<(512*code[i])) {
          counter++;
          turn_clockwise(code[i]);
          if (counter>=(512*code[i])) {
            counter = 0;
            break;
          }
        }
        break;
        
      case 1:
        Serial.println("case 2");
        while (counter <= (512*code[i])) {
          counter++;
          
          turn_anticlockwise(code[i]);
          if (counter == (511*code[i]) ) {
            counter = 0;
            break;
          }  
        }
        break;
        
      case 2:
      Serial.println("case 3");
        while (counter<=(512*code[i])) {
          counter++;
          //Serial.println(counter);
          turn_clockwise(code[i]);
          if (counter==(512*code[i])) {
            counter = 0;
            break;
          }
        }
        break;
        
      case 3:
        Serial.println("case 4");
        while (counter <= (512*code[i])) {
          counter++;
          //Serial.println(counter);
          turn_anticlockwise(code[i]);
          if (counter >= (512*code[i]) ) {
            counter = 0;
            break;
          }  
        }
        break;
      case 4:
        Serial.println("case 5");
        while (counter<(512*code[i])) {
          counter++;
          turn_clockwise(code[i]);
          if (counter>=(512*code[i])) {
            counter = 0;
            break;
          }
        }
        break;
      
      default: 
        // if nothing else matches, do the default
        // default is optional
      break;
    }
  }
}

int turn_clockwise (int clockwise_turns) {
      
     if(count < countsperrev * clockwise_turns)
      clockwise();
    count++;
    return count;
}

int turn_anticlockwise (int anticlockwise_turns) {
  count = 0;
  if(count < countsperrev * anticlockwise_turns)
    anticlockwise();
  count++;
  return count;
}


void anticlockwise()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void clockwise()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void setOutput(int out)
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}
