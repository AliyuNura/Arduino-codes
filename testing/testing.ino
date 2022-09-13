void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);

}

void loop() {
 digitalWrite(2, HIGH);
 Serial.println("ON");
 delay(1000);
 digitalWrite(2, LOW);
 Serial.println("OFF");
 delay(1000);
 
}
