#include "math.h"
#include "tiro.h"

Tiro::Tiro(){
    x = 0;
    y = 0;
    vel = 3.5;

}

void Tiro::setPos(float px, float py, float theta){
    x = px;
    y = py;
    alpha = theta;
}

int Tiro::getX(){
    return x;
}

int Tiro::getY(){
    return y;
}

void Tiro::setX(int px){
    x = px;
}

void Tiro::setY(int py){
    y = py;
}

float Tiro::getSpeed(){
    return vel;
}

void Tiro::setSpeed(float speed){
    vel = speed;
}

void Tiro::setAlpha(float theta){
    alpha = theta;
}

float Tiro::getAlpha(){
    return alpha;
}
