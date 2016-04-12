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

    void desenha(int x, char y, int x2, char y2, int cod){
        if(cod == 0)
            color(r, g, b);

        glPointSize(3.0);
        line(x, y+255, x2, y2+255);
        //marca de azul o ponto x armazenado
        color(0,0.5,1);
        point(x,300);

    }

};

#endif

