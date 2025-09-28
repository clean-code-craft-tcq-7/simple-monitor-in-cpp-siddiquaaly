#pragma once
#include <vector>
#include <string>
using std::cout, std::vector,std::flush, std::this_thread::sleep_for, std::chrono::seconds;

struct vitalRange{
  std::string name;
  float minNormal;
  float maxNormal;
}

extern const std::vector<vitalRange> vitals;

void  vitalsCriticalAttention(void);
bool isVitalsNormal(const vector<float>& currentValues);
bool isSingleVitalNormal(float currentValue, const vitalRange& vital);

