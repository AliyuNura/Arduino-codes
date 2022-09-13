zzzzzzz#include <Ethernet.h>

#include <EEPROM.h>
void setup() {
  int address,data = 5;
  Serial.begin(9600);
  Serial.available();
  if (Serial.available() == "Write"){
    EEPROM.write(address, data);
    Serial.print(address , data);z
    if (Serial.available() == "read") z
     Serial.print(EEPROM.read(address), DEC);
  }

}

void loop() {
