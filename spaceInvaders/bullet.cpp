#include <stdio.h>
#include "Bullet.h"

void Bullet::setPosition(int i, int j){
    this->x = i;
    this->y = j;
}

int Bullet::getX(){
    return x;
}

int Bullet::getY(){
    return y;
}

void Bullet::setX(int i){
    this->x = i;
}

void Bullet::setY(int j){
    this->y = j;
}
