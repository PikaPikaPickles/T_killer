//
// Created by yus on 24.05.2020.
//
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Animation.h"
using namespace sf;


   Animation:: Animation(){};

   Animation:: Animation (Texture &t, int x, int y, int w, int h, int count, float Speed)
   {
       this->Frame = 0;
       this->speed = Speed;

     for (int i=0;i<count;i++)
      frames.push_back( IntRect(x+i*w, y, w, h)  );

     sprite.setTexture(t);
     sprite.setOrigin(w/2,h/2);
     sprite.setTextureRect(frames[0]);
   }



   void Animation:: update()
   {
     Frame += speed;
     int n = frames.size();
     if (Frame >= n) Frame -= n;
     if (n>0) sprite.setTextureRect( frames[int(Frame)] );
   }

   bool Animation:: isEnd()
   {
     return Frame+speed>=frames.size();
   }