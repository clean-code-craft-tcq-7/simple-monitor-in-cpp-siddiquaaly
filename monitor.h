#pragma once
#include <vector>
#include <string>

struct vitalRange{
  std::string name;
  float minNormal;
  float maxNormal;
}

extern const std::vector<vitalRange> vitals;

int vitalsCheck(const vector<float>& currentValues);
void  vitalsCriticalAttention(void);

