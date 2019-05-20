#ifndef MQTTConnector_h
#define MQTTConnector_h

#include "ESP8266WiFi.h"
#include "PubSubClient.h"

class MQTTConnector{
public:
    MQTTConnector(char* ssid, char* ssPassword, char* mqttUser, char* mqttPassword, char* mqttTopic);
    void run();
    void setup();

private:
    char* _ssid;
    char* _ssPassword;
    char* _mqttUser;
    char* _mqttPassword;
    char* _mqttTopic;
    char* _mqttServer;
    int _mqttPort;

    WiFiClient _espClient;
    PubSubClient _client;

    static void _callback(char *topic, byte *payload, unsigned int length);
};

#endif
