#include "Arduino.h"
#include "WaterPump.h"

WaterPump::WaterPump(int PIN){
  
    //
    _PIN = PIN;

    //
    pinMode(_PIN, OUTPUT);

}

int WaterPump::start(){
    analogWrite(PUMP_PIN, 255);
}

bool WaterPump::stop(){
    analogWrite(PUMP_PIN, 0);
}
