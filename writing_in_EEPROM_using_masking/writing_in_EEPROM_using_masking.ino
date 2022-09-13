#include <EEPROM.h>

int bigData = 35;
byte littleData; 
void setup() {
  
  Serial.begin(9600);
  littleData = bigData & 0xFF;
  EEPROM.write(0, littleData);
  Serial.println(littleData);
  littleData = bigData>>8;
  EEPROM.write(1, littleData);
  Serial.println(littleData);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}

// this method is called little Endian ordering of masking
