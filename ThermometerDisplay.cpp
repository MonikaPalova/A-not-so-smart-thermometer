#include "ThermometerDisplay.hpp"
#include <sstream>
#include <string>
#include <iostream>

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int SCL_PIN = 14;
const int SDA_PIN = 13;
const int RST_PIN = 0;
const int DC_PIN = 2;
const int CS_PIN = 16;

void ThermometerDisplay::setup() {
  this->display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, SDA_PIN, SCL_PIN, DC_PIN, RST_PIN, CS_PIN);
  this->display->begin(SSD1306_SWITCHCAPVCC);
  this->display->clearDisplay();
}

void ThermometerDisplay::showTemperature(float temp) {
  configDisplay(0);

  this->display->setCursor(30, 10);
  this->display->print(temp);
  this->display->drawCircle(95, 13, 2, BLACK);
  this->display->print(" C");

  this->display->display();
}

void ThermometerDisplay::showHumidity(float humidity) {
  configDisplay(33);

  this->display->setCursor(30, 40);
  this->display->print(humidity);
  this->display->print("%");

  this->display->display();
}

void ThermometerDisplay::configDisplay(int startY) {
  this->display->fillRect(0, startY, SCREEN_WIDTH - 1, 30, WHITE);
  this->display->setTextSize(2);
  this->display->setTextColor(INVERSE);
}
