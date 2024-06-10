#ifndef DRONE_H
#define DRONE_H
#include <Arduino.h>
#include <MPU6050/MPU6050.h>
#include <vector>

#ifdef USE_PPM
#include <Zeta_RCIN/Zeta_RCIN_PPM.h>
#endif

class Drone
{
public:
    void Initialize_Drone();
    void Calibrate_Drone();
    void GetMPU6050Data();
    void Postprocessing();
    float getDroneAccelX();
    float getDroneAccelY();
    float getDroneAccelZ();
    float getDroneGyroX();
    float getDroneGyroY();
    float getDroneGyroZ();
    bool MidAirDrone();
    void updateRCIN();
    std::vector<float> Return_Receiver_Store();

    // global variables
    bool MidAirDroneBool;
    // mpu6050 variables
    float AccX, AccY, AccZ;
    float AngleRoll, AnglePitch;
    float RateRoll, RatePitch, RateYaw;
    // baro variable
    float Altitude;
    bool Calibrated = false;
    // rcin variables
    std::vector<float> Receiver_Values;

private:
    MPU6050Sensor mpu6050;
#ifdef USE_PPM
    ZetaRCIN_PPM zetaRcin;
#endif
};

// extern Drone drone;

#endif // DRONE_H
