#include <Arduino.h>
#include "Hygrometer.h"
#include "WaterPump.h"
#include "waterSensor.h"
#include "relay.h"
#include "MQTTConnector.h"
#include "string.h"
#include "ArduinoJson.h"

//Devices
WaterPump pumpWaterAndMix(D2);
WaterPump periFert(D8);
Hygrometer hygrometer(50, A0, D4);
WaterSensor waterSensor(D1, A0);
WaterSensor fertSensor(D3, A0);
Relay relay(D6, D7, D5);

//MQTT
char *ssid = "CPHBUS-STUDENT";
char *ssPassword = "";
char *mqttUser = "Device";
char *mqttPassword = "device";
char *mqttTopic = "landscape";
StaticJsonBuffer<200> jsonBuffer;
JsonObject &root = jsonBuffer.createObject();
MQTTConnector mqttConnector(ssid, ssPassword, mqttUser, mqttPassword, mqttTopic);

//Duration declarations
const int SECOND = 1000;
const int MINUTE = SECOND * 60;
const int HOUR = MINUTE * 60;
const int DAY = HOUR * 24;

//Non blocking time vars
const long FERT_INTERVAL = 1 * DAY; //Days
const long HYGROMETER_INTERVAL = 10 * MINUTE;
const long UPDATE_STATS_INTERVAL = 5 * MINUTE;
const long PUMP_DURATION = 20 * SECOND;
const long FERT_DURATION = 5 * SECOND;
long fertPrevTime = 0;
long pumpPrevTime = 0;
long updateStatsPrevTime = 0;
long currTime;

//Stats
int lightState = 0;
int desiredMoisture;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    desiredMoisture = hygrometer.readValue() / 2; //setting a low default desiredMoisture, so you can set a proper desiredMoisture later on
}

void loop()
{
    //Maintenance
    currTime = millis();
    mqttConnector.run();
    relay.run();

    runFertilizer();
    runPump();

    //MQTT
    handleMQTT();
    if (currTime - updateStatsPrevTime >= UPDATE_STATS_INTERVAL)
    {
        sendMQTT();
        updateStatsPrevTime = currTime;
    }
}

void handleMQTT()
{
    String response = mqttConnector.getResponse();

    if (response.length() > 0)
    {
        Serial.print("Reponse:: ");

        Serial.println(response);
        String field = response.substring(2, response.indexOf(":") - 1);
        String value = response.substring(response.indexOf(":") + 1, response.length() - 1);

        if (field.equals("calibrate"))
        {
            if (value.equals("true"))
            {
                desiredMoisture = hygrometer.readValue();
            }
        }
        else if (field.equals("lightState"))
        {
            lightState = value.toInt();
            relay.turnOn(lightState);
        }
        else if (field.equals("lightTimer"))
        {
            relay.turnOffTimer(value.toInt());
        }
    }

    mqttConnector.resetResponse();
}

void sendMQTT()
{
    root["hygrometer"] = hygrometer.readValue();
    root["waterlevel"] = waterSensor.isLow();
    root["fertilizerlevel"] = fertSensor.isLow();
    root["lightState"] = lightState;

    char message[256];
    root.printTo(message, sizeof(message));
    mqttConnector.sendJson(message);
}

void runFertilizer()
{
    if (currTime - fertPrevTime >= FERT_INTERVAL && !fertSensor.isLow()) //Time to start peristaltic pump
    {
        periFert.startPump();

        if (currTime - fertPrevTime >= FERT_INTERVAL + FERT_DURATION) //Time to stop peristaltic pump
        {
            periFert.stopPump();
            fertPrevTime = currTime;
        }
    }
}

void runPump()
{
    if (currTime - pumpPrevTime >= HYGROMETER_INTERVAL) //Start pump if soil is 10% dryer than desired value
    {
        if (hygrometer.readValue() < desiredMoisture * 0.90)
        {
            pumpWaterAndMix.startPump();

            if (currTime - pumpPrevTime >= HYGROMETER_INTERVAL + PUMP_DURATION)
            {
                pumpWaterAndMix.stopPump();
                pumpPrevTime = currTime;
            }
        }
        else
        {
            pumpPrevTime = currTime;
        }
    }
}