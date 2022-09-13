#include <Servo.h>
Servo myservo;
int i;
int x;
int y;
void setup() {
  myservo.attach(3);
  

}

void loop() {
  for (i = 0; i<=90; i++){
    myservo.write(i);
    delay(10);
  }
  for (i = 90; i>=0; i--){
    myservo.write(i);
    delay(10);
  }
}
