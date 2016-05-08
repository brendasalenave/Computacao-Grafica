#include <stdio.h>

#include "nave.h"
#include "transformacoes.h"

Nave::Nave(){
    x = 0;
    y = 0;
    theta = 1.5708;
    vel = 0.8;
    vx[0] = 50;
    vx[1] = -50;
    vx[2] = 0;
    vy[0] = -25;
    vy[1] = -25;
    vy[2] = 25;

}

void Nave::rotacao(int cod, float ang){
    Transformacoes* t = new Transformacoes();
    for(int i = 0; i < 3; i++){
        float temp = vx[i];
        vx[i] = t->rotacaoX(vx[i], vy[i], ang, cod);
        vy[i] = t->rotacaoY(temp, vy[i], ang, cod);
    }
}

void Nave::translacao(float px, float py){
    Transformacoes* t = new Transformacoes();
    for(int i = 0; i < 3; i++){
        vx[i] = t->translacaoX(vx[i]);
        vy[i] = t->translacaoY(vx[i]);
    }
}

void Nave::deslocamento(){
    Transformacoes* t = new Transformacoes();
    for(int i = 0; i < 3; i++){
        float temp = vx[i];
        vx[i] = t->deslocamentoX(vx[i], theta, vel);
        vy[i] = t->deslocamentoY(vy[i], theta ,vel);
    }

    //rotacao(cod,theta);
    //setShape(x, y);
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

float Nave::getSpeed(){
    return vel;
}

void Nave::setSpeed(float s, int cod){
    if((vel < 1.5) && cod == 1)
        vel += s;
    else if((vel > 0) && cod == 2)
        vel -= s;
}

float Nave::getTheta(){
    return theta;
}

void Nave::setTheta(float ang){
    theta = ang;
}


void Nave::setShape(int px, int py){
    vx[0] = px + 50 + theta;
    vx[1] = px - 50 + theta;
    vx[2] = px + theta;
    vy[0] = py - 25+ theta;
    vy[1] = py - 25 + theta;
    vy[2] = py + 25 + theta;

}

