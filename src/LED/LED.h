#ifndef LED_H
#define LED_H
#include <Arduino.h>
#include <param.h>

enum LEDState {
  OFF,
  ON,
  BLINK
};

enum BlinkMode {
  ALTERNATE,
  SIMULTANEOUS
};

class LEDController {
public:
  LEDController();
  void setBlinkMode(BlinkMode mode);
  void setLEDRate(int rate);
  void setLEDState(LEDState state);
  void update();

private:
  int bluePin, redPin;
  LEDState state;
  BlinkMode mode;
  int rate, timePeriod;
  elapsedMillis timer;
};



#endif // LED_H

