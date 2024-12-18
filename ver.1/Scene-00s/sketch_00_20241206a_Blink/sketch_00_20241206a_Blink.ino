#define LEDPIN	13

void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  digitalWrite(LEDPIN, HIGH);
  Serial.print(millis()); Serial.print("\t"); Serial.println("1");
  delay(500);
  digitalWrite(LEDPIN, LOW);
  Serial.print(millis()); Serial.print("\t"); Serial.println("0");
  delay(500);
}
