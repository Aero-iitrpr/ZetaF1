#ifndef ZETA_KALMAN_1D
#define ZETA_KALMAN_1D
#include <Arduino.h>
#include <param.h>
#include <ArduinoEigenDense.h>

class ZetaKalman1D
{
public:
    int n, c, d;

private:
    uint16_t time;
};

#endif