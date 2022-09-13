#include <Servo.h>
Servo myservo;
int x;
void setup() {
  pinMode(A0, INPUT);
  myservo.attach(9);
  // put your setup code here, to run once:

}

void loop() {
  x = analogRead(A0);
  myservo.write(x/4);
  // put your main code here, to run repeatedly:

}
