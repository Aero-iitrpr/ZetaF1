//experimental version, needs to be tested

#include <PulsePosition.h>
#include <Arduino.h>
#include <Zeta_RCIN/Zeta_RCIN_PPM.h>
#include <vector>

void ZetaRCIN_PPM::initialize()
{
    // For this version we will using 3rd party module
    // Next version we will be implementing our own
    // setting the pin
    _pin = RC_PPM_PIN;
    PPM_Receiver.begin(_pin);
    Number_Channels = PPM_Receiver.available();
    Receiver_Values.resize(Number_Channels);
}

void ZetaRCIN_PPM::update()
{
    // accepting only if the number of channels are greater than 0
    // most common channel numbers - 6, 10, 12
    if (Number_Channels > 0)
    {
        for(int i=0;i<Number_Channels;i++)
        {
            Receiver_Values[i]=PPM_Receiver.read(i+1);
        }
    }
    else
    {
        //add led support for the error in RX TX
    }

}

//this function return the vector of receiver values
//PPM support only
std::vector<float> ZetaRCIN_PPM::Receiver_Values_Store()
{
    return Receiver_Values;
}
