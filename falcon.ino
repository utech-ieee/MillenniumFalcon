#include <SharpIR.h>
#define sensor A0 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)

//Wheel 1 Pins - Right
const int WHEEL_ONE_PIN_ONE = 4; 
const int WHEEL_ONE_PIN_TWO = 5; 
const int WHEEL_ONE_PWM = 6; 

//Wheel 2 Pins -Left
const int WHEEL_TWO_PIN_ONE = 8; 
const int WHEEL_TWO_PIN_TWO = 9; 
const int WHEEL_TWO_PWM = 10; 

//Wheel Speed 
int WHEEL_SPEED = 140; 

int state;


#define ir A0
#define model 20150


int dis;
void setup(){

  
  //Wheel 1 
  pinMode(WHEEL_ONE_PIN_ONE, OUTPUT); 
  pinMode(WHEEL_ONE_PIN_TWO, OUTPUT); 
  pinMode(WHEEL_ONE_PWM, OUTPUT); 

 
  //Wheel 2 
  pinMode(WHEEL_TWO_PIN_ONE, OUTPUT); 
  pinMode(WHEEL_TWO_PIN_TWO, OUTPUT);
  pinMode(WHEEL_TWO_PWM, OUTPUT); 

  Serial.begin(9600);
}



void loop(){
  dis = IR();
 // Serial.println(distance);
  if (dis < 20)
  {
    Stop();
    //delay(2000);
    Reverse(120);
    delay(500);
    Right(100);
    delay(250);
  }
  else{
    Forward(90);
  }
}

void Reverse(int WHEEL_SPEED)
{
  //Wheel 1 
  digitalWrite(WHEEL_ONE_PIN_ONE, LOW); 
  digitalWrite(WHEEL_ONE_PIN_TWO, HIGH); 

  analogWrite(WHEEL_ONE_PWM, WHEEL_SPEED); 
 
  //Wheel 2 
  digitalWrite(WHEEL_TWO_PIN_ONE, HIGH); 
  digitalWrite(WHEEL_TWO_PIN_TWO, LOW); 

  analogWrite(WHEEL_TWO_PWM, WHEEL_SPEED); 
}

void Forward(int WHEEL_SPEED)
{
  //Wheel 1 
  digitalWrite(WHEEL_ONE_PIN_ONE, HIGH); 
  digitalWrite(WHEEL_ONE_PIN_TWO, LOW); 

  analogWrite(WHEEL_ONE_PWM, WHEEL_SPEED); 
 
  //Wheel 2 
  digitalWrite(WHEEL_TWO_PIN_ONE, LOW); 
  digitalWrite(WHEEL_TWO_PIN_TWO, HIGH); 

  analogWrite(WHEEL_TWO_PWM, WHEEL_SPEED); 
}

void Stop()
{
  //Wheel 1 
  digitalWrite(WHEEL_ONE_PIN_ONE, LOW); 
  digitalWrite(WHEEL_ONE_PIN_TWO, LOW); 
  
  analogWrite(WHEEL_ONE_PWM, 0); 
 
  //Wheel 2 
  digitalWrite(WHEEL_TWO_PIN_ONE, LOW); 
  digitalWrite(WHEEL_TWO_PIN_TWO, LOW); 

  analogWrite(WHEEL_TWO_PWM, 0); 
}

void Right(int WHEEL_SPEED)
{
  //Wheel 1 
  digitalWrite(WHEEL_ONE_PIN_ONE, LOW); 
  digitalWrite(WHEEL_ONE_PIN_TWO, HIGH); 
  
  analogWrite(WHEEL_ONE_PWM, WHEEL_SPEED); 

  //Wheel 2
  digitalWrite(WHEEL_TWO_PIN_ONE, LOW); 
  digitalWrite(WHEEL_TWO_PIN_TWO, HIGH); 

  analogWrite(WHEEL_TWO_PWM, WHEEL_SPEED); 
}

void Left(int WHEEL_SPEED)
{
  //Wheel 1 
  digitalWrite(WHEEL_ONE_PIN_ONE, HIGH); 
  digitalWrite(WHEEL_ONE_PIN_TWO, LOW); 
  
  analogWrite(WHEEL_ONE_PWM, WHEEL_SPEED); 

  //Wheel 2
  digitalWrite(WHEEL_TWO_PIN_ONE, HIGH); 
  digitalWrite(WHEEL_TWO_PIN_TWO, LOW); 

  analogWrite(WHEEL_TWO_PWM, WHEEL_SPEED); 
}


int IR(){
   // 5v
  float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  Serial.println(distance);
  delay(100); // slow down serial port 
  
  if (distance <= 30){
    Serial.println(distance);   // print the distance
  }
  return distance;
  
  }
