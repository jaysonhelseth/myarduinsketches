/*
	This is for a dht11 temperature and humidity sensor.
	Rename to main.cpp
*/
#include <Arduino.h>
#include "DHTesp.h"
#include "ArduinoJson.h"

DHTesp dht;
DynamicJsonDocument doc(500);

void setup() {
  Serial.begin(9600);
  dht.setup(D0, DHTesp::DHT11);
}

void loop() {
  float h = dht.getHumidity();
  float c = dht.getTemperature();
  float f = dht.toFahrenheit(c);

  doc["temp"] = f;
  doc["humidity"] = h;

  serializeJson(doc, Serial);
  Serial.print("\n");

  delay(2000);
  DynamicJsonDocument doc(500);
}
