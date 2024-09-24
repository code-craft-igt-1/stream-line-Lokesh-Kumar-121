#include <gtest/gtest.h>
#include "./dataSender.h"

// Test temperature generation function returns a value within the expected range (94 - 103)
TEST(HealthDataTest, TestGenerateTemperatureRange) {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator
    for (int i = 0; i < 5; ++i) {  // Test multiple times to cover randomness
        int temp = generateTemperature();
        ASSERT_GE(temp, 94) << "Temperature is below the valid range!";
        ASSERT_LE(temp, 103) << "Temperature is above the valid range!";
    }
}

// Test pulse rate generation function returns a value within the expected range (59 - 100)
TEST(HealthDataTest, TestGeneratePulseRateRange) {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator
    for (int i = 0; i < 5; ++i) {  // Test multiple times to cover randomness
        int pulse = generatePulseRate();
        ASSERT_GE(pulse, 59) << "Pulse rate is below the valid range!";
        ASSERT_LE(pulse, 100) << "Pulse rate is above the valid range!";
    }
}

// Test SpO2 generation function returns a value within the expected range (89 - 100)
TEST(HealthDataTest, TestGenerateSpO2Range) {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator
    for (int i = 0; i < 5; ++i) {  // Test multiple times to cover randomness
        int spo2 = generateSpO2();
        ASSERT_GE(spo2, 89) << "SpO2 is below the valid range!";
        ASSERT_LE(spo2, 100) << "SpO2 is above the valid range!";
    }
}

// Test the generateData function
TEST(HealthDataTest, TestGenerateDataExecution) {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator
    ASSERT_NO_THROW(generateData());  // Ensure generateData doesn't throw any exceptions
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
