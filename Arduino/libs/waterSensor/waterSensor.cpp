#include "Arduino.h"
#include "waterSensor.h"

waterSensor::waterSensor(int POWER_PIN, int SENSOR_PIN)
{
    pinMode(POWER_PIN, OUTPUT);
    pinMode(SENSOR_PIN, INPUT);

    _POWER_PIN = POWER_PIN;
    _SENSOR_PIN = SENSOR_PIN;
}

bool waterSensor::isLow()
{
    digitalWrite(_POWER_PIN, HIGH);
    int _WATER_VALUE = analogRead(_SENSOR_PIN); 
    digitalWrite(_POWER_PIN, LOW);
    return _WATER_VALUE < 200;
}
