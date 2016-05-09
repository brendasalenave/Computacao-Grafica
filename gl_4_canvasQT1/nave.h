// *********************************************************************
//  Autor: Brenda S. Santana
//         05/2016
// *
// *   bsantana@inf.ufsm.br
// *
// Objetivo da Classe: Implementar funções relacionas a forma e as operações realizadas
// sobre a nave.
//

#ifndef NAVE_H
#define NAVE_H

#include <vector>
#include "tiro.h"


class Nave{
    float x, y;
    float speed;
    float theta;

public:
    float vx[3], vy[3];
    float tempX[3], tempY[3];

public:
    Nave();

    std::vector<Tiro*> tiro;

    void rotacao(int cod, float ang);
    //void translacao(float px, float py);
    void deslocamento(int w, int h);
    int getX();
    void setX(int px);
    int getY();
    void setY(int py);
    float getSpeed();
    void setSpeed(float s, int cod);
    float getTheta();
    void setTheta(float ang);
    void setShape();

    void atira();
    void deslocaTiro();
};

#endif // NAVE_H
