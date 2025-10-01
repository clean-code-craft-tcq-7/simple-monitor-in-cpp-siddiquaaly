#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::vector,std::flush, std::this_thread::sleep_for, std::chrono::seconds;

// Define vital ranges once
const std::vector<vitalRange> vitals = {
  {"Temperature", 95, 102},
  {"PulseRate",60,100},
  {"Sp02",90,200}
};
/*
*Function to draw attention of user if any of the vital are abnormal
*/
void  vitalsCriticalAttention(void)
{
    for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}

/*
*Function to check if each vital is normal
*/
bool isSingleVitalNormal(float currentValue, const vitalRange& vital)
{
    return (currentValue >= vital.minNormal && currentValue <= vital.maxNormal);
}

/*
*Function to check if any of the vitals are critical/abnormal
*/
bool isVitalsNormal(const vector<float>& currentValues)
{
    for (std::size_t i = 0; i < currentValues.size(); i++)
    {
        float currentValue = currentValues[i];
        const auto& vital = vitals[i];

        if (!isSingleVitalNormal(currentValue, vital))
        {
            std::cout << vital.name << " = " << currentValue << " is critical" << std::endl;
            vitalsCriticalAttention();
            return false; // return false if any vital is abnormal
        }
    }
    return true; // return true if all vitals are normal
}



