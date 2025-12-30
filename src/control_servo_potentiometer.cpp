/*
Control the angle of a servo from a variable resistor

We read the value of the input analog, then use the map function to rescale it to a different range.
THe input is 0 - 1023, the output is scaled from 0 to 180 degrees.
*/

#include <Arduino.h>
#include <Servo.h>

#define ServoPin 3 //The pin that the Servo control line is attached to

Servo MyServo; //Create an instance of a servo represent the physical servo.

void setup()
{
 MyServo.attach(ServoPin); 
  
}
void loop()
{
  int PotValue = analogRead(A0);
  int ServoValue = map(PotValue, 0, 1023, 0, 180);
  MyServo.write(ServoValue);
 delay (100);
}