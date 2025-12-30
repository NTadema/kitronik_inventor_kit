/*
Switch on and off an LED via an interrupt, and change its brightness in relation to a variable reisitor input

A switch is connected to +5 and Pin 2. 
This triggers an interrupt on the falling edge (i.e. when it has been pressed and released).
The Interrupt toggles a variable which is used to turn on or off the PWN output on Pin 3.
Because this is used in both the main loop and the interrupt it is declared 'volatile'

The LED brightness is controlled by PWM on pin 3. The variable resistor is read into Analog input A0,
and its value is transfered to the PWN output.
*/

#include <Arduino.h>

const int SwitchInputPin = 2; //Define a human readable name for the input the switch is connected to.
const int LEDDrivePin = 3; // the pin we will use to drive the LED

//Variables used in interrupts are declared volatile, as they may be changed since you last looked at them
volatile byte ButtonState = LOW; //This variable tracks the button clicks.

void setup() 
{
  pinMode(LEDDrivePin, OUTPUT);
  pinMode(SwitchInputPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(SwitchInputPin), OnButtonPressed, FALLING);
}

// This is the interrupt routine that is attached to pin 2 and triggers when the button is released.
void OnButtonPressed() 
{
  ButtonState = !ButtonState;
}


void loop() 
{
  int PotValue = analogRead(A0);  //This variable reads the voltage that the potentiometer is adjusted to
  //Now decide what to do.
  if(ButtonState) //Then we want to turn on the LED
  {
    PotValue = map(PotValue, 0, 1023, 0, 255);  //Due to the ADC and PWM work on different scales, it is required to map the ADC to the same as the PWM
    analogWrite(LEDDrivePin,PotValue);   // turn the LED on to the value of the potentiometer
  }
  else
  {
    digitalWrite(LEDDrivePin, LOW);    // turn the LED off
  }
  
}