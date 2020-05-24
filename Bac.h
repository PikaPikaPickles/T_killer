//
// Created by yus on 24.05.2020.
//

#ifndef T_KILLER_BAC_H
#define T_KILLER_BAC_H

#include "Enemy.h"
#include "YourKletka.h"
#include <cmath>

class Bac: public Enemy{
public:
    Bac();


    void update(double z, double zz);
    void search(YourKletka *u);


};


#endif //T_KILLER_BAC_H
