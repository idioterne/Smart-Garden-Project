#ifndef WaterPump_h
#define WaterPump_h
#include "Arduino.h"

class WaterPump{
public:
    WaterPump(int PIN);
    void stop();
    void start();

private:
    //
    int _PIN;
};

#endif
