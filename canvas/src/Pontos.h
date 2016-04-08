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

    void desenha(int x, int y){
        color(r, g, b);
        glPointSize(3.0);
        point(x, y);
       /*color(0,1,0.9);
      point(vety[u],350);*/
    }
};



#endif

