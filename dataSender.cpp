#include "./dataSender.h"

// Function to generate random temperature in the range of 94 - 103
int generateTemperature() {
    int minTempurature = 94;  // Fahrenheit
    int maxTemperature = 103;
    return minTempurature + rand_r() % (maxTemperature - minTempurature + 1);
}

// Function to generate random pulse rate in the range of 59 - 100
int generatePulseRate() {
    int minPulseRate = 59;  // bpm
    int maxPulseRate = 100;
    return minPulseRate + rand_r() % (maxPulseRate - minPulseRate + 1);
}

// Function to generate random SpO2 level in the range of 89 - 100
int generateSpO2() {
    int minSpo2 = 89;  // Percentage
    int maxSpo2 = 100;
    return minSpo2 + rand_r() % (maxSpo2 - minSpo2 + 1);
}

// Function to generate and output 50 lines of data to console
void generateData() {
    // Unit : "Temperature (F), Pulse Rate (bpm), SpO2 (%)";

    for (int i = 0; i < 50; ++i) {
        float temperature = generateTemperature();
        int pulseRate = generatePulseRate();
        int spo2 = generateSpO2();

        std::cout << temperature << ", " << pulseRate << ", " << spo2 << "\n";
    }
}

