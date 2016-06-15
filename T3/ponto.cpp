// *********************************************************************
//  Autora: Brenda S. Santana
//         06/2016
// *
// *   bsantana@inf.ufsm.br
// *
//

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
    return this->y;
}

float Ponto::getZ(){
    return this->z;
}
