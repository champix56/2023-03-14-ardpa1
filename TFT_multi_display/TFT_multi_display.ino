#include <DS1307RTC.h>
#include <Timelib.h>
#include "config.h"
#include "structure.h"

volatile bool runloop = true;

void isr() {
  runloop = !runloop;
}
void setup() {
  attachInterrupt(digitalPinToInterrupt(2), isr, RISING);
#ifdef OUTPUT_ACTIONNER
  setupOutput();
#endif
#ifdef PRESSURE_SENSOR
  setupPressureUnit();
#endif
#ifdef TEMPERATURE_SENSOR
  setupTemperature();
#endif
#ifdef HUMIDITY_SENSOR
  setupHumidity();
#endif
  delay(900);
  //tft.fillScreen(TFT_BACKGROUND_COLOR);
  readAndShowDatetime();
}

void loop() {
  char buffer[10] = "";
  String sdrow = "";
  if (runloop) {
    digitalWrite(A3, HIGH);

    readAndShowDatetime();
#ifdef PRESSURE_SENSOR
    sensorsValues.pressure = readPressure();
    sprintf(buffer, "%d;", sensorsValues.pressure);
    sdrow += String(buffer);
#endif
#ifdef TEMPERATURE_SENSOR
    sensorsValues.temperature = readTemperature();
    dtostrf(sensorsValues.pressure, 5, 2, buffer);
    sdrow += String(buffer);
#endif
#ifdef HUMIDITY_SENSOR
    sensorsValues.humidity = readHumidity();
    sprintf(buffer, "%d;", sensorsValues.humidity);
    sdrow += String(buffer);
#endif
#ifdef OUTPUT_ACTIONNER
    loopOutput();
#endif
#ifdef SDCARD
    writeSD(sdrow);
#endif
  } else {
    digitalWrite(A3, LOW);
  }
  delay(1000);
}
