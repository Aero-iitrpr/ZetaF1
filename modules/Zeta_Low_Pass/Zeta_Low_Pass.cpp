#include "Zeta_Low_Pass.h"
#include <cmath>

ZetaLowPass::ZetaLowPass(float cutoffFrequency, float sampleRate)
    : cutoffFrequency(cutoffFrequency), sampleRate(sampleRate), prevOutput(0.0) {
    updateAlpha();
}

// Method to set the cutoff frequency
void ZetaLowPass::setCutoffFrequency(float newCutoffFrequency) {
    cutoffFrequency = newCutoffFrequency;
    updateAlpha();
}

// Method to set the sample rate
void ZetaLowPass::setSampleRate(float newSampleRate) {
    sampleRate = newSampleRate;
    updateAlpha();
}

// Method to process a single sample through the filter
float ZetaLowPass::process(float input) {
    float output = alpha * input + (1.0 - alpha) * prevOutput;
    prevOutput = output;
    return output;
}

// Method to update the alpha value
void ZetaLowPass::updateAlpha() {
    float rc = 1.0 / (2.0 * 3.14159265358979323846 * cutoffFrequency);
    float dt = 1.0 / sampleRate;
    alpha = dt / (rc + dt);
}