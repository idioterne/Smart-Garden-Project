#include <Arduino.h>
#include "Hygrometer.h"
#include "WaterPump.h"
#include "waterSensor.h"
#include "relay.h"

WaterPump pumpWaterAndMix(D2);
WaterPump periFert(D8);
Hygrometer hygrometer(50, A0, D4);
WaterSensor waterSensor1(D1, A0);
WaterSensor waterSensor2(D3, A0);
Relay relay(D6, D7, D5);

int timeToRunPeriPump;


void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("Starting pump");
  // waterpump.startPump();
  // delay(3000);
  // Serial.println("Stopping pump");
  // waterpump.stopPump();
  // relay.turnOn(3);
  // delay(3000);
  // Serial.print("hygro: ");
  // Serial.println(hygrometer.getPercentage());
  // Serial.println("==============================================");
  // Serial.print("ws1: ");
  // Serial.println(waterSensor1.isLow());
  // Serial.println("==============================================");
  // Serial.print("ws2: ");
  // Serial.println(waterSensor2.isLow());
  // Serial.println("==============================================");
  // if(hygrometer.isDry())
  // {
  //   waterpump.startPump();
  // }else{
  //   waterpump.stopPump();
  // }
  // relay.turnOn(1);
  // delay(1000);

  hygrometer.readValue();
  if(hygrometer.isDry) //readvalue() is 10% lower than desired readvalue() instead
  {
    pumpWaterAndMix.startPump();
    delay(20*1000);
    pumpWaterAndMix.stopPump();
  }


}


int setDesireDryness(){
  int result = 10;
  return result;
}