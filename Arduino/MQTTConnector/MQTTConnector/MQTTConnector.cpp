#include "Arduino.h"
#include "MQTTConnector.h"

#include "ESP8266WiFi.h"
#include "PubSubClient.h"


MQTTConnector::MQTTConnector(char* ssid, char* ssPassword, char* mqttUser, char* mqttPassword, char* mqttTopic): _client(_espClient) {
    _ssid = ssid;
    _ssPassword = ssPassword;
    _mqttUser = mqttUser;
    _mqttPassword = mqttPassword;
    _mqttTopic = mqttTopic;

    _mqttServer = "m24.cloudmqtt.com";
    _mqttPort = 12327;

}

void MQTTConnector::setup() {
    Serial.begin(115200);

    WiFi.begin(_ssid, _ssPassword);

    while (WiFi.status() != WL_CONNECTED) {
        delay(2000);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network");

    _client.setServer(_mqttServer, _mqttPort);
    _client.setCallback(_callback);


    Serial.println("Success!");
    
    while (!_client.connected()) {
        Serial.println("Connecting to MQTT...");
        
        if (_client.connect("ESP8266Client", _mqttUser, _mqttPassword)) {
            Serial.println("connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(_client.state());
            //delay(2000);
        }

        //delay(2000);
    }

    _client.publish(_mqttTopic, "Hi from Landscape");
    _client.subscribe(_mqttTopic);
}

void MQTTConnector::run() {
    _client.loop();
}

void MQTTConnector::_callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);

    Serial.print("Message:");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }

    Serial.println();
    Serial.println("-----------------------");
}
