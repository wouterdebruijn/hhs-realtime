#include <iostream>
#include <unistd.h>
#include <iostream>
#include "Timer.h"
#include <thread>

using namespace std;

void doeIets(char c, unsigned int tijd, unsigned int aantal);

int main()
{
  Timer tm1;
  tm1.Reset();
  
  thread t0(doeIets, 'p', 5, 8);
  thread t1(doeIets, 'A', 10, 10);
  thread t2(doeIets, 'B', 20, 10);
  thread t3(doeIets, 'C', 30, 10);

  t0.join();
  t1.join();
  t2.join();
  t3.join();

  tm1.Stop();
  cout << tm1.deTijd() << "  " << tm1.deNtijd() << endl;

  return 0;
}

void doeIets(char c, unsigned int tijd, unsigned int aantal)
{
  for (int i = 0; i < aantal; ++i)
  {
    cout << c << flush; // flush leeg output buffer (print direct)
    usleep(100000 * tijd);
  }
  cout << endl;
}
