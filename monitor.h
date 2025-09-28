#pragma once
#include <vector>
#include <string>

struct vitalRange{
  std::string name;
  float minNormal;
  float maxNormal;
}

extern const std::vector<vitalRange> vitals;

void  vitalsCriticalAttention(void);
bool isVitalsNormal(const vector<float>& currentValues);
bool isSingleVitalNormal(float currentValuev, const vitalRange& vital);

