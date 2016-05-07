#include "nave.h"
#include "transformacoes.h"

Nave::Nave(){
    x = 0;
    y = 0;
    theta = 0;
    /*vx[0] = 50;
    vx[1] = -50;
    vx[2] = 0;
    vy[0] = -25;
    vy[1] = -25;
    vy[2] = 25;*/

}

void Nave::rotacao(float ang){
    Transformacoes* t = new Transformacoes();
    for(int i = 0; i < 3; i++){
        vx[i] = t->rotacaoX(vx[i], vy[i], ang);
        vy[i] = t->rotacaoY(vx[i], vy[i], ang);
    }
}

int Nave::getX(){
    return x;
}

void Nave::setX(int px){
    x = px;
}

int Nave::getY(){
    return y    ;
}

void Nave::setY(int py){
    y = py;
}

float Nave::getTheta(){
    return theta;
}

void Nave::setTheta(float ang){
    theta = ang;
}

void Nave::setShape(int px, int py){
    vx[0] = px + 50;
    vx[1] = px - 50;
    vx[2] = px;
    vy[0] = py - 25;
    vy[1] = py - 25;
    vy[2] = py + 25;

}

/*void Nave::desenha(float vecX[3], float vecY[3]){
    //Desenho* d = new Desenho();
    //d->nave(vecX,vecY);
}*/
