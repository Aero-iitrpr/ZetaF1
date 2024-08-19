#include <LED/LED.h>

LEDController::LEDController() {
  pinMode(LED_BPIN, OUTPUT);
  pinMode(LED_RPIN, OUTPUT);
  digitalWrite(LED_BPIN, LOW);
  digitalWrite(LED_RPIN, LOW);
  setLEDState(BLINK);
  setBlinkMode(ALTERNATE);
  setLEDRate(2);
  timer = elapsedMillis();
  timer = 0;
}

void LEDController::setBlinkMode(BlinkMode mode) {
  this->mode = mode;
  timer=0;
  if(mode == ALTERNATE) {
    digitalWrite(LED_BPIN, LOW);
    digitalWrite(LED_RPIN, HIGH);
  }
  else {
    digitalWrite(LED_BPIN, HIGH);
    digitalWrite(LED_RPIN, LOW);
  }
}

void LEDController::setLEDRate(int rate) {
  timePeriod = 1000 / rate;
}

void LEDController::setLEDTimePeriod(int timePeriod) {
  this->timePeriod = timePeriod;
}

void LEDController::setLEDState(LEDState state) {
  this->state = state;
}

void LEDController::update() {
  if (timer >= timePeriod) {
    timer = 0;
    switch (state) {
      case OFF:
        digitalWrite(LED_BPIN, LOW);
        digitalWrite(LED_RPIN, LOW);
        break;
      case ON:
        digitalWrite(LED_BPIN, HIGH);
        digitalWrite(LED_RPIN, HIGH);
        break;
      case BLINK:
        digitalWrite(LED_BPIN, !digitalRead(LED_BPIN));
        digitalWrite(LED_RPIN, !digitalRead(LED_RPIN));
        break;
    }
  }
}