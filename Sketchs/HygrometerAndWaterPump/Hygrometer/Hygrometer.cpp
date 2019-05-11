#include "Arduino.h"
#include "Hygrometer.h"

Hygrometer::Hygrometer(int soilMoisturePercent, int PIN){
  
    //
    int _soilMoisturePercent = soilMoisturePercent;
    int _PIN = PIN;

    //
    pinMode(_PIN, INPUT);

    //
    int _minValue = 300;
    int _maxValue = 973;
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
