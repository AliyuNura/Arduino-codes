#include "DHT.h"
#include "BluetoothSerial.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Check if Bluetooth configs are enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Bluetooth Serial object
BluetoothSerial SerialBT;

// GPIO where LED is connected to
const int ledPin =  21;

//// GPIO where the DS18B20 is connected to
//const int oneWireBus = 32;          
//// Setup a oneWire instance to communicate with any OneWire devices
//OneWire oneWire(oneWireBus);
//// Pass our oneWire reference to Dallas Temperature sensor 
//DallasTemperature sensors(&oneWire);

// Handle received and sent messages
String message = "";
char incomingChar;
String temperatureString = "";

// Timer: auxiliar variables
unsigned long previousMillis = 0;    // Stores last time temperature was published
const long interval = 10000;         // interval at which to publish sensor readings

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  // Bluetooth device name
  SerialBT.begin("Aliyu's Temperature Station");
  Serial.println(F("DHTxx test!"));
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  int t = dht.readTemperature();
  int h = dht.readHumidity();

  unsigned long currentMillis = millis();
  // Send temperature readings
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
     
//    temperatureString = String(sensors.getTempCByIndex(0)) + "C  " +  String(sensors.getTempFByIndex(0)) + "F";
    temperatureString = String(t) + "C  " +  String(h) + "F";
    SerialBT.println(temperatureString); 
  }
  // Read received messages (LED control command)
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
  delay(1000);
  Serial.println(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("% "));
  Serial.println(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
}
