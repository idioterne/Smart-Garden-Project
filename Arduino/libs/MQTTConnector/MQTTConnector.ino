#include "MQTTConnector.h"

#include "string.h"
#include "ArduinoJson.h"

char* ssid = "CPHBUS-STUDENT";
char* ssPassword = "";
char* mqttUser = "Device";
char* mqttPassword = "device";
char* mqttTopic = "landscape";

StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

MQTTConnector mqttConnector(ssid, ssPassword, mqttUser, mqttPassword, mqttTopic);

void setup() {
    Serial.begin(9600);
   mqttConnector.setup();
}

void loop() {
  mqttConnector.run();
  // interval
  //char* massage = json(true, false, 67, 2);
  //mqttConnector.sendJson(massage);

  char* response = mqttConnector.getResponse();
  

  if (strlen(response) > 0) {
    Serial.print("Reponse:: ");
    
    for (int i = 0; i < strlen(response); i++)
    {
        Serial.print(response[i]);
    }

    Serial.println();
  }

  mqttConnector.resetResponse();
  delay(3000);
}

char* json(boolean water, boolean fertilizer, int hygrometer, int lightState) {
  root["hygrometer"] = hygrometer;
  root["waterlevel"] = water;
  root["fertilizerlevel"] = fertilizer;
  root["lightState"] = lightState;
  
  char message[256];
  root.printTo(message, sizeof(message));
  return message;
}
