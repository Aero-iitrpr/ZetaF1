//experimental version, needs to be tested

#include <PulsePosition.h>
#include <Arduino.h>
#include  "Zeta_RCIN_PWM.h"

void Zeta_RCIN_PWM::ZetaRCIN_PWM()(void)
{   // Set the pins
    pwmPin1 = RC_PWM_PIN 1;
    pwmPin2 = RC_PWM_PIN 2;
    pwmPin3 = RC_PWM_PIN 3;
    pwmPin4 = RC_PWM_PIN 4;
    pwmPin5 = RC_PWM_PIN 5;
    pwmPin6 = RC_PWM_PIN 6;
    
    // Set the pins as input
    pinMode(pwmPin2, INPUT);  
    pinMode(pwmPin1, INPUT);  
    pinMode(pwmPin3, INPUT);  
    pinMode(pwmPin4, INPUT);  
    pinMode(pwmPin5, INPUT);  
    pinMode(pwmPin6, INPUT);  

    // Attach interrupt to each pin , there are total 6 pins available for pwn input in our tennsy40
    attachInterrupt(digitalPinToInterrupt(pwmPin1), handleInterrupt1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pwmPin2), handleInterrupt2, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pwmPin3), handleInterrupt3, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pwmPin4), handleInterrupt4, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pwmPin5), handleInterrupt5, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pwmPin6), handleInterrupt6, CHANGE);
    
    //initializing input vector
    Receiver_Values.resize(6);
}

void Zeta_RCIN_PWM::handleInterrupt1(void){
    common_for_calculation(pwmPin1,0,0,1);
}
void Zeta_RCIN_PWM::handleInterrupt2(void){
    common_for_calculation(pwmPin2,1,1,2);
}
void Zeta_RCIN_PWM::handleInterrupt3(void){
    common_for_calculation(pwmPin3,2,2,3);
}
void Zeta_RCIN_PWM::handleInterrupt4(void){
    common_for_calculation(pwmPin4,3,3,4);
}
void Zeta_RCIN_PWM::handleInterrupt5(void){
    common_for_calculation(pwmPin5,4,4,5);
}
void Zeta_RCIN_PWM::handleInterrupt6(void){
    common_for_calculation(pwmPin6,5,5,6);
}

void Zeta_RCIN_PWM::common_for_calculation(int pin_val,int channel_val,int input_val,int timer_val)
{
    int pin = pin_val;
    timer[0] = micros();
    if (last_channel[channel_val] == 0 && digitalRead(pin) == HIGH) 
  {
    last_channel[channel] = 1;
    timer[timer_val] = timer[0];
  } 
  else if (last_channel[channel_val] == 1 && digitalRead(pin) == LOW) 
  {
    last_channel[channel_val] = 0;
    input[input_val] = timer[0] - timer[timer_val];
  }
    if (input[input_val]<0){
        return 0;
    }
}  
std::vector<int> Zeta_RCIN_PWM::get_PWM_Value()
{
    for (int i = 0; i < Receiver_Values.size();i ++){Receiver_Value.push_back(input[i]);}
    return Receiver_Value;
}


