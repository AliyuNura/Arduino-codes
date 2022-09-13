#include <Wire.h>
#define ADDR1;
void setup() {
  int ADDR;
  Wire.begin();
  Wire.beginTransmission(ADDR);
  Wire.write(2);
  Wire.write(3);
  Wire.endTransmission();

}

void loop() {
  // put your main code here, to run repeatedly:

}
