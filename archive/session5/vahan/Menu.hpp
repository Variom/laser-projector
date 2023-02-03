#ifndef MENU_HPP
#define MENU_HPP

#include <LiquidCrystal.h>
#include "Button.hpp"

LiquidCrystal screen(12, 11 , 5 , 4 , 3, 2);

Button back(6);
Button left(7);
Button right(8);
Button enter(9);

// Variables
boolean inChoice = false;
int displayedMode = 0;
int currentMode = 0;
unsigned long menuTime;

void setupMenu() {
  screen.begin(16, 2);
}

void updateMenu(unsigned long globalTime) {

  screen.setCursor(0, 0);

  // Buttons value
  if (menuTime < globalTime) {
    if (enter.getButtonValue()) {
      if (inChoice) {
        currentMode = displayedMode;
        inChoice = false;
      }
      else {
        inChoice = true;
      }
      menuTime = globalTime + 500;
    }

  }
  if (menuTime < globalTime) {
    if (right.getButtonValue()) {
      if (inChoice) {
        displayedMode += 1;
        displayedMode %= 3;
        Serial.println("right");
        menuTime = globalTime + 500;
      }
    }
  }
  if (menuTime < globalTime) {
    if (left.getButtonValue()) {
      if (inChoice) {
        displayedMode -= 1;
        displayedMode %= 3;
        Serial.println("left");
        menuTime = globalTime + 500;
      }
    }
  }
  if (menuTime < globalTime) {
    if (back.getButtonValue()) {
      inChoice = false;
      menuTime = globalTime + 500;
    }
  }

  // Screen reaction

  Serial.print("inChoice : ");
  Serial.println(inChoice);
  Serial.print("displayedMode : ");
  Serial.println(displayedMode);

  if (inChoice) {
    switch (displayedMode) {
      case 0:
        screen.print("Null MODE  ");
        break;
      case 1:
        screen.print("Linear MODE  ");
        break;
      case 2:
        screen.print("Square MODE  ");
        break;
    }
  }
  else {
    screen.print("Press ENTER");
  }

}

#endif
