#ifndef MODES_HPP
#define MODES_HPP

#include "Motor.hpp"

/*_____________________Global Variables_____________________*/

unsigned long updateTime = 0;

/*_______________________Linear Mode________________________*/

unsigned long dirXUpdate = 0;
unsigned long dirYUpdate = 0;
unsigned long linearXUpdate = 0;
unsigned long linearYUpdate = 0;

void linear(Motor MX, Motor MY, unsigned long globalTime, boolean horizontal) {
  if (horizontal) {
    // Direction update
    if (dirXUpdate < globalTime) {
      MX.changeDir();
      dirXUpdate = globalTime + 50;
    }
    if (dirYUpdate < globalTime) {
      MY.changeDir();
      dirYUpdate = globalTime + 1000;
    }

    // Position upadate
    if (linearXUpdate < globalTime) {
      MX.move();
      linearXUpdate = globalTime + 1;
    }
    if (linearYUpdate < globalTime) {
      MY.move();
      linearYUpdate = globalTime + 50;
    }
  }

  else {
    // Direction update
    if (dirXUpdate < globalTime) {
      MX.changeDir();
      dirXUpdate = globalTime + 1000;
    }
    if (dirYUpdate < globalTime) {
      MY.changeDir();
      dirYUpdate = globalTime + 50;
    }
    // Position upadate
    if (linearXUpdate < globalTime) {
      MX.move();
      linearXUpdate = globalTime + 50;
    }
    if (linearYUpdate < globalTime) {
      MY.move();
      linearYUpdate = globalTime + 1;
    }
  }
}


/*_______________________Square Mode________________________*/

boolean axis = true;

unsigned long squareTime = 0;

void square(Motor MX, Motor MY, unsigned long globalTime) {
  if (updateTime < globalTime) {
    if (squareTime < globalTime) {
      axis = !axis;
      if (axis) {
        MX.changeDir();
      }
      else {
        MY.changeDir();
      }
      squareTime = globalTime + 50;
    }
    if (axis) {
      MX.move();
    } else {
      MY.move();
    }
    updateTime = globalTime + 1;
  }
}

#endif
