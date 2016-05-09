// *********************************************************************
//  Autor: Brenda S. Santana
//         05/2016
// *
// *   bsantana@inf.ufsm.br
// *
//
// Objetivo da Classe: Implementar funções relacionadas aos disparos de projéteis da nave
//

#ifndef TIRO_H
#define TIRO_H


class Tiro{
    float x, y;
    float alpha;
    float vel;


public:
    Tiro();

    void setPos(float px, float py);
    float getX();
    float getY();
    float getSpeed();
    void setSpeed(float speed);
    void setAlpha(float theta);
    float getAlpha();
};

#endif // TIRO_H
