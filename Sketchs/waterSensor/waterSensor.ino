#define signalInPin 0
#define powerOutPin 3

#include "waterSensor.h"

waterSensor waterSensor(powerOutPin, signalInPin);

void setup() {
  // put your setup code here, to run once:
  //pinMode(signalInPin, INPUT);
  //pinMode(powerOutPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(waterSensor.isLow());
  delay(1000);
}
