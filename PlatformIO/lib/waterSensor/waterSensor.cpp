
#include "Arduino.h"
#include "WaterSensor.h"

WaterSensor::WaterSensor(int POWER_PIN, int SENSOR_PIN)
{
    _POWER_PIN = POWER_PIN;
    _SENSOR_PIN = SENSOR_PIN;

    pinMode(_POWER_PIN, OUTPUT);
    pinMode(_SENSOR_PIN, INPUT);
}

bool WaterSensor::isLow()
{
    digitalWrite(_POWER_PIN, HIGH);
    int _WATER_VALUE = analogRead(_SENSOR_PIN);
    digitalWrite(_POWER_PIN, LOW);
    return _WATER_VALUE < 200;
}
