#include <EEPROM.h>
void setup() {
  int address,data = 3;
  Serial.begin(9600);
  for (address = 0;address<1024;address++){
    EEPROM.write(address, data);
  }
    for (address = 0; address <1024;address++){
    Serial.println(EEPROM.read(address), DEC);
  }

}

void loop() {
  
}
