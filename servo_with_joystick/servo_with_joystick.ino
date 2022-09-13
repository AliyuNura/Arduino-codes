#include <Servo.h>
Servo myservo;
int x;
void setup() {
  Serial.begin(9600);
  myservo.attach(9); //servo pin
  pinMode(A2,OUTPUT);  //+VE of joystick
  pinMode(A3,OUTPUT);  //-VE of joystick
  digitalWrite(A2  , HIGH);
  digitalWrite(A3, LOW);
  
  

}

void loop() {
  delay(50);
  x = analogRead(A0);
  Serial.println(x, DEC);

 myservo.write(x); //setting range of operation of the servo motor i.e 52 --> 154.3xx
    
    
    }
 
    
  
