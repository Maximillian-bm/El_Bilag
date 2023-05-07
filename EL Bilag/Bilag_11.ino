#include <math.h>
int roSteps = 5;
int rs = 95;
int ls = 81;
double s1[150];
double s2[150];
double x;
double y;
double s;
double x1;
double y1;
double nx1;
double ny1;
double x2;
double y2;
double nx2;
double ny2;
int s1F = 0;
int s2F = 0;
double a1;
double a2;
double b = 6.3;
double angle;
double roTime;
double drTime;
boolean fireFound = false;

void setup() {
  Serial.begin(115200);
  pinMode(34, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(28, OUTPUT);
  digitalWrite(32, LOW);
  digitalWrite(30, HIGH);
  digitalWrite(28, LOW);
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
  delay(3000);
  if (fireFound == false) {
    for (int i = 0; i < 750 / roSteps; i++) {
      for (int a = 0; a < roSteps; a++) {
        delay(50);
        digitalWrite(32, HIGH);
        delay(3);
        digitalWrite(32 , LOW);
      }
      s1[i] = analogRead(A8);
      s2[i] = analogRead(A9);
      delay(100);
    }
    for (int i = 0; i < 750 / roSteps; i++) {
      if (s1[i] > s1[s1F]) {
        s1F = i;
      }
      if (s2[i] > s2[s2F]) {
        s2F = i;
      }
    }

    a1 = s1F;
    a2 = s2F;

    a1 = (a1 * 2.4) + 90;
    if (a1 > 360) {
      a1 = a1 - 360;
    }
    if (a1 < 0) {
      a1 = a1 + 360;
    }

    a2 = (a2 * 2.4) - 90;
    if (a2 > 360) {
      a2 = a2 - 360;
    }
    if (a2 < 0) {
      a2 = a2 + 360;
    }

    Serial.println(a1);
    Serial.println(a2);

    a1 = radians(a1);
    a2 = radians(a2);

    x1 = b * cos(a1);
    y1 = b * sin(a1);
    nx1 = y1;
    ny1 = -x1;

    x2 = b * cos(a2);
    y2 = b * sin(a2);
    nx2 = -y2;
    ny2 = x2;

    s = -((nx1 * y2 - nx1 * y1 - ny1 * x2 + ny1 * x1) / (nx1 * ny2 - nx2 * ny1));

    x = x2 + s * nx2;
    y = y2 + s * ny2;

    x = x + 15;
    y = y - 3.7;

    Serial.println(x);
    Serial.println(y);

    fireFound = true;
  }
  if (fireFound == true) {
      double temp = sqrt(y * y) / sqrt(x * x);
      angle = atan(temp);
      angle = degrees(angle);
      if (x > 0 && y < 0) {
      angle = angle + 270;
      }
      if (x < 0 && y > 0) {
      angle = angle + 90;
      }
      if (x < 0 && y < 0) {
      angle = angle + 180;
      }
      roTime = (angle / 90) * 1000;
      drTime = ((sqrt((x * x) + (y * y))) - 30) / 29.83 * 1000 ;
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    analogWrite(5, rs);
    analogWrite(6, ls);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    delay(int(roTime));
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    analogWrite(5, LOW);
    analogWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    analogWrite(5, rs);
    analogWrite(6, ls);
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
    delay(int(drTime));
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    analogWrite(5, LOW);
    analogWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    if (analogRead(A10) < 500) {
      digitalWrite(34, HIGH);
      delay(1000);
      digitalWrite(34, LOW);
    }

    fireFound = false;
  }
}
