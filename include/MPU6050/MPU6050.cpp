#include "mpu6050.h"
#include <Wire.h>
#include <Arduino.h>

void MPU6050Sensor::initialize()
{
    // initiating the MPU6050 I2C communication
    Wire.beginTransmission(MPU_Address);
    Wire.write(0x6B);
    Wire.write(0x00);
    Wire.endTransmission();

    // Initialize low-pass filters with appropriate cutoff frequency and sample rate
    float cutoffFrequency = 5.0; // change this to the actual cutoff frequency
    float sampleRate = 100.0; // change this to the actual sample rate

    accelXFilter = ZetaLowPass(cutoffFrequency, sampleRate);
    accelYFilter = ZetaLowPass(cutoffFrequency, sampleRate);
    accelZFilter = ZetaLowPass(cutoffFrequency, sampleRate);
    gyroXFilter = ZetaLowPass(cutoffFrequency, sampleRate);
    gyroYFilter = ZetaLowPass(cutoffFrequency, sampleRate);
    gyroZFilter = ZetaLowPass(cutoffFrequency, sampleRate);
}

bool MPU6050Sensor::check()
{
    Wire.beginTransmission(MPU_Address);
    int Gyro_Error = Wire.endTransmission();
    while (Gyro_Error != 0)
    {
        Serial.print("Gyro Not Available");
        Serial.println();
        return false;
    }
    return true;
}

void MPU6050Sensor::MPU6050_Output()
{
    Wire.beginTransmission(MPU_Address);
    Wire.write(0x1A);
    Wire.write(0x05);
    Wire.endTransmission();
    Wire.beginTransmission(MPU_Address);
    Wire.write(0x1C);
    Wire.write(0x10);
    Wire.endTransmission();
    Wire.beginTransmission(MPU_Address);
    Wire.write(0x3B);
    Wire.endTransmission();
    Wire.requestFrom(MPU_Address, 6);
    UAccX = Wire.read() << 8 | Wire.read();
    UAccY = Wire.read() << 8 | Wire.read();
    UAccZ = Wire.read() << 8 | Wire.read();
    Wire.beginTransmission(MPU_Address);
    Wire.write(0x1B);
    Wire.write(0x8);
    Wire.endTransmission();
    Wire.beginTransmission(MPU_Address);
    Wire.write(0x43);
    Wire.endTransmission();
    Wire.requestFrom(MPU_Address, 6);
    UGyro_Roll = Wire.read() << 8 | Wire.read();
    UGyro_Pitch = Wire.read() << 8 | Wire.read();
    UGyro_Yaw = Wire.read() << 8 | Wire.read();
    AccX = (float)UAccX / 4096;
    AccY = (float)UAccY / 4096;
    AccZ = (float)UAccZ / 4096;
    RateRoll = (float)UGyro_Roll / 65.5;
    RatePitch = (float)UGyro_Pitch / 65.5;
    RateYaw = (float)UGyro_Yaw / 65.5;

    // Apply low-pass filters to the accelerometer and gyroscope data
    AccX = accelXFilter.process(AccX);
    AccY = accelYFilter.process(AccY);
    AccZ = accelZFilter.process(AccZ);
    RateRoll = gyroXFilter.process(RateRoll);
    RatePitch = gyroYFilter.process(RatePitch);
    RateYaw = gyroZFilter.process(RateYaw);
}

void MPU6050Sensor::Gyro_Caliberate(void)
{
    //add led support
    //add error support
    Gyro_Caliberation_Num = 0;
    UGyro_Roll_Cal = 0;
    UGyro_Pitch_Cal = 0;
    UGyro_Yaw_Cal = 0;
    for (Gyro_Caliberation_Num = 0; Gyro_Caliberation_Num < 2000; Gyro_Caliberation_Num++)
    {
        // be carefull with the below declaration
        MPU6050_Output();
        UGyro_Roll_Cal += RateRoll;
        UGyro_Pitch_Cal += RatePitch;
        UGyro_Yaw_Cal += RateYaw;
        // delay 4ms for gathering the data
        delay(4);
    }
    UGyro_Roll_Cal /= 2000;
    UGyro_Pitch_Cal /= 2000;
    UGyro_Yaw_Cal /= 2000;
}

void MPU6050Sensor::Accel_Caliberate(void)
{
    //add led support
    //add error support
    Accel_Caliberation_Num = 0;
    Accel_Roll_Cal = 0;
    Accel_Pitch_Cal = 0;
    for (Accel_Caliberation_Num = 0; Accel_Caliberation_Num < 65; Accel_Caliberation_Num++)
    {
        MPU6050_Output();
        Accel_Roll_Cal += AccX;
        Accel_Pitch_Cal += AccY;
        Accel_Yaw_Cal += AccZ;
        delay(4);
    }
    Accel_Roll_Cal /= 65;
    Accel_Pitch_Cal /= 65;
    Accel_Yaw_Cal /= 65;
}

float MPU6050Sensor::getAccelX(void)
{
    AccX -= Accel_Roll_Cal;
    return AccX;
}

float MPU6050Sensor::getAccelY(void)
{
    AccY -= Accel_Pitch_Cal;
    return AccY;
}

float MPU6050Sensor::getAccelZ(void)
{
    AccZ -= Accel_Yaw_Cal;
    return AccZ;
}

float MPU6050Sensor::getGyroX(void)
{
    RateRoll -= UGyro_Roll_Cal;
    return RateRoll;
}

float MPU6050Sensor::getGyroY(void)
{
    RatePitch -= UGyro_Pitch_Cal;
    return RatePitch;
}

float MPU6050Sensor::getGyroZ(void)
{
    RateYaw -= UGyro_Yaw_Cal;
    return RateYaw;
}


