#ifndef THERMOMETEDISPLAY_HPP
#define THERMOMETEDISPLAY_HPP

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class ThermometerDisplay {
public:
  void setup();
  void showTemperature(float temp);
  void showHumidity(float humidity);
private:
  Adafruit_SSD1306* display;
  void configDisplay(int startY);
};

#endif
