#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;


void  vitalsCriticalAttention(void)
{
    for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}

int vitalsCheck(const vector<float>& currentValues)
{
   for(size_t i=0;i<currentValues.size();i++)
  { float currentValue = currentValues[i];
    const auto& vital = vitals[i];
    if( currentValue > vital.maxNormal || currentValue< vital.minNormal)
    {
      cout<<vital.name<<"= "<<currentValue<<" is critical"<<endl;
      vitalsCriticalAttention();
      return 0;
    }  
  }
return 1;
}


