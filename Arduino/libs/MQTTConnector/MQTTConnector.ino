#include "MQTTConnector.h"

char* ssid = "CPHBUS-STUDENT";
char* ssPassword = "";
char* mqttUser = "Device";
char* mqttPassword = "device";
char* mqttTopic = "landscape";

MQTTConnector mqttConnector(ssid, ssPassword, mqttUser, mqttPassword, mqttTopic);

void setup() {
   mqttConnector.setup();
}

void loop() {
  mqttConnector.run();
}
