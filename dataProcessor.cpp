#include <limits>
#include <queue>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include "./dataSender.h"

// Function to read data from file

std::vector<std::tuple<float, int, int>> readDataFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::vector<std::tuple<float, int, int>> data;
    if (!inFile) {
        std::cerr << "Error opening file for reading" << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        float temperature;
        int pulseRate, spo2;
        char comma;   // To consume the commas in the input
        if (!(iss >> temperature >> comma >> pulseRate >> comma >> spo2)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }
        data.emplace_back(temperature, pulseRate, spo2);
    }

    inFile.close();
    return data;
}

// Function to calculate maximum value
float calculateMaxValue(const std::vector<std::tuple<float, int, int>>& data) {
    float maxVal = std::numeric_limits<float>::min();
    for (const auto& entry : data) {
        float temperature = std::get<0>(entry);
        if (temperature > maxVal) maxVal = temperature;
    }
    return maxVal;
}

// Function to calculate minimum value
float calculateMinValue(const std::vector<std::tuple<float, int, int>>& data) {
    float minVal = std::numeric_limits<float>::max();
    for (const auto& entry : data) {
        float temperature = std::get<0>(entry);
        if (temperature < minVal) minVal = temperature;
    }
    return minVal;
}

// Function to calculate simple moving average (SMA) of the last 5 values
double calculateSMA(const std::vector<std::tuple<float, int, int>>& data) {
    std::queue<float> lastFiveValues;
    float sum = 0;
    for (const auto& entry : data) {
        float temperature = std::get<0>(entry);
        if (lastFiveValues.size() == 5) {
            sum -= lastFiveValues.front();
            lastFiveValues.pop();
        }
        lastFiveValues.push(temperature);
        sum += temperature;
    }
    int count = lastFiveValues.size();
    return static_cast<double>(sum) / count;
}

// Function to print results
void printResults(float maxVal, float minVal, double sma) {
    std::cout << "Max: " << maxVal << ", Min: " << minVal
              << ", SMA: " << std::fixed << std::setprecision(2) << sma << std::endl;
}

// Main function to process data
void processData() {
    auto data = readDataFromFile("outputData.txt");
    if (data.empty()) return;

    float maxVal = calculateMaxValue(data);
    float minVal = calculateMinValue(data);
    double sma = calculateSMA(data);

    printResults(maxVal, minVal, sma);
}

int main() {
    processData();
    return 0;
}
