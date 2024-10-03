#include "./dataSender.h"
#include <fstream>

// Create a random number generator
std::mt19937 rng(static_cast<unsigned int>(time(0)));  // Seed with current time

// Function to generate random temperature in the range of 94 - 103
int generateTemperature() {
    int minTempurature = 94;  // Fahrenheit
    int maxTemperature = 103;
    std::uniform_int_distribution<int> dist(minTempurature, maxTemperature);
    return dist(rng);
}

// Function to generate random pulse rate in the range of 59 - 100
int generatePulseRate() {
    int minPulseRate = 59;  // bpm
    int maxPulseRate = 100;
    std::uniform_int_distribution<int> dist(minPulseRate, maxPulseRate);
    return dist(rng);
}

// Function to generate random SpO2 level in the range of 89 - 100
int generateSpO2() {
    int minSpo2 = 89;  // Percentage
    int maxSpo2 = 100;
    std::uniform_int_distribution<int> dist(minSpo2, maxSpo2);
    return dist(rng);
}

// Function to generate and output 50 lines of data to a file
void generateData() {
    std::ofstream outFile("outputData.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing" << std::endl;
        return;
    }

    // Unit : "Temperature (F), Pulse Rate (bpm), SpO2 (%)";
    for (int i = 0; i < 50; ++i) {
        float temperature = generateTemperature();
        int pulseRate = generatePulseRate();
        int spo2 = generateSpO2();

        outFile << temperature << ", " << pulseRate << ", " << spo2 << "\n";
    }

    outFile.close();
}
