#ifndef BUTTON_HPP
#define BUTTON_HPP

/*_______________________Button Class________________________*/

class Button {

  private :

    // Pin informations

    int buttonPin;
    int buttonValue;

  public :

    // Constructor

    Button(int buttonPin) {
      this->buttonPin = buttonPin;
    }

    // Setup

    void setup() {
      pinMode(this->buttonPin, INPUT);
    }

    // Methods

    int getButtonValue() {
      if (digitalRead(this->buttonPin) == HIGH) {
        return true;
      }
      else {
        return false;
      }
    }

};

#endif
