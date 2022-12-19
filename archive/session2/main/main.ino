#include "Motor.hpp"

Motor Nema(9, 8);

void setup() {
  Serial.begin(9600);
  Nema.setup();
}

void loop() {
  Nema.loop();
  
}
