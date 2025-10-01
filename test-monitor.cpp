#include "./monitor.h"
#include <gtest/gtest.h>
#include <vector>
using std::vector;

TEST(Monitor_Temperature, TemperatureIsHigh) {
    std::vector<float> currentValues = {115.5, 80, 95};
    checkVital(currentValues, false, "Temp is high, condition is critical");
}

TEST(Monitor_Temperature, TemperatureIsLow) {
    std::vector<float> currentValues = {90, 80, 95};
    checkVital(currentValues, false, "Temp is low, condition is critical");
}

TEST(Monitor_Temperature, TemperatureIsNormal) {
    std::vector<float> currentValues = {98, 80, 95};
    checkVital(currentValues, true, "Temp is normal, all OK");
}

TEST(Monitor_PulseRate, PulseRateIsHigh) {
    std::vector<float> currentValues = {98, 120, 95};
    checkVital(currentValues, false, "PulseRate is high, condition is critical");
}

TEST(Monitor_PulseRate, PulseRateIsLow) {
    std::vector<float> currentValues = {98, 50, 95};
    checkVital(currentValues, false, "PulseRate is low, condition is critical");
}

TEST(Monitor_PulseRate, PulseRateIsNormal) {
    std::vector<float> currentValues = {98, 80, 95};
    checkVital(currentValues, true, "PulseRate is normal, all OK");
}

TEST(Monitor_Sp02, Sp02IsLow) {
    std::vector<float> currentValues = {98, 80, 85};
    checkVital(currentValues, false, "Sp02 is low, condition is critical");
}

TEST(Monitor_Sp02, Sp02IsNormal) {
    std::vector<float> currentValues = {98, 80, 95};
    checkVital(currentValues, true, "Sp02 is normal, all OK");
}