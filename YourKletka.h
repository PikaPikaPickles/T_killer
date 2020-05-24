//
// Created by yus on 24.05.2020.
//

#ifndef T_KILLER_YOURKLETKA_H
#define T_KILLER_YOURKLETKA_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Entity.h"
using namespace sf;
class YourKletka: public Entity {
public:
    bool thrust;

    YourKletka();

    void update();
};

#endif //T_KILLER_YOURKLETKA_H
