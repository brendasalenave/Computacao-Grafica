// *********************************************************************
//  Autor: Brenda S. Santana
//         05/2016
// *
// *   bsantana@inf.ufsm.br
// *
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#include "nave.h"
#include "tiro.h"

#include "transformacoes.h"

Nave::Nave(){
    x = 0;
    y = 0;
    theta = M_PI/2; /*Inicia em 90 graus */
    //theta = 0;
    speed = 1;
    vx[0] = 50;
    vx[1] = -50;
    vx[2] = 0;
    vy[0] = -25;
    vy[1] = -25;
    vy[2] = 25;

    //tiro = new Tiro();

}


void Nave::rotacao(int cod, float ang){
    Transformacoes* t = new Transformacoes();
    for(int i = 0; i < 3; i++){
        float temp = vx[i];
        vx[i] = t->rotacaoX(vx[i], vy[i], ang, cod);
        vy[i] = t->rotacaoY(temp, vy[i], ang, cod);
    }
    setShape();
}

/*void Nave::translacao(float px, float py){
    Transformacoes* t = new Transformacoes();
    for(int i = 0; i < 3; i++){
        vx[i] = t->translacaoX(vx[i]);
        vy[i] = t->translacaoY(vx[i]);
    }
}*/

void Nave::deslocamento(int w, int h){
    Transformacoes* t = new Transformacoes();
    x = t->deslocamentoX(x, theta, speed);
    y = t->deslocamentoY(y, theta, speed);
    if(y > h - 170)
      y = 0;
    else if(y < 0)
      y = h - 170;
    if(x > w-170)
      x = 0;
    else if(x < 0)
        x = w-170;

    setShape();
}

int Nave::getX(){
    return x;
}

void Nave::setX(int px){
    x = px;
}

int Nave::getY(){
    return y;
}

void Nave::setY(int py){
    y = py;
}

float Nave::getSpeed(){
    return speed;
}

void Nave::setSpeed(float s, int cod){
    if((speed < 6.0) && cod == 1)
        speed += s;
    else if((speed > 0) && cod == 2)
        speed -= s;
}

float Nave::getTheta(){
    return theta;
}

void Nave::setTheta(float ang){
    theta = ang;
}


void Nave::setShape(){
    for(int i = 0; i < 3; i++){
        tempX[i] = vx[i] + x;
        tempY[i] = vy[i] + y;
    }
}

void Nave::atira(){
    Tiro* s = new Tiro();
    tiro.push_back(s);
    s->setPos(x,y);
    s->setAlpha(theta);
    s->setSpeed(speed + 3.0);
}

void Nave::deslocaTiro(){
    Transformacoes* t = new Transformacoes();
    std::vector<Tiro*> tmp;
    tmp = tiro;
    std::vector<Tiro*>::iterator it;

    for(it = tmp.begin(); it != tmp.end(); it++){
        float ax = t->deslocamentoX((*it)->getX(),(*it)->getAlpha(),(*it)->getSpeed());
        float ay = t->deslocamentoY((*it)->getY(),(*it)->getAlpha(),(*it)->getSpeed());
        (*it)->setPos(ax,ay);
    }

}
