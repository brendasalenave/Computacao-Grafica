// *********************************************************************
//  Autor: Brenda S. Santana
//         05/2016
// *
// *   bsantana@inf.ufsm.br
// *
//

#include "math.h"
#include "tiro.h"

Tiro::Tiro(){

}

void Tiro::setPos(float px, float py){
    x = px;
    y = py;
}

float Tiro::getX(){
    return x;
}

float Tiro::getY(){
    return y;
}

float Tiro::getSpeed(){
    return vel;
}

void Tiro::setSpeed(float speed){
    vel = speed;
}

void Tiro::setAlpha(float theta){
    alpha = -theta;
}

float Tiro::getAlpha(){
    return alpha;
}
