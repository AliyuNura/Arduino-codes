#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "ESP32_DHT11"                         //change this
 
const char WIFI_SSID[] = "aliyu";               //change this
const char WIFI_PASSWORD[] = "******##";           //change this
const char AWS_IOT_ENDPOINT[] = "a1vgoyp22ws2f7-ats.iot.us-east-1.amazonaws.com";       //change this
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----

-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----

-----END CERTIFICATE-----
 
 
)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
----BEGIN RSA PRIVATE KEY-----

-----END RSA PRIVATE KEY-----

 
 
)KEY";
