//
// Created by yus on 24.05.2020.
//

#include "AntyBody.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Entity.h"
#include <cmath>
    AntyBody:: AntyBody()
    {
        name="AntyBody";
    }

    void AntyBody:: update()
    {
        dx=0;
        dy=0;
        // angle+=rand()%7-3;  /*try this*/
        x+=dx;
        y+=dy;

        if (x>W || x<0 || y>H || y<0) life=0;
    }