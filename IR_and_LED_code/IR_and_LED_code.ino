#include <IRremote.h>
 
int IR_Recv = 11;   //IR Receiver Pin 3
int bluePin = 10;
int greenPin = 9;
int yellowPin = 8;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  pinMode(bluePin, OUTPUT);      // sets the digital pin as output
  pinMode(greenPin, OUTPUT);      // sets the digital pin as output
  pinMode(yellowPin, OUTPUT);      // sets the digital pin as output 

}
 
void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    //switch case to use the selected remote control button
    switch (results.value){
      case 16724175: //when you press the 1 button
        digitalWrite(bluePin, HIGH);
        break;   
      case 16718055: //when you press the 4 button
        digitalWrite(bluePin, LOW);   
        break;
       case 16743045: //when you press the 2 button
        digitalWrite(greenPin, HIGH);
        break;           
       case 16716015: //when you press the 5 button
        digitalWrite(greenPin, LOW);
        break;       
       case 16726215: //when you press the 3 button
        digitalWrite(yellowPin, HIGH);
        break;       
       case 16734885: //when you press the 6 button
        digitalWrite(yellowPin, LOW);
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(10);
}
