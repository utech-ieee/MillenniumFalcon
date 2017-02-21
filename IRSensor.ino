#include <SharpIR.h>

/* Project level constants */
#define RANGE_SENSOR_PIN  A0

/* Instances */
SharpIR rangeSensor(RANGE_SENSOR_PIN, 25, 93, 20150);

/* Setup function */
void setup()
{
  pinMode( RANGE_SENSOR_PIN, INPUT);
  Serial.begin(9600);
}

/* Infinite loop */
void loop()
{
  /* Check for obstacles */
  Serial.println( rangeSensor.distance() );
  

  /* Avoid reading before the new distance is sampled */
  delay( 100 );
}
