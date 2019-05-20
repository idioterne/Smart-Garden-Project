const int PUMP_PIN = 3;

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {  
}

void start() {
  digitalWrite(PUMP_PIN, HIGH);
}

void stop() {
  digitalWrite(PUMP_PIN, LOW);
}