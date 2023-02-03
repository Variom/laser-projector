#ifndef SENSOR_HPP
#define SENSOR_HPP

/*_______________________Sensor Class________________________*/

class Sensor {

  private :

    // Pin informations

    int analogPin;
    int digitalPin;
    int analogValue;
    bool digitalValue;

  public :

    // Constructor

    Sensor(int analogPin, int digitalPin) {
      this->analogPin = analogPin;
      this->digitalPin = digitalPin;
    }

    // Setup

    void setup() {
      pinMode(this->analogPin, INPUT);
      pinMode(this->digitalPin, INPUT);
    }

    // Methods

    int getAnalogValue() {
      this->analogValue = analogRead(this->analogPin);
      return this->analogValue;
    }

    boolean getDigitalValue() {
      this->digitalValue = digitalRead(this->digitalPin);
      return this->digitalValue;
    }

};

#endif
