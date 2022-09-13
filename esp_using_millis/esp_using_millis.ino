const int pin =4;
unsigned long interval = 1000;
unsigned previous_time = 0;
unsigned long current_time;
int state = LOW;
void setup() {
  pinMode(pin, OUTPUT);

}

void loop() {
  current_time = millis();
  if (current_time-previous_time >=interval){
    previous_time = current_time;
  }
  if (state == LOW){
   state = HIGH ;
  }
  if (state == HIGH){
    state = LOW;
  }
  digitalWrite(pin, state);
}
