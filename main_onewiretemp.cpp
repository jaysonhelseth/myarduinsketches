/*
	This is for a DS18B20 temperature sensor that can be placed in water.
	Rename to main.cpp
*/
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ArduinoJson.h>

#define ONE_WIRE_BUS 50
#define DOC_LENGTH 200

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float tempF = 0;

DynamicJsonDocument doc(DOC_LENGTH);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  tempF = sensors.getTempFByIndex(0); 
  
  doc["temp"] = tempF;

  serializeJson(doc, Serial);
  Serial.print("\n");

  delay(1000);
  DynamicJsonDocument doc(DOC_LENGTH);
}
