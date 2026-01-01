/*
Control a set of LEDs to show the charge in a capacitor.
*/

#include <Arduino.h>

//define some human readable shorcutys for the pins of each LED
#define RED 2
#define ORANGE 3
#define YELLOW 4
#define GREEN 5


void setup()
{
  // define pins to outputs for driving the LEDs
  pinMode(RED,OUTPUT); 
  pinMode(ORANGE,OUTPUT); 
  pinMode(YELLOW,OUTPUT); 
  pinMode(GREEN,OUTPUT);
 
}

void loop() 
{
  //first read in the capacitor voltage
  int CapVoltage = analogRead(A0);

  //do a very quick but rough conversion to percentage (1023/10 => 102% full scale)
  int CapPercent = CapVoltage/10;
  
  //now we decide which LEDs to turn on)
  if((CapPercent > 25) &&(CapPercent<=50)) //Red at 25% and up
  {
    digitalWrite(RED,1);
  }
  else if((CapPercent > 50) &&(CapPercent<=75)) //Red and ORange at 50% and up
  {
    digitalWrite(RED,1);
    digitalWrite(ORANGE,1);
  }
  else if((CapPercent > 75) &&(CapPercent<=90)) // Red, Orange and Yellow at 75% and up
  {
    digitalWrite(RED,1);
    digitalWrite(ORANGE,1);
    digitalWrite(YELLOW,1);
  }  
  else if(CapPercent > 90) //all 4 when we get over 90%
  {
    digitalWrite(RED,1);
    digitalWrite(ORANGE,1);
    digitalWrite(YELLOW,1);
    digitalWrite(GREEN,1);
  }
  else // must be below 25%, so turn off all the LEDs
  {
    digitalWrite(RED,0);
    digitalWrite(ORANGE,0);
    digitalWrite(YELLOW,0);
    digitalWrite(GREEN,0);
  }
}