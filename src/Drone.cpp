#include "drone.h"
#include <Arduino.h>
#include <MPU6050/MPU6050.h>
#include <Zeta_Buffer/Zeta_Buffer.h>
#include <vector>


// #ifdef USE_PPM
// #include <Zeta_RCIN/Zeta_RCIN_PPM.h>
// #endif

// #ifdef USE_PWM
// #include <Zeta_RCIN/Zeta_RCIN_PWM.h>
// #endif

void Drone::Initialize_Drone(void)
{
    // this function does the initial setup required for the drone
    mpu6050.initialize();
    // Initialising the Circular Buffer Store
    BufferLog.begin();
// #ifdef USE_PPM
//     zetaRcin.initialize();
// #endif
//     // Initialize low-pass filters with appropriate cutoff frequency and sample rate
//     float cutoffFrequency = 5.0; // change this to the actual cutoff frequency
//     float sampleRate = 100.0;    // change this to the actual sample rate

//     accelXFilter = ZetaLowPass(zeta_low_pass_accelX_cutoff, zeta_low_pass_accelX_rate);
//     accelYFilter = ZetaLowPass(zeta_low_pass_accelY_cutoff, zeta_low_pass_accelY_rate);
//     accelZFilter = ZetaLowPass(zeta_low_pass_accelZ_cutoff, zeta_low_pass_accelZ_rate);
//     gyroXFilter = ZetaLowPass(zeta_low_pass_gyroX_cutoff, zeta_low_pass_gyroX_rate);
//     gyroYFilter = ZetaLowPass(zeta_low_pass_gyroY_cutoff, zeta_low_pass_gyroY_rate);
//     gyroZFilter = ZetaLowPass(zeta_low_pass_gyroZ_cutoff, zeta_low_pass_gyroZ_rate);
}

void Drone::Calibrate_Drone(void)
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
    // we can add the buffer log here just to test
    // BufferLog.AddLog("AccX", AccX);
    // BufferLog.AddLog("AccY", AccY);
    ApplyLowPass();
    String fullLog = "AccX:" + String(AccX);
    String fullLog1 = "AccXFilter:" + String(AccX_Low_Pass);
    Serial.println(fullLog);
    Serial.println(fullLog1);
    // BufferLog.AddLog("AccZ", AccZ);
    // BufferLog.AddLog("RateRoll", RateRoll);
    // BufferLog.AddLog("RatePitch", RatePitch);
    // BufferLog.AddLog("RateYaw", RateYaw);
    // Serial.print(AccX);
    // Serial.print(" ");
    // Serial.print(AccY);
    // Serial.print("\n");
}
void Drone::ApplyLowPass(void)
{
    AccX_Low_Pass = accelXFilter.process(AccX);
    AccY_Low_Pass = accelYFilter.process(AccY);
    AccZ_Low_Pass = accelZFilter.process(AccZ);
    RateRoll_Low_Pass = gyroXFilter.process(RateRoll);
    RatePitch_Low_Pass = gyroYFilter.process(RatePitch);
    RateYaw_Low_Pass = gyroZFilter.process(RateYaw);
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

void Drone::updateRCIN(void)
{
// updating the store
//using ppm signal
// #ifdef USE_PPM
//     zetaRcin.update();
//     Receiver_Values = zetaRcin.Receiver_Values_Store();
// #endif
// //using pwm signal 
// #ifdef USE_PWM
//     //No need to upadte the values, inturrupt services are updated by themself
//     Receiver_Values = zetaRcin.get_PWM_Value();
// #endif
}

std::vector<float> Drone::Return_Receiver_Store()
{
    return Receiver_Values;
}
