#include "math.h"
#include "tiro.h"

Tiro::Tiro(){
    x = 100;
    y = 10;
    vel = 5.0;

}

void Tiro::setPos(int px, int py){
    x = cos(px);
    y = sin(py);
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
