#include<Wire.h>
#include<Arduino.h>
#include<param.h>

void write8(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(BMP180_ADDRESS);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

uint16_t read16(uint8_t reg) {
  Wire.beginTransmission(BMP180_ADDRESS);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(BMP180_ADDRESS, 2);
  return (Wire.read() << 8) | Wire.read();
}