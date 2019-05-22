#include <Arduino.h>
#include "waterSensor.h"
// #include "Hygrometer.h"
// Hygrometer hygrometer(50, A0);

WaterSensor waterSensor(3, 1);

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    // Serial.println("Hello World");
    Serial.println(waterSensor.isLow());
    delay(2000);
    // Serial.println(hygrometer.getPercentage());
}