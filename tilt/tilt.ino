 
void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

}

void loop() {
  int pin2 = digitalRead(4);
  if (pin2 ==HIGH){
    digitalWrite(12, HIGH);
  }
  else(digitalWrite(12, LOW));

}
