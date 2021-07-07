#include "ThermometerMQTTClient.hpp"
#include "config.h"

void ThermometerMQTTClient::setupMQTTClient(WiFiClient& wifi){
    this->client.begin(MQTT_SERVER, wifi);
    this->client.subscribe("v1/devices/thermometer/rpc/response/+");
}

bool ThermometerMQTTClient::reconnect(){
  if(this->connected()){
    return true;
  };

  return this->client.connect(CLIENT_ID,USER,PASS);
}

bool ThermometerMQTTClient::connected(){
  return this->client.connected();
}

void ThermometerMQTTClient::sendTemperature(float temp){
  String json = "{\"temperature\":" + String(temp,2) + "}";

  int qos =1;
  bool retained=true;
  this->client.publish("v1/devices/thermometer/telemetry", json.c_str(), retained, qos);
}

void ThermometerMQTTClient::sendHumidity(float humidity){
  String json = "{\"humidity\":" + String(humidity,2) + "}";

  int qos =1;
  bool retained=true;
  this->client.publish("v1/devices/thermometer/telemetry", json.c_str(), retained, qos);
}
