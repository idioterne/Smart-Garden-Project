#include "Arduino.h"
#include "WaterPump.h"

WaterPump::WaterPump(int PIN){
  
    //
    _PIN = PIN;

    //
    pinMode(_PIN, OUTPUT);

}

void WaterPump::startPump(){
    digitalWrite(_PIN, HIGH);
}

void WaterPump::stopPump(){
    digitalWrite(_PIN, LOW);
}
