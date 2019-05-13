#include <Arduino.h>
#include "Hygrometer.h"
Hygrometer hygrometer(50, A0);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");
  delay(2000);
  Serial.println(hygrometer.getPercentage());

}