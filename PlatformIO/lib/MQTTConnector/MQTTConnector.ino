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

  String response = mqttConnector.getResponse();

  if (response.length() > 0) {
    Serial.print("Reponse:: ");

    Serial.println(response);
    String field = response.substring(2, response.indexOf(":")-1);
    String value = response.substring(response.indexOf(":")+1, response.length()-1);

    if(field.equals("calibrate")){
        Serial.print("cali:");
        Serial.println(value.equals("true"));
    }else if(field.equals("lightState")){
        Serial.print("light:");
        Serial.println(value);
    }
  }

  mqttConnector.resetResponse();
  //delay(5000);
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
