/*
Control the tone of a piezo buzzer with a pot.

We read the value of the input analog, then use the map function to rescale it to a different range.
THe input is 0 - 1023, the output is scaled from 120Hz to 5KHz.
*/

#include <Arduino.h>

#define TonePin 3 // The pin that the Piezo is attached to

void setup()
{
  // nothing to do here - analogRead uses dedicated pins, and tone sets the pin up as part of the function
}
void loop()
{
  int PotValue = analogRead(A0);
  int ToneValue = map(PotValue, 0, 1023, 120, 5000);
  tone(TonePin,ToneValue);
}

