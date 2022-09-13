#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  string = "";
  buffer = Serial.readString();
  if (buffer.startsWith("read"){
    address = buffer.substring(buffer.indexOf('')+1).toInt;
    Serial.print("Data from address:");
    Serial.print(address);
    Serial.println();
     Serial.println(EEPROM.read(address));}
     else if(buffer.startsWith("Write"){
     address = buffer.substring(6,7).toInt();
     dataTowrite = buffer.substring(8).toInt();
     Serial.print("written");
    Serial.print(dataTowrite);
    Serial.println();
    Serial.println("To access the address;");
    Serial.println(address);
    Serial.println();
    EEPROM.write(address,dataTowrite)
    
     }
    
  
    
  }
