#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay
{
public:
    Relay(int RELAY_ONE, int RELAY_TWO, int RELAY_THREE);

    void turnOn(int number);
    void run();
    void turnOffTimer(int delayTime);

private:
    int _RELAY_ONE;
    int _RELAY_TWO;
    int _RELAY_THREE;
    int _startTime;
    int _onTime;
};

#endif

/*
#ifndef relay_h
#define relay_h

#include "Arduino.h"

class Relay
{
private:
    int _RELAY_ONE;
    int _RELAY_TWO;
    int _RELAY_THREE;
    int _startTime;
    int _onTime;

public:
    Relay(int RELAY_ONE, int RELAY_TWO, int RELAY_THREE)
    {
        pinMode(RELAY_ONE, OUTPUT);
        pinMode(RELAY_TWO, OUTPUT);
        pinMode(RELAY_THREE, OUTPUT);

        _RELAY_ONE = RELAY_ONE;
        _RELAY_TWO = RELAY_TWO;
        _RELAY_THREE = RELAY_THREE;
        _startTime = -1;
        _onTime = 0;
    }

    void turnOn(int number)
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

    void run()
    {
        //Serial.println(millis() - _startTime);
        //Serial.println(millis() - _startTime >= _onTime);

        if (_startTime != -1 && millis() - _startTime >= _onTime)
        {
            _startTime = -1;
            turnOn(0);
        }
    }

    void turnOnTimer(int number, int delayTime)
    {
        _startTime = millis();
        _onTime = delayTime;
        turnOn(number);
    }
};

#endif

/*
#include "Arduino.h"
#include "Relay.h"

Relay::Relay(int RELAY_ONE, int RELAY_TWO, int RELAY_THREE)
{
    pinMode(RELAY_ONE, OUTPUT);
    pinMode(RELAY_TWO, OUTPUT);
    pinMode(RELAY_THREE, OUTPUT);

    _RELAY_ONE = RELAY_ONE;
    _RELAY_TWO = RELAY_TWO;
    _RELAY_THREE = RELAY_THREE;
    _startTime = -1;
    _onTime = 0;
}

void Relay::turnOn(int number)
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

void Relay::turnOnTimer(int number, int delayTime)
{
    _startTime = millis();
    _onTime = delayTime;
    turnOn(number);
}

void Relay::run()
{
  //Serial.println(millis() - _startTime);
  //Serial.println(millis() - _startTime >= _onTime);

    if (_startTime != -1 && millis() - _startTime >= _onTime)
    {
        _startTime = -1;
        turnOn(0);
    }
}

*/