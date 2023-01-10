#include "Motor.hpp"

Motor M2(4, 3, 80);
Motor M1(9, 8, 80);

void setup() {
  Serial.begin(9600);
  M1.setup();
  M1.setRange(10);
  M1.chooseMode(1);
  M2.setup();
  M2.setRange(10);
  M2.chooseMode(1);
}

void loop() {
  M1.loop();
  M2.loop();
}
