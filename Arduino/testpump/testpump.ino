const int PUMP_PIN = D3;

void setup() {
  Serial.begin(115200);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  Serial.println("pumping");
  digitalWrite(PUMP_PIN, HIGH);
  delay(2000);
  Serial.println("not pumping");
  digitalWrite(PUMP_PIN, LOW);
  delay(2000);
}
