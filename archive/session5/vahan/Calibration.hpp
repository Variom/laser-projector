#ifndef CALIBRATION_HPP
#define CALIBRATION_HPP

#include "Motor.hpp"
#include "Sensor.hpp"

/*_____________________Calibration Method______________________*/

boolean isXCalibrate, isYCalibrate;
unsigned long updateCalibration = 0;

void calibrate(Motor MX, Sensor XSensor, Motor MY, Sensor YSensor) {
  isXCalibrate = false;
  isYCalibrate = false;

  while ((isXCalibrate == false) || (isYCalibrate == false)) {
    unsigned long globalTime = millis();
    if (updateCalibration < globalTime) {
      if (isXCalibrate == false) {
        MX.move();
        if (XSensor.getAnalogValue() < 40) {
          isXCalibrate = true;
        }
      }
      if (isYCalibrate == false) {
        MY.move();
        if (YSensor.getAnalogValue() < 40) {
          isYCalibrate = true;
        }
      }
      updateCalibration = globalTime + 1;
    }
  }
}

#endif
