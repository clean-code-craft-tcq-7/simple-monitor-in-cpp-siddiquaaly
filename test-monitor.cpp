#include "./monitor.h"
#include <gtest/gtest.h>
#include <vector>
using std::vector;

TEST(MonitorTemperature, TemperatureIsHigh) {
  // Current vital values: Temperature, PulseRate, SpO2
  vector<float> currentValues = {115.5, 80, 95};
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "Temp is high, condition is critical";
}

TEST(Monitor_Temperature, TemperatureIsLow) { 
  // Current vital values: Temperature, PulseRate, SpO2
  vector<float> currentValues = {90.5,80,95};
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "Temp is low, condition is critical";
}

TEST(Monitor_Temperature, TemperatureIsNormal) { 
  // Current vital values: Temperature, PulseRate, SpO2
  vector<float> currentValues = {98.8,80,95};
  EXPECT_TRUE(isVitalsNormal(currentValues)) << "Temp is Normal, All OK";
}

TEST(Monitor_PulseRate, PulseRateIsHigh) { 
  // Current vital values: Temperature, PulseRate, SpO2
  vector<float> currentValues = {98,102,95};
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "PulseRate is high, condition is critical";
}

TEST(Monitor_PulseRate, PulseRateIsLow) { 
  // Current vital values: Temperature, PulseRate, SpO2
  vector<float> currentValues = {96,59,95};
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "PulseRate is low, condition is critical";
}

TEST(Monitor_PulseRate, PulseRateIsNormal) { 
  // Current vital values: Temperature, PulseRate, SpO2
  vector<float> currentValues = {100,80,95};
  EXPECT_TRUE(isVitalsNormal(currentValues)) << "PulseRate is Normal, All OK";
}

TEST(Monitor_Sp02, Sp02IsLow) { 
  // Current vital values: Temperature, PulseRate, SpO2
  vector<float> currentValues = {96,80,88};
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "Sp02 is low, condition is critical";
}

TEST(Monitor_Sp02, Sp02IsNormal) { 
  // Current vital values: Temperature, PulseRate, SpO2
  vector<float> currentValues = {100,80,95};
  EXPECT_TRUE(isVitalsNormal(currentValues)) << "Sp02 is Normal, All OK";
}