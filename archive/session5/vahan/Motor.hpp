#ifndef MOTOR_HPP
#define MOTOR_HPP

/*________________________Motor Class________________________*/

class Motor {

  private:

    // Pin informations

    int stepPin;
    int dirPin;

  public:

    // Constructor

    Motor(int stepPinInit, int dirPinInit) {
      this->stepPin = stepPinInit;
      this->dirPin = dirPinInit;
    }

    // Setup

    void setup() {
      pinMode(stepPin, OUTPUT);
      pinMode(dirPin, OUTPUT);
      digitalWrite(dirPin, LOW);
    }

    // Methods

    void changeDir() {
      if (digitalRead(this->dirPin) == LOW) {
        digitalWrite(this->dirPin, HIGH);
      }
      else {
        digitalWrite(this->dirPin, LOW);
      };
    }

    void move() {
      digitalWrite(this->stepPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(this->stepPin, LOW);
    }

};

#endif
