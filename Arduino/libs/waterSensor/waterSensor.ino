#define signalInPin A0
#define powerOutPin D3

#include "waterSensor.h"

waterSensor wS(powerOutPin, signalInPin);
waterSensor wS2(D1, signalInPin);

void setup()
{
    // put your setup code here, to run once:
    //pinMode(signalInPin, INPUT);
    //pinMode(powerOutPin, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(A0, INPUT);
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    Serial.print("water 1: ");
    Serial.println(wS.isLow());
    //digitalWrite(powerOutPin, HIGH);
    //Serial.println(analogRead(signalInPin));
    //digitalWrite(powerOutPin, LOW);
    delay(1000);
    Serial.print("water 2: ");
    Serial.println(wS2.isLow());
    delay(1000);
    Serial.print("hygro: ");
    digitalWrite(D4, HIGH);
    delay(2000);
    Serial.println(analogRead(A0));
    digitalWrite(D4, LOW);
    delay(1000);
}
