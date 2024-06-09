#ifndef DRONE_H
#define DRONE_H
#include <Arduino.h>
#include <MPU6050/MPU6050.h>
#include <Zeta_Low_Pass\Zeta_Low_Pass.h>

class Drone
{
public:
    bool Caliberated=false;
    void Initialize_Drone();
    void Caliberate_Drone();
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

    //global variables
    bool MidAirDroneBool;
    float AccX, AccY, AccZ;
    float AngleRoll, AnglePitch;
    float RateRoll, RatePitch, RateYaw;
    float Altitude;

private:
    MPU6050Sensor mpu6050;
    ZetaLowPass accelXFilter;
    ZetaLowPass accelYFilter;
    ZetaLowPass accelZFilter;
    ZetaLowPass gyroXFilter;
    ZetaLowPass gyroYFilter;
    ZetaLowPass gyroZFilter;
    
    

};

extern Drone drone;

#endif // DRONE_H
