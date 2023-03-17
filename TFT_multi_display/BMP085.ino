#include "structure.h"
#include "config.h"
#ifdef BMP180

#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;

bool setupPressureUnit() {
  return bmp.begin();
}
uint16_t readPressure() {
  return bmp.readPressure() / 100L;
  return true;
}
#ifdef BMP180_TEMPERATURE
//dummy start for others components libs complients
void setupTemperature(){}
float readTemperature() {
  sensorsValues.temperature = bmp.readTemperature();
  return sensorsValues.temperature;
}
#endif
#endif