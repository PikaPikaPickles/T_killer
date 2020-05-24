//
// Created by yus on 24.05.2020.
//

#ifndef T_KILLER_ENEMY_H
#define T_KILLER_ENEMY_H
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Entity.h"
#include <cmath>
using namespace sf;


class Enemy: public Entity {
public:
    Enemy();

    void update();
};


#endif //T_KILLER_ENEMY_H
