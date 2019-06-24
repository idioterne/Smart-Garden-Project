#include <Arduino.h>
#include "Hygrometer.h"
#include "WaterPump.h"
#include "waterSensor.h"
#include "relay.h"
#include "MQTTConnector.h"
#include "string.h"
#include "ArduinoJson.h"

//Devices
WaterPump pumpWater(D2);
WaterPump pumpMix(D1);
WaterPump periFert(D8);
Hygrometer hygrometer(50, A0, D4);
WaterSensor waterSensor(D0, A0);
WaterSensor fertSensor(D3, A0);
Relay relay(D6, D7, D5);

//MQTT
char *ssid = "CPHBUS-STUDENT";
char *ssPassword = "";
char *mqttUser = "Device";
char *mqttPassword = "device";
char *mqttTopic = "landscape";
StaticJsonBuffer<200> jsonBuffer;
JsonObject &json = jsonBuffer.createObject();
MQTTConnector mqttConnector(ssid, ssPassword, mqttUser, mqttPassword, mqttTopic);

//Time declarations
const int DROPLET_TIME = 350;
const int SECOND = 1000;
const int MINUTE = SECOND * 60;
const int HOUR = MINUTE * 60;
const int DAY = HOUR * 24;

//Non blocking time vars
const long FERT_INTERVAL = 1 * MINUTE;          //1 * DAY; //Days
const long HYGROMETER_INTERVAL = 1 * SECOND;    //10 * MINUTE;
const long UPDATE_STATS_INTERVAL = 10 * SECOND; //5 * MINUTE;
const long PUMP_DURATION = 5 * SECOND;
const long FERT_DURATION = 10 * DROPLET_TIME;
long fertPrevTime = 0;
long pumpPrevTime = 0;
long updateStatsPrevTime = 0;
long currTime;

//testing
bool testingPumpWater = false;
bool testingPeriFert = false;
long testStartTime = 0;

//Stats
int lightState = 0;
int desiredMoisture = 0;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    mqttConnector.setup();
}

void handleMQTT()
{
    String response = mqttConnector.getResponse();

    delay(10);

    if (response.length() > 0)
    {
        Serial.print("Reponse: ");

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
        else if (field.equals("testWaterPump"))
        {
            testStartTime = currTime;
            testingPumpWater = true;
        }
        else if (field.equals("testPeriFert"))
        {
            testStartTime = currTime;
            testingPeriFert = true;
        }
    }

    mqttConnector.resetResponse();
}

void sendMQTT()
{
    if (currTime - updateStatsPrevTime >= UPDATE_STATS_INTERVAL)
    {
        json["hygrometer"] = hygrometer.readValue();
        json["isWaterContainerDry"] = waterSensor.isLow();
        json["isFertilizerContainerDry"] = fertSensor.isLow();
        json["lightState"] = lightState;

        char message[256];
        json.printTo(message, sizeof(message));
        mqttConnector.sendJson(message);
        updateStatsPrevTime = currTime;
    }
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
    else if(!testingPeriFert)
    {
        periFert.stopPump();
    }
}

void runPump()
{
    if (currTime - pumpPrevTime >= HYGROMETER_INTERVAL) //Start pump if soil is 10% dryer than desired value
    {

        if (hygrometer.readValue() < desiredMoisture * 0.90 && !waterSensor.isLow())
        {
            pumpWater.startPump();

            if (currTime - pumpPrevTime >= HYGROMETER_INTERVAL + PUMP_DURATION)
            {
                pumpWater.stopPump();
                pumpMix.startPump();

                if (currTime - pumpPrevTime >= HYGROMETER_INTERVAL + PUMP_DURATION * 2)
                {
                    pumpMix.stopPump();
                    pumpPrevTime = currTime;
                }
            }
        }
        else
        {
            pumpWater.stopPump();
            pumpMix.stopPump();
            pumpPrevTime = currTime;
        }
    }
}

void testPumpWater()
{
    pumpWater.startPump();
    if (currTime - testStartTime >= PUMP_DURATION)
    {
        pumpWater.stopPump();
        pumpMix.startPump();
        if (currTime - testStartTime >= PUMP_DURATION * 2)
        {
            pumpMix.stopPump();
            testingPumpWater = false;
        }
    }
}

void testPeriFert()
{
    periFert.startPump();
    if (currTime - testStartTime >= FERT_DURATION)
    {
        periFert.stopPump();
        testingPeriFert = false;
    }
}

void loop()
{
    //Maintenance
    currTime = millis();
    mqttConnector.run();
    runFertilizer();
    runPump();

    //MQTT
    handleMQTT();
    sendMQTT();

    //test
    if (testingPumpWater)
    {
        testPumpWater();
    }
    if (testingPeriFert)
    {
        testPeriFert();
    }
}