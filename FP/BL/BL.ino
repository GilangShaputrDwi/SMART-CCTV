#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>

char auth[]= "806MOr2PUkZU7LpDdnb4TqgVISA2jv4I";    // hasil setelah melakukan konfigurasi pada blynk)
char ssid[] = "GGGGG";  // nama dari SSDID yang digunakan
char pass[]= "qqqqqqqq"; // ditambahkan jika ssidnya menggunakan password

void setup() {
  Serial.begin(9600);
  pinMode(D7, OUTPUT); // pin yang dugunakan pada wemos D1
  Blynk.begin(auth,ssid, pass,"iot.amikom.ac.id", 8080); //merupakan server yang digunakan 

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
