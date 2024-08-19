#ifndef PARAM_H
#define PARAM_H

// MPU6050 Parameters
#define MPU6050_ADDRESS 0x68

// RC PPM Parameters
// use the below macros to choose from PWM and PPM Inputs
// #define USE_PPM
#define USE_PWM

#define RC_PPM_PIN 1
#define RC_PWM_PIN_1 1
#define RC_PWM_PIN_2 2
#define RC_PWM_PIN_3 3
#define RC_PWM_PIN_4 4
#define RC_PWM_PIN_5 5
#define RC_PWM_PIN_6 6



// Zeta Buffer Parameters
#define CIRCULAR_BUFFER_SIZE 1024

// LED Parameters
#define LED_BPIN 13
#define LED_RPIN 12

#endif 
