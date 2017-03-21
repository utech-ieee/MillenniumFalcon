int motorPin1 = 8;  
int motorPin2 = 9;    
int motorPin3 = 10;   
int motorPin4 = 11;    

int t = 0;
int pass = 0;
int motorSpeed = 1200;  
int count = 0;          // count of steps made
int countsperrev = 512; // number of steps per full revolution
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

int code[] = {2, 1, 3, 5, 4};

void setup() {
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}


void loop(){
  if (Serial.available() > 0) {  
    char numberOfTurns = Serial.parseInt();
    for(int i = (numberOfTurns*512*2); i >= 0; i--){
      turn(numberOfTurns);
    }
      
  }
}

int turn (int turns) {
      
     if(count < countsperrev * turns)
      clockwise();
    else if (count == countsperrev * 2 * turns)
      count = 0;
    else
      anticlockwise();
    count++;
    Serial.println(count);
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
