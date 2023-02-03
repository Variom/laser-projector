#include "Motor.hpp"
#include "Modes.hpp"
#include "Calibration.hpp"
#include "Menu.hpp"

Motor MX(4, 3);
Motor MY(9, 8);

Sensor XSensor(A0, 8);
Sensor YSensor(A1, 12);

/*_____________________Global Variables_____________________*/

unsigned long globalTime;

/*__________________________Setup___________________________*/

void setup() {
  Serial.begin(9600);
  setupMenu();
  //XSensor.setup();
  //YSensor.setup();
  //MX.setup();
  //MY.setup();
}

/*___________________________Loop___________________________*/

void loop() {
  globalTime = millis();
  updateMenu(globalTime);
  //calibrate(MX, XSensor, MY, YSensor);
  //linear(MX, MY, globalTime, false);
  //square(MX, MY, globalTime);
}
