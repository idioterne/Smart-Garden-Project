#ifndef relay_h
#define relay_h

#include "Arduino.h"

class relay
{
public:
    relay(int RELAY_ONE, int RELAY_TWO, int RELAY_THREE);

    void turnOn(int number);
    void run();
    void turnOnTimer(int number, int delayTime);

private : 
    int _RELAY_ONE;
    int _RELAY_TWO;
    int _RELAY_THREE;
    int _startTime;
    int _onTime;
};

#endif
