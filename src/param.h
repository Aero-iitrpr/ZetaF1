#ifndef PARAM_H
#define PARAM_H

// MPU6050 Parameters
#define MPU6050_ADDRESS 0x68

// BMP180 Parameters
#define BMP180_ADDRESS 0x77

#define BMP180_REG_CONTROL 0xF4
#define BMP180_REG_RESULT 0xF6

#define BMP180_CMD_TEMPERATURE 0x2E
#define BMP180_CMD_PRESSURE 0x34

//RC PPM Parameters
#define RC_PPM_PIN 1
// #define USE_PPM
//use the below macro in case of pwm input
#define USE_PWM
#define RC_PWM_PIN_1 1
#define RC_PWM_PIN_2 2
#define RC_PWM_PIN_3 3
#define RC_PWM_PIN_4 4
#define RC_PWM_PIN_5 5
#define RC_PWM_PIN_6 6

//constant parameters
//Task add the range of the values
const float zeta_low_pass_accelX_cutoff=1.0;
const float zeta_low_pass_accelY_cutoff=1.0;
const float zeta_low_pass_accelZ_cutoff=1.0;
const float zeta_low_pass_gyroX_cutoff=1.0;
const float zeta_low_pass_gyroY_cutoff=1.0;
const float zeta_low_pass_gyroZ_cutoff=1.0;

const float zeta_low_pass_accelX_rate=1.0;
const float zeta_low_pass_accelY_rate=1.0;
const float zeta_low_pass_accelZ_rate=1.0;
const float zeta_low_pass_gyroX_rate=1.0;
const float zeta_low_pass_gyroY_rate=1.0;
const float zeta_low_pass_gyroZ_rate=1.0;


// Zeta Buffer Parameters
#define CIRCULAR_BUFFER_SIZE 1024

#endif 
