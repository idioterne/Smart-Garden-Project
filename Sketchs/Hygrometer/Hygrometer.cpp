#include "Arduino.h"
#include "Hygrometer.h"

Hygrometer::Hygrometer(int soilMoisturePercent, int PIN){
  
    //
    _soilMoisturePercent = soilMoisturePercent;
    _PIN = PIN;

    //
    pinMode(_PIN, INPUT);

    //
    _minValue = 0;
    _maxValue = 973;
}

int Hygrometer::getPercentage(){
  int percentage = 100*((_readValue()-_minValue)/(_maxValue-_minValue));
  return abs(percentage - 100);
}

bool Hygrometer::isDry(){
  return (_soilMoisturePercent > getPercentage());
}

int Hygrometer::_readValue(){
  return analogRead(_PIN);
}
