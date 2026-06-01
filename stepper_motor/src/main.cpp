#include <Arduino.h>

const int IN1 = 13;
const int IN2 = 12;
const int IN3 = 14;
const int IN4 = 27;

// 半步驱动序列
const int stepSequence[8][4] =
{
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,1,1},
    {0,0,0,1},
    {1,0,0,1}
};

void stepMotor(int stepIndex)
{
    digitalWrite(IN1, stepSequence[stepIndex][0]);
    digitalWrite(IN2, stepSequence[stepIndex][1]);
    digitalWrite(IN3, stepSequence[stepIndex][2]);
    digitalWrite(IN4, stepSequence[stepIndex][3]);
}

void rotateForward(int steps)
{
    for(int i = 0; i < steps; i++)
    {
        stepMotor(i % 8);
        delay(2);
    }
}

void rotateBackward(int steps)
{
    for(int i = 0; i < steps; i++)
    {
        stepMotor(7 - (i % 8));
        delay(2);
    }
}

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    Serial.begin(115200);

    Serial.println("28BYJ-48 Stepper Test");
}

void loop()
{
    Serial.println("Forward One Revolution");

    rotateForward(2048);

    delay(2000);

    Serial.println("Backward One Revolution");

    rotateBackward(2048);

    delay(2000);
}