#include "Verwerker.hpp"
#include "Buffer.hpp"
#include <iostream>
using namespace std;

vector<int> Verwerker::tussenstanden = vector<int>();
mutex Verwerker::tussenstanden_mutex = mutex();
atomic<int> Verwerker::result = 0;

Verwerker::Verwerker(Buffer* b,int h): buf(b), status(true),hoeveel(h) {
}

void Verwerker::zetUit() {
    status=false;
}

int Verwerker::hetResultaat()const {
    return result;
}
void Verwerker::aantalTeLezenData(int d) {
    hoeveel=d;
}
vector<int> Verwerker::deTussenstanden() const {
    return tussenstanden;
}
void Verwerker::verwerkData() {
    status=true;
    int h=hoeveel;
    while(h-- && status) {
      int temp;
      unsigned int rd=(rand() % 2000) + 1;
      std::this_thread::sleep_for(std::chrono::nanoseconds(rd));
      temp=buf->haalUitBuf();
      result += temp;
    }
    tussenstanden_mutex.lock();
    tussenstanden.push_back(result);
    tussenstanden_mutex.unlock();
}
