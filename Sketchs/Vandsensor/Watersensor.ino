//Sensors
int waterSensor = A0;

//Async timer
long previousTime = 0;
long currentTime;
const long INTERVAL = 1000;

void setup() {

  pinMode(waterSensor, INPUT);
  Serial.begin(9600);


}


void loop() {
  currentTime = millis();  
  if (currentTime - previousTime >= INTERVAL || previousTime == 0) {
    previousTime = currentTime; // updates previous time to current time
    Serial.println(readWaterSensor());
  }

  

  

}


int readWaterSensor(){
  return analogRead(waterSensor);
}
