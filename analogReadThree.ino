void setup() {
  Serial.begin(57600);
}

#define SHRINK 35

void loop() {
  digitalWrite(13,digitalRead(2)); // make LED follow D2
  int a13 = analogRead(A0);
  Serial.print(a13);
  Serial.print(" ");
  for (int i = 0 ; i < SHRINK ; i++) {
    if ((a13 / SHRINK) > i) Serial.print("#");
      else Serial.print(" ");
  }
  Serial.print(" ");
  int a14 = analogRead(A1);
  Serial.print(a14);
  Serial.print(" ");
  for (int i = 0 ; i < SHRINK ; i++) {
    if ((a14 / SHRINK) > i) Serial.print("#");
      else Serial.print(" ");
  }
  Serial.print(" ");
  int a15 = analogRead(A2);
  Serial.print(a15);
  Serial.print(" ");
  for (int i = 0 ; i < SHRINK ; i++) {
    if ((a15 / SHRINK) > i) Serial.print("#");
      else Serial.print(" ");
  }
  Serial.print(" ");
  Serial.print(digitalRead(A3));
  Serial.print(" ");
  Serial.print(digitalRead(A4));
  Serial.println("");    
}
