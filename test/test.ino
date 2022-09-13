void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(2, HIGH);
  Serial.println("PIN 2 is ON");
  delay(1000);
  digitalWrite(2, LOW);
  Serial.println("PIN 2 is off");
  delay(1000);
  // put your main code here, to run repeatedly:

}
