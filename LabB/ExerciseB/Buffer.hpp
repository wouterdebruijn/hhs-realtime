//
//  Buffer.hpp
//  sensoren
//
//  Created by John Vi on 4/26/19.
//  Copyright © 2019 John Vi. All rights reserved.
//

#ifndef Buffer_hpp
#define Buffer_hpp

#include <stdio.h>
#include <mutex>
#include <semaphore>

using namespace std;

#define GROOTTE 3
class Buffer {
    
public:
    void zetInBuf(int);
    int haalUitBuf();
private:
    binary_semaphore vol{GROOTTE-1};
    binary_semaphore leeg{0};
    int in=0;
    int out=0;
    int teller=0;
    int opslag[GROOTTE];
    mutex m1;
    
};
#endif /* Buffer_hpp */
