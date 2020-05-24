//
// Created by yus on 24.05.2020.
//
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Entity.h"
using namespace sf;


    Entity::Entity()
   {
     life=1;
   }

   void Entity::settings(Animation &a,int X,int Y)
   {
     anim = a;
     x=X; y=Y;
     angle = 0;
     R = 1;
   };

   void Entity::draw(RenderWindow &app)
   {
     anim.sprite.setPosition(x,y);
     anim.sprite.setRotation(angle+90);
     app.draw(anim.sprite);


   }

    Entity:: ~Entity(){};