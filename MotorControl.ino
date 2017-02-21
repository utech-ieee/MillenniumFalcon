//Wheel 1 Pins - Right
const int WHEEL_ONE_PIN_ONE = 4; 
const int WHEEL_ONE_PIN_TWO = 5; 
const int WHEEL_ONE_PWM = 6; 

//Wheel 2 Pins -Left
const int WHEEL_TWO_PIN_ONE = 8; 
const int WHEEL_TWO_PIN_TWO = 9; 
const int WHEEL_TWO_PWM = 10; 

//Wheel Speed 
const int WHEEL_SPEED = 140; 

int state;

void setup() 
{ 
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
 
void loop()
{ 
  if(Serial.available()>0)
  { 
    state = Serial.read();

    //Move Forward

    if(state == '1')
    { 
      Forward();

      Serial.println("Move Forward");

      state = 0;
    } 

    if(state == '2')
    { 
      Stop();

      Serial.println("Stop");

      state = 0;
    } 

    if(state == '3')
    { 
      Reverse();

      Serial.println("Reverse");

      state = 0;
    }

    if(state == '4')
    { 
      Left();

      Serial.println("Left");

      state = 0;
    }

    if(state == '5')
    { 
      Right();

      Serial.println("Right");

      state = 0;
    }
  }
} 

void Reverse()
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

void Forward()
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

void Right()
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

void Left()
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




