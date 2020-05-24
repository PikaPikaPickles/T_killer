#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "YourKletka.h"
#include "Animation.h"
#include "AntyBody.h"
#include "Enemy.h"
#include "Virus.h"
#include <time.h>
#include <list>
#include <cmath>
#include <SFML/Audio.hpp>
#include "Bac.h"

bool isCollide(Entity *a,Entity *b)
{
    return (b->x - a->x)*(b->x - a->x)+
           (b->y - a->y)*(b->y - a->y)<
           (a->R + b->R)*(a->R + b->R);
}
int main() {
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "Enemys!");
    app.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5, t6, t7,t8;
    t1.loadFromFile("/home/yus/CLionProjects/asteros/images/klet.png");
    t2.loadFromFile("/home/yus/CLionProjects/asteros/images/fon.png");
    t3.loadFromFile("/home/yus/CLionProjects/asteros/images/explosions/type_C.png");
    t4.loadFromFile("/home/yus/CLionProjects/asteros/images/virus.png");
    t5.loadFromFile("/home/yus/CLionProjects/asteros/images/fire_blue.png");
    t6.loadFromFile("/home/yus/CLionProjects/asteros/images/rock_small.png");
    t7.loadFromFile("/home/yus/CLionProjects/asteros/images/explosions/type_B.png");
    t8.loadFromFile("/home/yus/CLionProjects/asteros/images/bac.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite background(t2);
    Music music;
    music.openFromFile("/home/yus/CLionProjects/asteros/images/Tquila.ogg");
    music.play();
    Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
    Animation sRock(t4, 0, 0,27 , 27, 16, 0);
    Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
    Animation sAntyBody(t5, 0, 0, 32, 64, 16, 0.8);
    Animation sYourKletka(t1, 0, 0, 120, 145, 1, 0);
    Animation sYourKletka_go(t1, 0, 0, 120, 145, 1, 0);
    Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);
    Animation sBac(t8, 0, 0, 89, 126, 64, 0.0);

    std::list<Entity *> entities;
    std::list<Bac*> bbb;

    for (int i = 0; i < 15; i++) {
        Virus *a = new Virus();
        a->settings(sRock, rand() % W, rand() % H);
        entities.push_back(a);


    }
    for (int i = 0; i < 5; i++) {
        Bac *b = new Bac();
        b->settings(sBac, rand() % W, rand() % H);
        bbb.push_back(b);
    }

    YourKletka *p = new YourKletka();
    p->settings(sYourKletka, 200, 200);
    entities.push_back(p);

    /////main loop/////
    while (app.isOpen()) {
        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
                if (event.key.code == Keyboard::Space) {
                    AntyBody *b = new AntyBody();
                    b->settings(sAntyBody, p->x, p->y,p->angle, 10);
                    entities.push_back(b);
                }
        }
        for (auto b:bbb) {
            b->update(p->x,p->y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) p->angle += 3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) p->angle -= 3;
        if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust = true;
        else p->thrust = false;


        for (auto a:entities)
            for (auto b:entities) {
                if (a->name == "Virus" && b->name == "AntyBody")
                    if (isCollide(a, b)) {
                        a->life = false;
                        b->life = false;

                        Entity *e = new Entity();
                        e->settings(sExplosion, a->x, a->y);
                        e->name = "explosion";
                        entities.push_back(e);


                        for (int i = 0; i < 2; i++) {
                            if (a->R == 15) continue;
                            Entity *e = new Virus();
                        }

                    }

                if (a->name == "YourKletka" && b->name == "Virus")
                    if (isCollide(a, b)) {
                        b->life = false;

                        Entity *e = new Entity();
                        e->settings(sExplosion_ship, a->x, a->y);
                        e->name = "explosion";
                        entities.push_back(e);

                        p->settings(sYourKletka, W / 2, H / 2);
                        p->dx = 0;
                        p->dy = 0;
                    }
            }


        if (p->thrust) p->anim = sYourKletka_go;
        else p->anim = sYourKletka;


         for (auto e:entities)
            if (e->name == "explosion")
                if (e->anim.isEnd()) e->life = 0;

        for (auto i = entities.begin(); i != entities.end();) {
            Entity *e = *i;
            e->update();
            e->anim.update();
            if (e->life == false) {
                i = entities.erase(i);
                delete e;
            }
            else i++;
        }

        //////draw//////
        app.draw(background);
        for (auto i:entities) i->draw(app);
        for (auto i:bbb) i->draw(app);
        app.display();
    }

    return 0;
}