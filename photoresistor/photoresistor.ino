int analogPin = A0;
int analogValue = 0; 
void setup() {
  pinMode(10,OUTPUT);
}

void loop() {
  analogValue = analogRead(analogPin);
  digitalWrite(10,HIGH);
  delay(analogValue);
  digitalWrite(10,LOW);
  delay(analogValue);
}
