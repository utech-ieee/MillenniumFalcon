#include <Encoder.h>

//Wheel 1 Pins - Right
const int WHEEL_ONE_PIN_ONE = 5; 
const int WHEEL_ONE_PIN_TWO = 4; 
const int WHEEL_ONE_PWM = 6; 

//Wheel 2 Pins -Left
const int WHEEL_TWO_PIN_ONE = 8; 
const int WHEEL_TWO_PIN_TWO = 9; 
const int WHEEL_TWO_PWM = 10; 

//Wheel Speed 
//int WHEEL_SPEED = 140; 

int state;
// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knobLeft(2, 3);
Encoder knobRight(20, 21);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  Serial.println("TwoKnobs Encoder Test:");
}

long positionLeft  = -999;
long positionRight = -999;

void loop() 
{
  Forward(70, 70);
  long newLeft, newRight;
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  if (newLeft != positionLeft || newRight != positionRight) {
    Serial.print("Left = ");
    Serial.print(newLeft);
    Serial.print(", Right = ");
    Serial.print(newRight);
    Serial.println();
    positionLeft = newLeft;
    positionRight = newRight;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    knobLeft.write(0);
    knobRight.write(0);
  }
}
void Reverse(int right, int left)
{
  //Wheel 1 
  digitalWrite(WHEEL_ONE_PIN_ONE, LOW); 
  digitalWrite(WHEEL_ONE_PIN_TWO, HIGH); 

  analogWrite(WHEEL_ONE_PWM, right); 
 
  //Wheel 2 
  digitalWrite(WHEEL_TWO_PIN_ONE, HIGH); 
  digitalWrite(WHEEL_TWO_PIN_TWO, LOW); 

  analogWrite(WHEEL_TWO_PWM, left); 
}

void Forward(int right, int left)
{
  //Wheel 1 
  digitalWrite(WHEEL_ONE_PIN_ONE, HIGH); 
  digitalWrite(WHEEL_ONE_PIN_TWO, LOW); 

  analogWrite(WHEEL_ONE_PWM, right); 
 
  //Wheel 2 
  digitalWrite(WHEEL_TWO_PIN_ONE, LOW); 
  digitalWrite(WHEEL_TWO_PIN_TWO, HIGH); 

  analogWrite(WHEEL_TWO_PWM, left); 
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
