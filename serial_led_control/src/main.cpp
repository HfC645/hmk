#include <Arduino.h>

void toggleLed(int index);

const int ledPins[] = {13, 12, 14, 27, 26, 25};
const int ledCount = 6;

bool ledStates[] = {false, false, false, false, false, false};

void setup()
{
    Serial.begin(115200);

    for (int i = 0; i < ledCount; i++)
    {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }

    Serial.println("ESP32 Serial LED Control");
    Serial.println("Input 1~6 to control LEDs");
}

void loop()
{
    if (Serial.available())
    {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();

        if (cmd == "1")
            toggleLed(0);
        else if (cmd == "2")
            toggleLed(1);
        else if (cmd == "3")
            toggleLed(2);
        else if (cmd == "4")
            toggleLed(3);
        else if (cmd == "5")
            toggleLed(4);
        else if (cmd == "6")
            toggleLed(5);
        else
            Serial.println("Invalid Command");
    }
}

void toggleLed(int index)
{
    ledStates[index] = !ledStates[index];

    digitalWrite(
        ledPins[index],
        ledStates[index] ? HIGH : LOW);

    Serial.print("LED");
    Serial.print(index + 1);

    if (ledStates[index])
        Serial.println(" ON");
    else
        Serial.println(" OFF");
}