/*********************************************************************
// Computacao Grafica - Trabalho 1.
//  Autor: Brenda Salenave Santana
//         2016/1
//  E-mail: bsantana@inf.ufsm.br
//
//  Classe Pontos: Classe utilizada para implementar o metodo que desenha os
//  pontos desenhados.
// *********************************************************************/

#ifndef __PONTOS_H__
#define __PONTOS_H__

#include "gl_canvas2d.h"

class Pontos{
  int x, y;
  float r, g, b; //cor do ponto
public:
    Pontos(int x, int y, int r, int g, int b){
        this->x = x;
        this->y = y;
        this->r = r;
        this->g = b;
        this->b = b;
    }

    /* Metodo utilizado para desenho do sinal entrado pelo usuario */
    void desenha(int x, char y, int x2, char y2, int cod, int cod2){
        if(cod == 0)
            color(r, g, b);

        glPointSize(3.0);
        if(cod2 == 0)
            line(x, y+510, x2, y2+510);
        else
            line(x, y+230, x2, y2+230);
        //marca de azul o ponto x armazenado
        color(0,0.5,1);
        point(x,481);

    }


};

#endif
