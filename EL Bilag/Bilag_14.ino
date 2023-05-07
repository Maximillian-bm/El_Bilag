double s1[150];
double s2[150];
boolean done = false;
void setup() {
  Serial.begin(9600);
  pinMode(32, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(28, OUTPUT);
  digitalWrite(32, LOW);
  digitalWrite(30, HIGH);
  digitalWrite(28, LOW);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
}

void loop() {
  if(done == false){
    delay(1000);
  for (int i = 0; i < 750 / 5; i++) {
    for (int a = 0; a < 5; a++) {
      delay(50);
      digitalWrite(32, HIGH);
      delay(3);
      digitalWrite(32 , LOW);
    }
    s1[i] = analogRead(A8);
    s2[i] = analogRead(A9);
    delay(100);
    }
   Serial.println("s1");
  for(int i = 0; i < 150; i++){
    Serial.println(s1[i]);
    }
       Serial.println("s2");
  for(int i = 0; i < 150; i++){
    Serial.println(s2[i]);
    }
    done = true;
  }
}
