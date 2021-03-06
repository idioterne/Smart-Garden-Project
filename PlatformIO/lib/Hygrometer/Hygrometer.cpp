#include "Arduino.h"
#include "Hygrometer.h"

Hygrometer::Hygrometer(int soilMoisturePercent, int PIN_SIGNAL, int PIN_POWER)
{
    _soilMoisturePercent = soilMoisturePercent;
    _PIN_SIGNAL = PIN_SIGNAL;
    _PIN_POWER = PIN_POWER;

    pinMode(_PIN_SIGNAL, INPUT);
    pinMode(_PIN_POWER, OUTPUT);

    _minValue = 450;
    _maxValue = 1023;
}

int Hygrometer::readValue()
{
    digitalWrite(_PIN_POWER, HIGH);
    delay(10);
    int rv = analogRead(_PIN_SIGNAL);
    delay(10);
    digitalWrite(_PIN_POWER, LOW);
    return rv;
}

int Hygrometer::getPercentage()
{
    double percentage = 100 * ((readValue() - _minValue) / (_maxValue - _minValue));
    return (int)percentage;
}

bool Hygrometer::isDry()
{
    return (_soilMoisturePercent > getPercentage());
}