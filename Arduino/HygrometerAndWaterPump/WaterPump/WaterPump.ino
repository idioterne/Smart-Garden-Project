const int PUMP_PIN = GPIO5;

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {  
  digitalWrite(PUMP_PIN, HIGH);
  delay(2000);
  digitalWrite(PUMP_PIN, LOW);
  delay(2000);
}

void start() {
  analogWrite(PUMP_PIN, 255);
}

void stop() {
  analogWrite(PUMP_PIN, 0);
}
