const int HYGROMETER_PIN = A0;
const int PUMP_PIN = 3;

int hygroValue;
int motorSpeed;

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  hygroValue = analogRead(HYGROMETER_PIN);
  motorSpeed = (hygroValue < 800) ? 255 : 0;
  analogWrite(PUMP_PIN, motorSpeed);
  
  delay(2000);
}
