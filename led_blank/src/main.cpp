#include <Arduino.h>

const int ledPins[] = {13, 12, 14, 27, 26, 25};
const int ledCount = 6;

void setup()
{
    for (int i = 0; i < ledCount; i++)
    {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
}

void loop()
{
    for (int i = 0; i < ledCount; i++)
    {
        digitalWrite(ledPins[i], HIGH);
        delay(200);
        digitalWrite(ledPins[i], LOW);
    }
}