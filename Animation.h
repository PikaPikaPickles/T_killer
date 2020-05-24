//
// Created by yus on 24.05.2020.
//

#ifndef T_KILLER_ANIMATION_H
#define T_KILLER_ANIMATION_H
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
using namespace sf;
const int W = 1300;
const int H = 900;

class Animation {
public:
    float DEGTORAD = 0.017453f;
    float Frame, speed;
    Sprite sprite;
    std::vector<IntRect> frames;

    Animation();

    Animation (Texture &t, int x, int y, int w, int h, int count, float Speed);

   void update();

   bool isEnd();
};


#endif //T_KILLER_ANIMATION_H
