#include "drone.h"
#include <Arduino.h>

void Drone::Initialize_Drone()
{
    // this function does the initial setup required for the drone
    mpu6050.initialize();
    //adding initial PPM support later use macros to switch dynamically
    zetaRcin.initialize();
}

void Drone::Caliberate_Drone()
{
    mpu6050.Gyro_Caliberate();
    // add delay and led support
    mpu6050.Accel_Caliberate();
    // add multiple sensor support and store them in eprom
}

void Drone::GetMPU6050Data(void)
{
    mpu6050.MPU6050_Output();
    AccX = mpu6050.getAccelX();
    AccY = mpu6050.getAccelY();
    AccZ = mpu6050.getAccelZ();
    RateRoll = mpu6050.getGyroX();
    RatePitch = mpu6050.getGyroY();
    RateYaw = mpu6050.getGyroZ();
}

void Drone::Postprocessing()
{
    // add postprocessing support for the sensor
    // check with the consistency and health sensors
}

float Drone::getDroneAccelX(void)
{
    return AccX;
}

float Drone::getDroneAccelY(void)
{
    return AccY;
}

float Drone::getDroneAccelZ(void)
{
    return AccZ;
}

float Drone::getDroneGyroX(void)
{
    return RateRoll;
}

float Drone::getDroneGyroY(void)
{
    return RatePitch;
}

float Drone::getDroneGyroZ(void)
{
    return RateYaw;
}

bool Drone::MidAirDrone()
{
    // write algo for checking if the drone is mid air
    return false;
}

void Drone::updateRCIN()
{
    //updating the store
    zetaRcin.update();
    Receiver_Values=zetaRcin.Receiver_Values_Store();
}

std::vector<float> Drone::Return_Receiver_Store()
{
    return Receiver_Values;
}

