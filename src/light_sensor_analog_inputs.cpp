/*
Turns an LED on  and off in response to changing light level.

Most Arduinos have an on-board LED you can control.
LED_BUILTIN is set to the correct LED pin independent of which board is used.

A photo Transistor is connnected to Analogue in 0, pulling it up to 5V.
As the light level veries the analogue input will vary, with bright light being nearer full scale, and dark being near to 0.
We can then use this to turn on the in build LED as it gets dark.
*/


#include <Arduino.h>

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin  for the LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

const int LightLevelToSwitchAt = 200; //set to about 20 percent of scale


// the loop function runs forever, reading the light level and turning on the LED if its dark

void loop() 
{
  //First read the state of the button.
  int LightValue = analogRead(A0);
  //Now decide what to do.
  if(LightValue > LightLevelToSwitchAt) //Then it is bright, so turn off the LED
  {
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  }
  else
  {
    digitalWrite(LED_BUILTIN, HIGH);    // turn the LED on (HIGH is the voltage level)
  }
}