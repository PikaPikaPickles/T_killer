//
// Created by yus on 24.05.2020.
//
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Entity.h"
#include <cmath>
using namespace sf;
#include "Enemy.h"

     Enemy::Enemy(){
        dx=rand()%8-4;
        dy=rand()%8-4;
        name="asteroid";
    }

    void Enemy::update()
    {
        x+=dx;
        y+=dy;

        if (x>W) x=0;  if (x<0) x=W;
        if (y>H) y=0;  if (y<0) y=H;
    }

