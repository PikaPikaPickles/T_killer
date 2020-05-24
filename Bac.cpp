//
// Created by yus on 24.05.2020.
//
#include <cmath>
#include "Bac.h"
#include <iostream>
   Bac::Bac(){
    dx=1;
    dy=1;
    name = "Bac";
    R=60;
    }

  void Bac:: search(YourKletka *u){
    if(1){
        std::cout<< "xuy";
        if(this->x - u->x > 0){

            dx+=0.2; std::cout<< "xuy2";
        }
        if(this->x - u->x > 0 ){
            dx-=0.2;
        }



    }


};
    void Bac:: update(double z, double zz){
        if(sqrt((this->x - z)*(this->x - z) + (this->y - zz)*(this->y - zz)) < 350) {

            if ((this->x) < z) {
                this->dx += 0.2;
            }
            if ((this->x > z)) {
                this->dx -= 0.2;
            }
            if ((this->y) < zz) {

                this->dy += 0.2;
            }
            if ((this->y > zz)) {
                this->dy -= 0.2;
            }
        }
        x+=dx + rand()%10;
        y+=dy + rand()%10;
        angle+=rand()%7;
        if(dx>1 )dx-=0.05;
        if(dx<1)dx+=0.05;
        if(dy>1)dy-=0.05;
        if(dy<1)dy+=0.05;
        if (x>W) x=0;  if (x<0) x=W;
        if (y>H) y=0;  if (y<0) y=H;
    }

