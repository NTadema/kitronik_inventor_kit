/*
Control RGB channels using buttons to increase and decrease values.

Red and Green are controlled by buttons, which trigger an interrupt.
Blue is controlled by reading the value of an analog input.

On an Arduino only two interrupts are available.
*/

#include <Arduino.h>

// Pin definitions
#define RED_IN 2
#define GREEN_IN 3
#define BLUE_IN A0

#define RED_OUT 9
#define GREEN_OUT 10
#define BLUE_OUT 11

// Assign variables used in interrupts
volatile int redValue = 0;
volatile int greenValue = 0;
int blueValue = 0;

// The interrupt routines for Red and Green values.
void OnRedButtonPressed()
{
    if (redValue < 250)
    {
        redValue += 5;
    }
    else
    {
        redValue = 0;
    }
}

void OnGreenButtonPressed()
{
    if (greenValue < 250)
    {
        greenValue += 5;
    }
    else
    {
        greenValue = 0;
    }
}

void setup()
{
  // Define pin modes connected to buttons
    pinMode(RED_IN, INPUT);
    pinMode(GREEN_IN, INPUT);

    // Setup intrrupts on the button pins
    attachInterrupt(digitalPinToInterrupt(RED_IN), OnRedButtonPressed, FALLING);
    attachInterrupt(digitalPinToInterrupt(GREEN_IN), OnGreenButtonPressed, FALLING);

    // Define pin modes for RGB LED output
    pinMode(RED_OUT, OUTPUT);
    pinMode(GREEN_OUT, OUTPUT);
    pinMode(BLUE_OUT, OUTPUT);

}

/*
Main loop reads the analogue value and converts the input analog range (0-1023) to the output value (0-255).
It then puts the PWN values to the RGB LED.
*/

void loop()
{
    int PotValue = analogRead(BLUE_IN);
    blueValue = map(PotValue, 0, 1023, 0, 255);
    analogWrite(RED_OUT, redValue);
    analogWrite(GREEN_OUT, greenValue);
    analogWrite(BLUE_OUT, blueValue);
    delay(50); // Small delay to stabilize the loop
}
