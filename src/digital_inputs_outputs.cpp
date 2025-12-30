/*
Turns an LED on  and off in response to a press on the button that is connected to Pin 2.

Most Arduinos have an on-board LED you can control.
LED_BUILTIN is set to the correct LED pin independent of which board is used.

The switch is connected from the 5V output header to input pin 2.
*/

#include <Arduino.h>

const int SwitchInputPin = 2; //Define the input that the switch is connected to

void setup() {
  // initialize pin for the LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // Initialize the switch pin as an input
  pinMode (SwitchInputPin, INPUT);
}


//A variable to hold the value of the button
boolean buttonValue;

void loop() 
{
  //Read state of the button
  buttonValue = digitalRead(SwitchInputPin);
  //Decide what to do based on the button state
  if(buttonValue)
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }
}