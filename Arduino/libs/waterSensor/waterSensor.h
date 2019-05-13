#ifndef waterSensor_h
#define waterSensor_h

#include "Arduino.h"

class waterSensor
{
public:
    waterSensor(int POWER_PIN, int SENSOR_PIN);

    bool isLow();

private:
    int _POWER_PIN;
    int _SENSOR_PIN;
    int _WATER_VALUE;
};

#endif
