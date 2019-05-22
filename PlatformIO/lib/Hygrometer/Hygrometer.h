#ifndef Hygrometer_h
#define Hygrometer_h

#include "Arduino.h"

class Hygrometer
{
public:
    Hygrometer(int soilMoisturePercent, int PIN);
    int getPercentage();
    bool isDry();

private:
    //
    int _minValue;
    int _maxValue;
    int _soilMoisturePercent;
    int _PIN;

    //
    int _readValue();
};

#endif
