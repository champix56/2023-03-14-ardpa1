#include "struct.h"
struct Datas data;
void setup() {
  Serial.begin(9600);
// put your setup code here, to run once:
#ifdef EMITTER
  setupValues();
#endif
}

void loop() {
// put your main code here, to run repeatedly:
#ifdef EMITTER

  emit();
#endif
#ifdef RECIEVER
  recieve();
#endif
}
#ifdef EMITTER
void setupValues() {
}

void emit() {
}
#endif
#ifdef RECIEVER
void recieve() {
}
#endif