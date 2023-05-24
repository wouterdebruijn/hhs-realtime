//
//  main.cpp
//  sensoren
//
//  Created by John Vi on 4/26/19.
//  Copyright © 2019 John Vi. All rights reserved.
//

#include "Buffer.hpp"
#include "Sensor.hpp"
#include "Verwerker.hpp"
#include <iostream>
#include <thread>

using namespace std;

int main(int argc, const char * argv[]) {

    Buffer opslag;
    Sensor s1(1,10,100,&opslag); //te genereren data tssen de 1 en de 9 aantal 10
    Sensor s2(11,20,100,&opslag);
    Sensor s3(21,30,100,&opslag);
    Verwerker vw1(&opslag,100);
    Verwerker vw2(&opslag,200);
    cout<<"start" <<endl;
    for(int n=0;n<5;n++) {
      thread t1(&Sensor::genereerdData,&s1);
      thread t2(&Verwerker::verwerkData,&vw1);

      thread t3(&Sensor::genereerdData,&s2);
      thread t4(&Verwerker::verwerkData,&vw2);
      thread t5(&Sensor::genereerdData,&s3);

      t1.join();
      t2.join();
      t3.join();
      t4.join();
      t5.join();
    }
    cout << "Hello, IoT "<<vw1.hetResultaat()<<endl;
    vector<int> ts=vw1.deTussenstanden();

    for(auto i:ts) {
        cout<<i <<" ";
    }
    cout<<endl;

    return 0;
}
