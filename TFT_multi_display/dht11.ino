#include "config.h"
#ifdef DHT_SENSOR
#include "structure.h"
#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT11  // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)


DHT dht(DHTPIN, DHTTYPE);

bool setupHumidity() {

  dht.begin();
  return true;
}

float readHumidity() {

  float h = dht.readHumidity();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h)) {
    Serial.println(F("Failed to read from DHT sensor!"));

    return 0;
  } else {

    return h;
  }
}
#ifdef DHT_TEMPERATURE
void setupTemperature() {}
float readTemperature() {
  float t = dht.readTemperature();


  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    t = -1000;
  }

  return t;
}
#endif
#endif