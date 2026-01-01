/*
Measure how much "power" is generated from a fan,
using a seven segment display
*/

#include <Arduino.h>

/* 
  *  This array of 10 numbers shows the states of the pins for the segments 
  *  to display the appropriate number. This is used to simplify the code
  *  later - we can index the array to display the correct number.
 */
const bool Numbers[11][7] =  {
                        {1,1,1,1,1,1,0}, //zero
                        {0,1,1,0,0,0,0}, //one
                        {1,1,0,1,1,0,1}, //two
                        {1,1,1,1,0,0,1}, //three
                        {0,1,1,0,0,1,1}, //four
                        {1,0,1,1,0,1,1}, //five
                        {1,0,1,1,1,1,1}, //six
                        {1,1,1,0,0,0,0}, //seven
                        {1,1,1,1,1,1,1}, //eight
                        {1,1,1,0,0,1,1},  //nine
                        {0,0,0,0,0,0,0}  //Clear Display
  
};

#define clearDisplay 10

int displayNumber(int numberToDisplay)
{
  int pin = 2;
  for(int segment =0;segment<7;segment++) 
  {
    digitalWrite(pin, Numbers[numberToDisplay][segment]);  
    pin++;
  }
  return numberToDisplay;
}

void setup()
{
  // define pin modes
 pinMode(2,OUTPUT); //Segment A
 pinMode(3,OUTPUT); //Segment B
 pinMode(4,OUTPUT); //Segment C
 pinMode(5,OUTPUT); //Segment D
 pinMode(6,OUTPUT); //Segment E
 pinMode(7,OUTPUT); //Segment F
 pinMode(8,OUTPUT); //Segment G
 pinMode(9,OUTPUT); //Segment Decimal Point
 
 displayNumber(clearDisplay); //Make sure display is off
}

void loop() 
{
  int generatedValue = analogRead(A0); //Read the wind sensor value
  int displayValue = map(generatedValue,0,1023,0,9); //Map it to a single digit 0-9
  displayNumber(displayValue); //Show it on the display
  delay(100); //Update twice a second
}