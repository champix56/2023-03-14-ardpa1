#ifndef _CONFIG_H_

#define _CONFIG_H_
#include "structure.h"
  /***
  PRESSURE
  ***/
  #define BMP180
  /***
  TEMPERATURE
  ***/
  //#define BMP180_TEMPERATURE
  //#define DUMMY_TEMPERATURE
  //#define DS18B20_TEMPERATURE
  #define DHT_TEMPERATURE
  /***
  HUMIDITY
  ***/
  #define DHT_SENSOR
 /***
 OUTPUT
 ***/
  //#define ST7735
#define SDCARD
//check config for multiple sensor type defined
  #include "config_adv.h"
#endif
