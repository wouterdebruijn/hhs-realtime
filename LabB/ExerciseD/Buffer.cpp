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
    // Wacht tot er ruimte is in de buffer. Semaphoor is de grootte van de buffer, en wordt bij elke acquire 1 kleiner. Bij 0 wordt er gewacht.
    vol.acquire();

    cout << "In on i: " << in << " value: " << d << endl;

    opslag[in++]=d;
    in %=GROOTTE;
    m1.lock();
    teller++;
    m1.unlock();

    // Geef aan dat we niet meer leeg zijn
    leeg.release();
}

int Buffer::haalUitBuf() {
    int waarde;
    // Wacht tot we niet meer leeg zijn
    leeg.acquire();

    waarde=opslag[out++];
    cout << "Out on i: " << out << " value: " << waarde << endl;

    out %=GROOTTE;
    m1.lock();
    teller--;
    m1.unlock();

    // Geef aan dat we niet meer vol zijn
    vol.release();
    return waarde;
}

