#include <Arduino.h>
#include "Hygrometer.h"
#include "WaterPump.h"
#include "waterSensor.h"
#include "relay.h"

WaterPump waterpump(D2);
Hygrometer hygrometer(50, A0, D4);
waterSensor waterSensor1(D1, A0);
waterSensor waterSensor2(D3, A0);
relay relay(D6, D7, D5);

void setup() {
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
  relay.turnOn(3);
  delay(3000);
  Serial.print("hygro: ");
  Serial.println(hygrometer.getPercentage());
  Serial.println("==============================================");
  Serial.print("ws1: ");
  Serial.println(waterSensor1.isLow());
  Serial.println("==============================================");
  Serial.print("ws2: ");
  Serial.println(waterSensor2.isLow());
  Serial.println("==============================================");
  if(hygrometer.isDry())
  {
    waterpump.startPump();
  }else{
    waterpump.stopPump();
  }
  relay.turnOn(1);
  delay(1000);


}