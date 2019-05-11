#define relayOne 2
#define relayTwo 3
#define relayThree 4

#include "relay.h"
int i = 0;
relay relay(relayOne, relayTwo, relayThree);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
  relay.run();
  if(i==0){
    relay.turnOnTimer(2, 5000);
    i++;
  }
}
