# A-not-so-smart-thermometer
A Not-so-smart Thermometer created for the IoT course in FMI, 2021

## Hardware configuration

Used **ESP8266**

### Display

Used Display *128\*64*

- Change size configurations:
```
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
```

- Use given pins to connect your display:
```
Display -> ESP8266

 GND -> GND
 VDD -> 3V3
 SCK -> D5
 SDA -> D7
 RES -> D3
 DC  -> D4
```

### Thermometer Sensor 

Used **GY21**

- Use given pins to connect your sensor:
```
Sensor -> ESP8266

 VIN -> 3V3
 GND -> GND
 SCL -> D1
 SDA -> D2
```

## Software configuration

Fill in the **config.h** file accordingly to configure WiFi and ThingsBoard