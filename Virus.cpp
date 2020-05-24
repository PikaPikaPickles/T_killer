//
// Created by yus on 24.05.2020.
//

#include "Virus.h"
    Virus:: Virus(){

        t.loadFromFile("/home/yus/CLionProjects/asteros/images/virus.png");
        Animation An(t, 0, 0,27 , 27, 16, 0);
        dx=rand()%8-4;
        dy=rand()%8-4;
        name="asteroid";
    }
