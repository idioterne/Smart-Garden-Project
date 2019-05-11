const int PUMP_PIN = 3;
int pumpSpeed;

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {  
}

void start() {
  analogWrite(PUMP_PIN, 255);
}

void stop() {
  analogWrite(PUMP_PIN, 0);
}
