
void setup() {
  Serial.begin(115200);
  pinMode(A0, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(34, LOW);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(4, LOW);
  digitalWrite(9, LOW);
  analogWrite(5, LOW);
  analogWrite(6, LOW);
}

void loop() {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  analogWrite(5, 95);
  analogWrite(6, 81);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
}
