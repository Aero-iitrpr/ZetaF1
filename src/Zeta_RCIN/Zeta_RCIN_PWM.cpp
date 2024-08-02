// #include <PulsePosition.h>
// #include <Arduino.h>
// #include <Zeta_RCIN/Zeta_RCIN_PWM.h>

// ZetaRCIN_PWM::ZetaRCIN_PWM() {
//     // Set the pins
//     pwmPin1 = RC_PWM_PIN_1;
//     pwmPin2 = RC_PWM_PIN_2;
//     pwmPin3 = RC_PWM_PIN_3;
//     pwmPin4 = RC_PWM_PIN_4;
//     pwmPin5 = RC_PWM_PIN_5;
//     pwmPin6 = RC_PWM_PIN_6;
    
//     // Set the pins as input
//     pinMode(pwmPin1, INPUT);  
//     pinMode(pwmPin2, INPUT);  
//     pinMode(pwmPin3, INPUT);  
//     pinMode(pwmPin4, INPUT);  
//     pinMode(pwmPin5, INPUT);  
//     pinMode(pwmPin6, INPUT);  
//     // Attach interrupt to each pin , there are total 6 pins available for pwm input in our tennsy40
//     attachInterrupt(digitalPinToInterrupt(pwmPin1), handleInterrupt1, CHANGE);
//     attachInterrupt(digitalPinToInterrupt(pwmPin2), handleInterrupt2, CHANGE);
//     attachInterrupt(digitalPinToInterrupt(pwmPin3), handleInterrupt3, CHANGE);
//     attachInterrupt(digitalPinToInterrupt(pwmPin4), handleInterrupt4, CHANGE);
//     attachInterrupt(digitalPinToInterrupt(pwmPin5), handleInterrupt5, CHANGE);
//     attachInterrupt(digitalPinToInterrupt(pwmPin6), handleInterrupt6, CHANGE);
    
//     // Initializing input vector
//     Receiver_Values.resize(6);
// }

// void ZetaRCIN_PWM::handleInterrupt1() {
//     common_for_calculation(pwmPin1, 0, 0, 1);
// }

// void ZetaRCIN_PWM::handleInterrupt2() {
//     common_for_calculation(pwmPin2, 1, 1, 2);
// }

// void ZetaRCIN_PWM::handleInterrupt3() {
//     common_for_calculation(pwmPin3, 2, 2, 3);
// }

// void ZetaRCIN_PWM::handleInterrupt4() {
//     common_for_calculation(pwmPin4, 3, 3, 4);
// }

// void ZetaRCIN_PWM::handleInterrupt5() {
//     common_for_calculation(pwmPin5, 4, 4, 5);
// }

// void ZetaRCIN_PWM::handleInterrupt6() {
//     common_for_calculation(pwmPin6, 5, 5, 6);
// }

// void ZetaRCIN_PWM::common_for_calculation(int pin_val, int channel_val, int input_val, int timer_val) {
//     int pin = pin_val;
//     timer[0] = micros();
//     if (last_channel[channel_val] == 0 && digitalRead(pin) == HIGH) {
//         last_channel[channel_val] = 1;
//         timer[timer_val] = timer[0];
//     } else if (last_channel[channel_val] == 1 && digitalRead(pin) == LOW) {
//         last_channel[channel_val] = 0;
//         input[input_val] = timer[0] - timer[timer_val];
//     }
//     if (input[input_val] < 0) {
//         input[input_val] = 0;  // Fixing invalid negative input value
//     }
// }

// std::vector<int> ZetaRCIN_PWM::get_PWM_Value() {
//     std::vector<int> Receiver_Value;
//     for (int i = 0; i < Receiver_Values.size(); i++) {
//         Receiver_Value.push_back(input[i]);
//     }
//     return Receiver_Value;
// }
