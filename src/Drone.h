#ifndef DRONE_H
#define DRONE_H
#include <Arduino.h>
#include <MPU6050/MPU6050.h>
#include <Zeta_Buffer/Zeta_Buffer.h>
#include <vector>
//while using ppm
#ifdef USE_PPM
#include <Zeta_RCIN/Zeta_RCIN_PPM.h>
#endif
//while using pwm
#ifdef USE_PWM
#include <Zeta_RCIN/Zeta_RCIN_PWM.h>
#endif

#include <Zeta_Low_Pass\Zeta_Low_Pass.h>
#include <LED/LED.h>

class Drone
{
public:
    void Initialize_Drone(LEDController led);
    void Calibrate_Drone();
    void GetMPU6050Data();
    void ApplyLowPass();
    void Postprocessing();
    float getDroneAccelX();
    float getDroneAccelY();
    float getDroneAccelZ();
    float getDroneGyroX();
    float getDroneGyroY();
    float getDroneGyroZ();
    bool MidAirDrone();
    void updateRCIN();
    std::vector<int> Return_Receiver_Store();

    // global variables
    bool MidAirDroneBool;
    // mpu6050 variables
    float AccX, AccY, AccZ;
    float AngleRoll, AnglePitch;
    float RateRoll, RatePitch, RateYaw;
    float AccX_Low_Pass, AccY_Low_Pass, AccZ_Low_Pass;
    float RateRoll_Low_Pass, RatePitch_Low_Pass, RateYaw_Low_Pass;
    float Altitude;
    bool Calibrated = false;
    // rcin variables
    std::vector<int> Receiver_Values;

private:
    LEDController led;
    MPU6050Sensor mpu6050;
    ZetaBufferStore BufferLog;
#ifdef USE_PPM
    ZetaRCIN_PPM zetaRcin;
#endif

#ifdef USE_PWM
    ZetaRCIN_PWM zetaRcin; // here the object was declared hence initialization of hardware inturrupt was successfully done here
#endif

    ZetaLowPass accelXFilter;
    ZetaLowPass accelYFilter;
    ZetaLowPass accelZFilter;
    ZetaLowPass gyroXFilter;
    ZetaLowPass gyroYFilter;
    ZetaLowPass gyroZFilter;
};

// extern Drone drone;

#endif // DRONE_H
