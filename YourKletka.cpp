//
// Created by yus on 24.05.2020.
//
#include <SFML/Graphics.hpp>
#include "YourKletka.h"
#include <time.h>
#include <list>
#include "Entity.h"
#include <cmath>
using namespace sf;

    YourKletka:: YourKletka(){
        name="YourKletka";
        R=100;
    }

    void  YourKletka::update(){
        if (thrust){
            dx+=cos(angle*DEGTORAD)*0.2;
            dy+=sin(angle*DEGTORAD)*0.2;
        }
        else{
            dx*=0.90;
            dy*=0.90;
        }

        int maxSpeed=15;
        float speed = sqrt(dx*dx+dy*dy);
        if (speed>maxSpeed){ dx *= maxSpeed/speed;
            dy *= maxSpeed/speed;
        }

        x+=dx;
        y+=dy;

        if (x>W) x=0;
        if (x<0) x=W;
        if (y>H) y=0;
        if (y<0) y=H;
    }



