#ifndef WaterSensor_h
#define WaterSensor_h

#include "Arduino.h"

class WaterSensor
{
public:
    WaterSensor(int POWER_PIN, int SENSOR_PIN);

    bool isLow();

private:
    int _POWER_PIN;
    int _SENSOR_PIN;
    int _WATER_VALUE;
};

#endif

/*#ifndef waterSensor_h
#define waterSensor_h

#include "Arduino.h"

class waterSensor
{
private:
    int _POWER_PIN;
    int _SENSOR_PIN;
    int _WATER_VALUE;

public:
    waterSensor(int POWER_PIN, int SENSOR_PIN)
    {
        pinMode(POWER_PIN, OUTPUT);
        pinMode(SENSOR_PIN, INPUT);

        _POWER_PIN = POWER_PIN;
        _SENSOR_PIN = SENSOR_PIN;
    }

    bool isLow()
    {
        digitalWrite(_POWER_PIN, HIGH);
        int _WATER_VALUE = analogRead(_SENSOR_PIN);
        digitalWrite(_POWER_PIN, LOW);
        return _WATER_VALUE < 200;
    }
};

#endif

/*#include "Arduino.h"
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
*/
