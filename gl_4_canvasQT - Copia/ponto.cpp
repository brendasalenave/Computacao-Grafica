#include "ponto.h"

Ponto::Ponto(){
    z = 10.0;
}

void Ponto::setX(float u){
    x = u;
}

void Ponto::setY(float u){
    y = u;
}

void Ponto::setZ(float u){
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
