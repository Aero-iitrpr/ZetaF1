#ifndef PARAM_H
#define PARAM_H

// MPU6050 Parameters
#define MPU6050_ADDRESS 0x68

//RC PPM Parameters
// #define RC_PPM_PIN 1
// #define USE_PPM
//use the below macro in case of pwm input
#define USE_PWM
#define RC_PWM_PIN_1 1
#define RC_PWM_PIN_2 2
#define RC_PWM_PIN_3 3
#define RC_PWM_PIN_4 4
#define RC_PWM_PIN_5 5
#define RC_PWM_PIN_6 6



// Zeta Buffer Parameters
#define CIRCULAR_BUFFER_SIZE 1024

#endif 
