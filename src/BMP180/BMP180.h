#ifndef BMP180_H
#define BMP180_H
#include <Arduino.h>
#include <param.h>

class BMP180Sensor
{
public:
  // BMP180Sensor();
  bool checkConnection();
  float getPressure();
  float getTemperature();
  void initialize();
  float groundPressure;
private:
  int16_t ac1, ac2, ac3;
  uint16_t ac4, ac5, ac6;
  int16_t b1, b2, mb, mc, md;
};

#endif // BMP180_H