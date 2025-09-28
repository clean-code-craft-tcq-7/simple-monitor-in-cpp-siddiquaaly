#include <gtest/gtest.h>
#include "./monitor.h"

// TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
//   ASSERT_FALSE(vitalsOk(99, 102, 70));
//   ASSERT_TRUE(vitalsOk(98.1, 70, 98));
// }


TEST(Monitor_Temperature, TemperatureIsHigh) 
{ //enter the current vital value of temperature, pulseRate, spo2
  vector<float> currentValues = {115.5,80,95}
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "Temp is high, condition is critical";
}

TEST(Monitor_Temperature, TemperatureIsLow) 
{ //enter the current vital value of temperature, pulseRate, spo2
  vector<float> currentValues = {90.5,80,95}
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "Temp is low, condition is critical";
}

TEST(Monitor_Temperature, TemperatureIsNormal) 
{ //enter the current vital value of temperature, pulseRate, spo2
  vector<float> currentValues = {98.8,80,95}
  EXPECT_TRUE(isVitalsNormal(currentValues)) << "Temp is Normal, All OK";
}

TEST(Monitor_PulseRate, PulseRateIsHigh) 
{ //enter the current vital value of temperature, pulseRate, spo2
  vector<float> currentValues = {98,102,95}
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "PulseRate is high, condition is critical";
}

TEST(Monitor_PulseRate, PulseRateIsLow) 
{ //enter the current vital value of temperature, pulseRate, spo2
  vector<float> currentValues = {96,59,95}
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "PulseRate is low, condition is critical";
}

TEST(Monitor_PulseRate, PulseRateIsNormal) 
{ //enter the current vital value of temperature, pulseRate, spo2
  vector<float> currentValues = {100,80,95}
  EXPECT_TRUE(isVitalsNormal(currentValues)) << "PulseRate is Normal, All OK";
}

TEST(Monitor_Sp02, Sp02IsLow) 
{ //enter the current vital value of temperature, pulseRate, spo2
  vector<float> currentValues = {96,80,88}
  EXPECT_FALSE(isVitalsNormal(currentValues)) << "Sp02 is low, condition is critical";
}

TEST(Monitor_Sp02, Sp02IsNormal) 
{ //enter the current vital value of temperature, pulseRate, spo2
  vector<float> currentValues = {100,80,95}
  EXPECT_TRUE(isVitalsNormal(currentValues)) << "Sp02 is Normal, All OK";
}