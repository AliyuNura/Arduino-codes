int sw1 = 0;
int sw2 = 0;
void setup() {
  pinMode(22, INPUT);
  pinMode(5, INPUT);
  pinMode(21, OUTPUT);
  Serial.begin(115200);
  sw1 = digitalRead(22);
  sw2 = digitalRead(5);
  
  if (sw1 == HIGH){
    digitalWrite(21, HIGH);
    Serial.println("LED ON");
  }
  if (sw2 == HIGH) {
    digitalWrite(21, LOW);
    Serial.println("LED OFF");
  }

}

void loop() {
  
  
  
}
