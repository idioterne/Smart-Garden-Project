#include <Arduino.h>
#include "Hygrometer.h"
#include "WaterPump.h"

WaterPump waterpump(D3);
Hygrometer hygrometer(50, A0);

WaterSensor waterSensor(3, 1);

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    Serial.println("Starting pump");
    waterpump.startPump();
    delay(3000);
    Serial.println("Stopping pump");
    waterpump.stopPump();
    delay(3000);
    // Serial.println(hygrometer.getPercentage());
    Serial.println("==============================================");
}