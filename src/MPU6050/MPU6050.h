#ifndef MPU6050_H
#define MPU6050_H
#include <Arduino.h>
#include <param.h>

class MPU6050Sensor
{
public:
    // MPU6050Sensor();
    bool check();
    void MPU6050_Output();
    void Gyro_Caliberate();
    void Accel_Caliberate();
    float getAccelX();
    void initialize();
    float getAccelY();
    float getAccelZ();
    float getGyroX();
    float getGyroY();
    float getGyroZ();

private:
    int16_t UAccX, UAccY, UAccZ;
    int16_t UGyro_Roll, UGyro_Pitch, UGyro_Yaw;
    int16_t MPUTemperature;
    float AccX, AccY, AccZ;
    float AngleRoll, AnglePitch;
    float RateRoll, RatePitch, RateYaw;
    int Gyro_Caliberation_Num;
    float UGyro_Roll_Cal, UGyro_Pitch_Cal, UGyro_Yaw_Cal;
    int Accel_Caliberation_Num;
    float Accel_Roll_Cal, Accel_Pitch_Cal,Accel_Yaw_Cal;
};



#endif // MPU6050_H
