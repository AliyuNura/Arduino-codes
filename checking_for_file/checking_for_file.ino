#include "SPIFFS.h"
 
void setup() {
 
  Serial.begin(115200);
 
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
 
  File file = SPIFFS.open("/test.txt", FILE_WRITE);
 
  if (!file) {
    Serial.println("There was an error opening the file for writing");
    return;
  }
 
  if (file.print("TEST")) {
    Serial.println("File was written");
  } else {
    Serial.println("File write failed");
  }
 
  file.close();
 
  Serial.println(SPIFFS.exists("/test.txt"));
  Serial.println(SPIFFS.exists("/nonexisting.txt"));
 
}
 
void loop() {}
