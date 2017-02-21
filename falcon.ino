#include <SharpIR.h>

//Project level constants 
#define RANGE_SENSOR_PIN  A0

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


SharpIR rangeSensor(RANGE_SENSOR_PIN, 25, 93, 20150);

int distance; 

void setup(){

	pinMode( RANGE_SENSOR_PIN, INPUT);
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
	distance = rangeSensor.distance();
	if (distance < 25)
	{
		Stop();
		delay(2000);
		Right(100);
		delay(3000);
	}
	else{
		Forward(140);
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


