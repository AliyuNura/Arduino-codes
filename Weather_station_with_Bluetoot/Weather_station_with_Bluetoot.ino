#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
//#include <LiquidCrystal_I2C.h>
//#include <Wire.h>
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
// set the LCD number of columns and rows
//int lcdColumns = 16;
//int lcdRows = 2;
//LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); //Define LCD
String message;
const int ledPin =  21;
//Message from device
void setup() {
  //Initiate LCD
//   
  pinMode(ledPin, OUTPUT);
  //Initiate DHT11 Sensor
  dht.begin();
  Serial.begin(115200);
  SerialBT.begin("Aliyu's ESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  
}
void loop() {
delay(1000);
    
  //Send Sensor data to device via Bluetooth
  SerialBT.print("Hum: ");
  SerialBT.print(dht.readHumidity());
  SerialBT.println(" %");
  
  SerialBT.print("Temp: ");
  SerialBT.print(dht.readTemperature());
  SerialBT.println(" C ");
  delay(2000);



if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  // Check received message and control output accordingly
  if (message =="on"){
    digitalWrite(ledPin, HIGH);
  }
  else if (message =="off"){
    digitalWrite(ledPin, LOW);
  }
  //Display message to LCD
////    lcd.setCursor(0, 0);
////    lcd.print(message);
  
}
