#ifndef ZETA_LOW_PASS_H
#define ZETA_LOW_PASS_H

class ZetaLowPass {
public:
    
    ZetaLowPass(float cutoffFrequency = 1.0, float sampleRate = 1.0);

    // Method to set the cutoff frequency
    void setCutoffFrequency(float cutoffFrequency);

    // Method to set the sample rate
    void setSampleRate(float sampleRate);

    // Method to process a single sample through the filter
    float process(float input);

private:
    float cutoffFrequency;
    float sampleRate;
    float alpha;
    float prevOutput;

    // Method to update the alpha value based on the current cutoff frequency and sample rate
    void updateAlpha();
};

#endif // ZETA_LOW_PASS_H

