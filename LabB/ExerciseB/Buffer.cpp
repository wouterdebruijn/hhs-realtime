//
//  Buffer.cpp
//  sensoren
//
//  Created by John Vi on 4/26/19.
//  Copyright © 2019 John Vi. All rights reserved.
//

#include "Buffer.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;
void Buffer::zetInBuf(int d) {
    vol.acquire();

    opslag[in++]=d;
    in %=GROOTTE;
    m1.lock();
    teller++;
    cout<<"teller in  "<<teller<<endl;
    m1.unlock();

    leeg.release();
}

int Buffer::haalUitBuf() {
    int waarde;
    leeg.acquire();
    
    waarde=opslag[out++];
    out %=GROOTTE;
    m1.lock();
    teller--;
    cout<<"teller out "<<teller<<endl;
    m1.unlock();

    vol.release();
    return waarde;
}

