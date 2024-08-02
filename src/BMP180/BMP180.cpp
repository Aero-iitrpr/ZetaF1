#include <Wire.h>
#include <Arduino.h>
#include <BMP180/BMP180.h>
#include <Helpers/I2C.h>

void BMP180Sensor::initialize(void)
{
    // initiating the BMP180 I2C communication
    Wire.begin();
    Wire.setClock(400000);
    this->ac1 = read16(0xAA);
    this->ac2 = read16(0xAC);
    this->ac3 = read16(0xAE);
    this->ac4 = read16(0xB0);
    this->ac5 = read16(0xB2);
    this->ac6 = read16(0xB4);
    this->b1 = read16(0xB6);
    this->b2 = read16(0xB8);
    this->mb = read16(0xBA);
    this->mc = read16(0xBC);
    this->md = read16(0xBE);

    this->groundPressure = getPressure();
}

float BMP180Sensor::getTemperature(void)
{
    write8(BMP180_REG_CONTROL, BMP180_CMD_TEMPERATURE);
    delay(5);
    uint16_t UT = read16(BMP180_REG_RESULT);
    int32_t X1 = (UT - this->ac6) * this->ac5 >> 15;
    int32_t X2 = (this->mc << 11) / (X1 + this->md);
    int32_t B5 = X1 + X2;
    return ((B5 + 8) >> 4) / 10.0;
}

float BMP180Sensor::getPressure(void)
{
  write8(BMP180_REG_CONTROL, BMP180_CMD_TEMPERATURE);
  delay(5);
  uint16_t ut = read16(BMP180_REG_RESULT);
  write8(BMP180_REG_CONTROL, BMP180_CMD_PRESSURE);
  delay(8);  // Wait for conversion to complete
  uint16_t up = read16(BMP180_REG_RESULT) >> 6;

  int32_t x1 = (ut - (int32_t)this->ac6) * ((int32_t)this->ac5) >> 15;
  int32_t x2 = ((int32_t)this->mc << 11) / (x1 + this->md);
  int32_t b5 = x1 + x2;

  int32_t b6 = b5 - 4000;
  x1 = (this->b2 * (b6 * b6 >> 12)) >> 11;
  x2 = (this->ac2 * b6) >> 11;
  int32_t x3 = x1 + x2;
  int32_t b3 = ((((int32_t)this->ac1 * 4 + x3) << 1) + 2) / 4;

  x1 = (this->ac3 * b6) >> 13;
  x2 = (this->b1 * (b6 * b6 >> 12)) >> 16;
  x3 = ((x1 + x2) + 2) >> 2;
  uint32_t b4 = (this->ac4 * (uint32_t)(x3 + 32768)) >> 15;
  uint32_t b7 = ((uint32_t)up - b3) * (50000 >> 1);

  int32_t p = b7 < 0x80000000 ? (b7 * 2) / b4 : (b7 / b4) * 2;

  x1 = (p >> 8) * (p >> 8);
  x1 = (x1 * 3038) >> 16;
  x2 = (-7357 * p) >> 16;
  p += (x1 + x2 + 3791) >> 4;

  return p;
}

bool BMP180Sensor::checkConnection(void)
{
  Wire.beginTransmission(BMP180_ADDRESS);
  uint8_t error = Wire.endTransmission();

  // If the error is 0, the device acknowledged the transmission
  return (error == 0);
}