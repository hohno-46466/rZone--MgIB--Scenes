//
// sketch_01_20241206a_Blink.ino
//

#define LEDPIN	4

void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  digitalWrite(LEDPIN, HIGH);
  Serial.print(millis()); Serial.print("\t"); Serial.println("1");
  delay(100);
  digitalWrite(LEDPIN, LOW);
  Serial.print(millis()); Serial.print("\t"); Serial.println("0");
  delay(100);
}
