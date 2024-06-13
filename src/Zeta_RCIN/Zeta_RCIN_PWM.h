#ifndef Zeta_RCIN_H
#define Zeta_RCIN_H
#include <Arduino.h>
#include <param.h>
#include <vector>

class ZetaRCIN_PWM
{
    public:
        // define functions that will be called during interrupts
        void handleInterrupt1();
        void handleInterrupt2();
        void handleInterrupt3();
        void handleInterrupt4();
        void handleInterrupt5();
        void handleInterrupt6();
        //function to compute the calculate pwm signal value
        void common_for_calculation(int pin);
        // function to get the value of the channel
        std::vector<int> get_PWM_Value(void);
        
        // adding constructor to initaialzie values and inturrupt functios
        ZetaRCIN_PWM();

    private:
        unsigned long timer[6];
        int last_channel[6];
        int input[6];
        std::vector<int> Receiver_Values;
};
#endif// Zeta_RCIN_H