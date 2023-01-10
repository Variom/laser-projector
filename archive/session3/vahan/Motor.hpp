#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor {

  private:

    // Pin informations
    int stepPin;
    int dirPin;

    // State
    long speed;                          // Percentage
    boolean direction{true};                      // Clockwise is true and anti-clockwise is false
    int currentStep;
    int targetedStep;

    // Trajectory
    int range;
    boolean linearMode{false};
    boolean sinusoidalMode{false};

    // Time variables
    unsigned long globalTime;
    unsigned long nextUpdate = 0;

  public:

    // Constructors
    // General constructor
    Motor(int stepPinInit, int dirPinInit, long speedInit, int currentStepInit, int targetedStepInit) {
      stepPin = stepPinInit;
      dirPin = dirPinInit;
      speed = speedInit;
      currentStep = currentStepInit;
      targetedStep = targetedStepInit;
    }
    // With four parameters
    Motor(int stepPinInit, int dirPinInit, long speedInit, int currentStepInit) : Motor(stepPinInit, dirPinInit, speedInit, currentStepInit , currentStepInit) {};
    // With three parameters
    Motor(int stepPinInit, int dirPinInit, long speedInit) : Motor(stepPinInit, dirPinInit, speedInit, 0 , 0) {};
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
        nextUpdate = globalTime + 101 - speed;
        return true;
      }
      else {
        return false;
      }
    }

    void move() {
      linear(0);
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
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
      }
    }

    // Modes
    void setModes(boolean newLinearMode, boolean newSinusoidalMode) {
      linearMode = newLinearMode;
      sinusoidalMode = newSinusoidalMode;
    }

    void chooseMode(int mode) {
      switch (mode) {
        case 0:
          setModes(false, false);
          break;
        case 1:
          setModes(true, false);
          targetedStep = range;
          break;
        case 3:
          setModes(false, true);
          targetedStep = range;
          break;
      }
    }

    // Setter
    void setTargetedStep(int newTargetedStep) {
      targetedStep = newTargetedStep;
    }

    void setCurrentStep(int newCurrentStep) {
      currentStep = newCurrentStep;
    }

    void setSpeed(float newSpeed) {
      speed = newSpeed;
    }

    void setRange(int newRange) {
      range = newRange;
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

    float getSpeed() {
      return speed;
    }

    // Modes

    void linear(int bypass) {
      if ((linearMode) or (bypass == 1)) {
        if (currentStep == range) {
          targetedStep = -range;
        }
        else if (currentStep == -range) {
          targetedStep = range;
        }
      }
    }

    void sinusoidal(int range) {}

    // Setup
    void setup() {
      pinMode(stepPin, OUTPUT);
      pinMode(dirPin, OUTPUT);
      digitalWrite(dirPin, LOW);
    }

    // Loop
    void loop() {
      if (tryUpdate()) {
        move();
      }
    }
};

#endif
