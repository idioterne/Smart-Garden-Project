#include "Hygrometer.h"
Hygrometer hygrometer(50, A0);

void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.print("Hygrometer percentage: ");
    Serial.println(hygrometer.getPercentage());
    
    Serial.print("Is dry? ");
    Serial.println(hygrometer.isDry());

    Serial.println("#################");
    delay(2000);
}
