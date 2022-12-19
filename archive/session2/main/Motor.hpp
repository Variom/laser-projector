#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor {

  private:

    // Pin informations
    int stepPin;
    int dirPin;

    // State
    int speed;                          // Percentage
    boolean direction{true};            // Clockwise is true and anti-clockwise is false
    int currentStep;
    int targetedStep;

    // Time variables
    unsigned long globalTime;
    unsigned long nextUpdate = 0;
    unsigned long lastUpdate = 0;

  public:

    // Constructors
    // General constructor
    Motor(int stepPinInit, int dirPinInit, int speedInit, int currentStepInit, int targetedStepInit) {
      stepPin = stepPinInit;
      dirPin = dirPinInit;
      speed = speedInit;
      currentStep = currentStepInit;
      targetedStep = targetedStepInit;
    }
    // With four parameters
    Motor(int stepPinInit, int dirPinInit, int speedInit, int currentStepInit) : Motor(stepPinInit, dirPinInit, speedInit, currentStepInit , currentStepInit) {};
    // With three parameters
    Motor(int stepPinInit, int dirPinInit, int speedInit) : Motor(stepPinInit, dirPinInit, speedInit, 0 , 0) {};
    // With two parameters
    Motor(int stepPinInit, int dirPinInit) : Motor(stepPinInit, dirPinInit, 50, 0 , 0) {};

    // Methods

    void changeDir() {
      direction = !direction;
      if (direction) {
        digitalWrite(dirPin, HIGH);
      }
      else {
        digitalWrite(dirPin, LOW);
      };
    }

    boolean goodDir() {
      return (((direction) and (targetedStep >= currentStep)) or ((!direction) and (targetedStep <= currentStep)));
    }

    boolean tryUpdate() {
      globalTime = millis();
      if (nextUpdate < globalTime) {
        lastUpdate = globalTime;
        nextUpdate = globalTime + 1;
        return true;
      }
      else {
        return false;
      }
    }

    void move() {
      if (currentStep != targetedStep) {
        if (!goodDir()) {
          changeDir();
        }
        if (direction) {
          currentStep++;
        }
        else {
          currentStep--;
        }
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(900);
        digitalWrite(stepPin, LOW);
      }
    }

    // Setter
    void setTargetedStep(int newTargetedStep) {
      targetedStep = newTargetedStep;
    }

    void setCurrentStep(int newCurrentStep) {
      currentStep = newCurrentStep;
    }

    // Getter
    int getTargetedStep() {
      return targetedStep;
    }

    int getCurrentStep() {
      return currentStep;
    }

    boolean getDirection() {
      return direction;
    }

    // Setup
    void setup() {
      pinMode(stepPin, OUTPUT);
      pinMode(dirPin, OUTPUT);
      digitalWrite(dirPin, HIGH);
    }

    // Loop
    void loop() {
      if (tryUpdate()) {
        move();
      }
    }
};

#endif
