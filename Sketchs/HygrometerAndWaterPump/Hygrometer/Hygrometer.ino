#include "Hygrometer.h"
Hygrometer hygrometer(50, A0);

void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println(hygrometer.getPercentage());
    Serial.println(hygrometer.isDry());
    Serial.println("#################");
    delay(2000);
    

}
