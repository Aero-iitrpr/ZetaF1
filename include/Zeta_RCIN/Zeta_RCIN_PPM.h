#ifndef Zeta_RCIN_H
#define Zeta_RCIN_H
#include <Arduino.h>
#include <param.h>
#include <vector>
#include <PulsePosition.h>


class ZetaRCIN_PPM
{
public:
    // setup for PPM input
    void initialize();
    void update();
    int Number_Channels;
    std::vector<float> Receiver_Values_Store();
    // adding constructor for the initialization for ppm module
    ZetaRCIN_PPM() : PPM_Receiver(RISING) {}

private:
    PulsePositionInput PPM_Receiver;
    int _pin;
    int Number_Channels;
    std::vector<float> Receiver_Values;
};

extern ZetaRCIN_PPM zetaRcinPPM;

#endif // Zeta_RCIN_H
