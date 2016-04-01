#ifndef __ASTEROIDE_H__
#define __ASTEROIDE_H__
#include "Bullet.h"
#include "Draw.h"

class Ship{
public:
    int x, y, bullets;
    int **shape;
    Draw *d = new Draw();
    typedef struct fbs{
        struct fbs *prox;
        Bullet *b;
    }fbs;
    fbs *f;


    Ship();
    int **getShape();
    void setShape();
    void setPosition(int i, int j);
    int getX();
    int getY();

    void iniciaShoots();
    void shoot();
    void removeShoot();
    void imprimeShoots();
    void liberaShoots();
    void renderShoots();
    void updateBulletsPosition();
};

#endif // __ASTEROIDE_H__
