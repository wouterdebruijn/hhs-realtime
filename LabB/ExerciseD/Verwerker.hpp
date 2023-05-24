//
//  verwerker.hpp
//  sensoren
//
//  Created by John Vi on 4/26/19.
//  Copyright © 2019 John Vi. All rights reserved.
//

#ifndef Verwerker_hpp
#define Verwerker_hpp

#include <stdio.h>
#include <vector>
#include <random>
#include <mutex>
#include <atomic>

using namespace std;

class Buffer;
class Verwerker {
public:
    Verwerker(Buffer*,int);
    void verwerkData();
    void zetUit();
    int hetResultaat()const;
    void aantalTeLezenData(int);
    vector<int> deTussenstanden() const;
private:
    static vector<int> tussenstanden;
    static mutex tussenstanden_mutex;
    static atomic<int> result;
    int hoeveel;
    Buffer *buf;
    bool status;
};
#endif /* verwerker_hpp */
