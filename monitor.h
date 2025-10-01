#pragma once
#include <vector>
#include <string>

struct vitalRange{
  std::string name;
  float minNormal;
  float maxNormal;
};

extern const std::vector<vitalRange> vitals;

void  vitalsCriticalAttention(void);
bool isVitalsNormal(const std::vector<float>& currentValues);
bool isSingleVitalNormal(float currentValue, const vitalRange& vital);
void checkVital(const std::vector<float>& values, bool expectedNormal, const std::string& message);
