const int HYGROMETER_PIN = A0;
const int PUMP_PIN = 3;

int hygroValue;
int pumpSpeed;

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  hygroValue = analogRead(HYGROMETER_PIN);
  pumpSpeed = (hygroValue < 800) ? 255 : 0;
  analogWrite(PUMP_PIN, pumpSpeed);
  Serial.println(hygroValue);
  delay(2000);
}
