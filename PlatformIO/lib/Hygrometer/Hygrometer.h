#ifndef Hygrometer_h
#define Hygrometer_h1

#include "Arduino.h"

class Hygrometer{
public:
    Hygrometer(int soilMoisturePercent, int PIN_SIGNAL, int PIN_POWER);
    int getPercentage();
    bool isDry();

private:
    //
    double _minValue;
    double _maxValue;
    int _soilMoisturePercent;
    int _PIN_SIGNAL;
    int _PIN_POWER;

    //
    int _readValue();
};

#endif
