#include <iostream>
#include <unistd.h>
#include <iostream>
#include "Timer.h"

using namespace std;

void doeIets(char c, unsigned int tijd, unsigned int aantal);

int main()
{
  Timer tm1;
  tm1.Reset();
  pid_t pid;

  // Create three child processes with one parent process
  for (int i = 0; i < 3; i++)
  {
    pid = fork();
    if (pid == 0)
    {
      // Child process
      switch (i)
      {
      case 0:
        doeIets('A', 10, 10);
        break;
      case 1:
        doeIets('B', 20, 10);
        break;
      case 2:
        doeIets('C', 30, 10);
        break;
      }
      return 0;
    }
  }

  // Parent process
  doeIets('p',5,8);

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
