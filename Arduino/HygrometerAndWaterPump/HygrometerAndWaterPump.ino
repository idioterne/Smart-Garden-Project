int PUMP_PIN = 5;

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  analogWrite(PUMP_PIN, 255);
  delay(2000);
  analogWrite(PUMP_PIN, 0);
  delay(2000);
}
