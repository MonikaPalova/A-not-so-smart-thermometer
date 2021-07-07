#ifndef THERMOMETERMQTTCLIENT_HPP
#define THERMOMETERMQTTCLIENT_HPP

#include <ESP8266WiFi.h>
#include <MQTT.h> // https://github.com/256dpi/arduino-mqtt

class ThermometerMQTTClient {
public:
  void setupMQTTClient(WiFiClient& wifi);
  bool reconnect();
  bool connected();
  void sendTemperature(float temp);
  void sendHumidity(float humidity);
private:
  MQTTClient client;
};

#endif
