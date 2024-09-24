#ifndef DATA_SENDER_H
#define DATA_SENDER_H

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

// Function to generate random temperature in the range of 94 - 103
int generateTemperature();

// Function to generate random pulse rate in the range of 59 - 100
int generatePulseRate();

// Function to generate random SpO2 level in the range of 89 - 100
int generateSpO2();

// Function to generate and output 50 lines of data to console
void generateData();

#endif // DATA_SENDER_H
