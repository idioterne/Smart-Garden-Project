#include "Arduino.h"
#include "relay.h"

relay::relay(int RELAY_ONE, int RELAY_TWO, int RELAY_THREE)
{
    _RELAY_ONE = RELAY_ONE;
    _RELAY_TWO = RELAY_TWO;
    _RELAY_THREE = RELAY_THREE;
    _startTime = -1;
    _onTime = 0;

    pinMode(_RELAY_ONE, OUTPUT);
    pinMode(_RELAY_TWO, OUTPUT);
    pinMode(_RELAY_THREE, OUTPUT);
}

void relay::turnOn(int number)
{
    digitalWrite(_RELAY_ONE, LOW);
    digitalWrite(_RELAY_TWO, LOW);
    digitalWrite(_RELAY_THREE, LOW);
    switch (number)
    {
    case 3:
        digitalWrite(_RELAY_THREE, HIGH);
    case 2:
        digitalWrite(_RELAY_TWO, HIGH);
    case 1:
        digitalWrite(_RELAY_ONE, HIGH);
        break;
    }
}

void relay::turnOnTimer(int number, int delayTime)
{
    _startTime = millis();
    _onTime = delayTime;
    turnOn(number);
}

void relay::run()
{
  //Serial.println(millis() - _startTime);
  //Serial.println(millis() - _startTime >= _onTime);

    if (_startTime != -1 && millis() - _startTime >= _onTime)
    {
        _startTime = -1;
        turnOn(0);
    }
}
