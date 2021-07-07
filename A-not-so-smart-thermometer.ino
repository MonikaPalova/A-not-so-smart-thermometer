#include <ESP8266WiFi.h>
#include <Wire.h>
#include "ThermometerMQTTClient.hpp"
#include "ThermometerDisplay.hpp"
#include "config.h"

#define gy21Addr 0x40

WiFiClient wifi;
ThermometerMQTTClient mqtt;
ThermometerDisplay display;

void setupWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}

void setup() {
  Wire.begin();
  setupWifi();

  mqtt.setupMQTTClient(wifi);
  display.setup();
}

void loop() {
  if (!mqtt.connected()) {
    mqtt.reconnect();
  }

  float humidity = readHumidity();
  mqtt.sendHumidity(humidity);
  display.showHumidity(humidity);

  for (int i = 0; i < 10; i++) {
    float temperature = readTemperature();
    mqtt.sendTemperature(temperature);
    display.showTemperature(temperature);
    delay(500);
  }
}

float readTemperature() {
  float response = sendRequestToSensor(0xF3);
  float celsTemp = ((175.72 * response) / 65536.0) - 46.85;

  return celsTemp;
}

float readHumidity() {
  float response = sendRequestToSensor(0xF5);
  float humidity = ((125 * response) / 65536.0) - 6;

  return humidity;
}

float sendRequestToSensor(byte command) {
  unsigned int data[2];

  Wire.beginTransmission(gy21Addr);
  Wire.write(command);
  Wire.endTransmission();
  delay(500);

  Wire.requestFrom(gy21Addr, 2);
  if (Wire.available() == 2) {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }

  return ((data[0] * 256.0) + data[1]);
}
