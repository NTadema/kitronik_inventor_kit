/*
Control a motor speed via PWM control of a Transistor.
Some pins have PWM capability. Commonly Pin 3.
This is used to control the base of a transistor which actually drives the motor.
*/

#include <Arduino.h>

const int MotorControlPin = 3; //Define a human readable name for the output controlling the transistor.

void setup() 
{
  pinMode(MotorControlPin, OUTPUT);
}

void loop() 
{
  int OutputValue;  
// First ramp up the output value - this speeds up the motor
  for(OutputValue=0; OutputValue<255;OutputValue++)
  {
    analogWrite(MotorControlPin,OutputValue);   
    delay(50);
  }
  //pause at full speed for 1/2 a second to make it more obvious we have got here.
  delay(500);
  //now ramp down the output value - this slows the motor down
  for(OutputValue=255; OutputValue>0;OutputValue--)
  {
    analogWrite(MotorControlPin,OutputValue);   
    delay(50);
  }
  //pause at stop for 1/2 a second to make it more obvious we have got here.
  delay(500); 
}