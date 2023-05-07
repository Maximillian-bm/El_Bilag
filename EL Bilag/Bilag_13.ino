void setup() {
  Serial.begin(115200);
  pinMode(34, OUTPUT);
  pinMode(A10, INPUT);
  digitalWrite(34, LOW);
}

void loop() {
if (analogRead(A10) > 500) {
      digitalWrite(34, LOW);
    }
}
