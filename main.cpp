#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "YourKletka.h"
#include "Animation.h"
#include "AntyBody.h"
#include "Enemy.h"
#include <time.h>
#include <list>
#include <cmath>
#include "Virus.h"
bool isCollide(Entity *a,Entity *b)
{
    return (b->x - a->x)*(b->x - a->x)+ (b->y - a->y)*(b->y - a->y)< (a->R + b->R)*(a->R + b->R);
}
int main() {
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "Enemys!");
    app.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5, t6, t7;
    t2.loadFromFile("/home/yus/CLionProjects/asteros/images/background.jpg");
    t3.loadFromFile("/home/yus/CLionProjects/asteros/images/explosions/type_C.png");
    t7.loadFromFile("/home/yus/CLionProjects/asteros/images/explosions/type_B.png");

    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite background(t2);

    Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
    Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);


    std::list<Entity *> entities;

    for (int i = 0; i < 15; i++) {
        Virus *a = new Virus();
        a->settings(sRock, rand() % W, rand() % H);
        entities.push_back(a);
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
                    b->settings(sAntyBody, p->x, p->y);
                    entities.push_back(b);
                }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) p->angle += 3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) p->angle -= 3;
        if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust = true;
        else p->thrust = false;


        for (auto a:entities)
            for (auto b:entities) {
                if (a->name == "Enemy" && b->name == "AntyBody")
                    if (isCollide(a, b)) {
                        a->life = false;
                        b->life = false;

                        Entity *e = new Entity();
                        e->settings(sExplosion, a->x, a->y);
                        e->name = "explosion";
                        entities.push_back(e);


                        for (int i = 0; i < 2; i++) {
                            if (a->R == 15) continue;
                            Entity *e = new Enemy();
                            e->settings(sRock_small, a->x, a->y);
                            entities.push_back(e);
                        }

                    }

                if (a->name == "YourKletka" && b->name == "Enemy")
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

        if (rand() % 150 == 0) {
            Enemy *a = new Enemy();
            a->settings(sRock, 0, rand() % H);
            entities.push_back(a);
        }

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
        app.display();
    }

    return 0;
}