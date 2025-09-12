#pragma once

struct vitalRange{
  string name;
  float minNormal;
  float maxNormal;
}

const vector<vitalRange> vitals = {
  {"Temperature", 95, 102},
  {"PulseRate",60,100},
  {"Sp02",90,200}
};

// int vitalsOk(float temperature, float pulseRate, float spo2);
int vitalsCheck(const vector<float>& currentValues);
void  vitalsCriticalAttention(void);

