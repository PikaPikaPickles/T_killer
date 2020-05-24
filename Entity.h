//
// Created by yus on 24.05.2020.
//

#ifndef T_KILLER_ENTITY_H
#define T_KILLER_ENTITY_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Animation.h"

using namespace sf;

class Entity: public Animation{
public:
    Texture t;
    float x,y,dx,dy,R=1,angle=0;
    bool life;
    std::string name;
    Animation anim;
    Entity();
    void settings(Animation &a,int X,int Y,float Angle=0,int radius=1);
    virtual void update(){};

    void draw(RenderWindow &app);

    virtual ~Entity();

};


#endif //T_KILLER_ENTITY_H
