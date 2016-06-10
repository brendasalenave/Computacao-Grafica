#include "ponto.h"

Ponto::Ponto(){
    z = 10.0;
}

void Ponto::setX(int u){
    x = u;
}

void Ponto::setY(int u){
    y = u;
}

void Ponto::setZ(int u){
    z = u;
}

float Ponto::getX(){
    return x;
}

float Ponto::getY(){
    return y;
}

float Ponto::getZ(){
    return z;
}
