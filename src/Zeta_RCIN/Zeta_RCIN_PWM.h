#ifndef ZETA_RCIN_H
#define ZETA_RCIN_H

#include <Arduino.h>
#include <param.h>
#include <vector>

class ZetaRCIN_PWM {
public:
    // Define functions that will be called during interrupts
    void handleInterrupt1();
    void handleInterrupt2();
    void handleInterrupt3();
    void handleInterrupt4();
    void handleInterrupt5();
    void handleInterrupt6();
    
    // Function to compute the calculate pwm signal value
    void common_for_calculation(int pin_val, int channel_val, int input_val, int timer_val);
    
    // Function to get the value of the channel
    std::vector<int> get_PWM_Value(void);
    
    // Adding constructor to initialize values and interrupt functions
    ZetaRCIN_PWM();

private:
    unsigned long timer[6];
    int last_channel[6];
    int input[6];
    std::vector<int> Receiver_Values;
    
    // PWM Pin variables
    int pwmPin1;
    int pwmPin2;
    int pwmPin3;
    int pwmPin4;
    int pwmPin5;
    int pwmPin6;
};

#endif // ZETA_RCIN_H
