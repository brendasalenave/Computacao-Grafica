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

    void desenha(int x, int y, int x2, int y2, int cod){
        if(cod == 0)
            color(r, g, b);

        glPointSize(3.0);
        line(x, y, x2, y2);
        color(0,0.5,1);
        //marca de azul o ponto x armazenado
        point(x,300);

        //x = ceilf((float)x/(488/128.0f));
        //y = ceilf((float)y/(400/128.0f));
        /*for(int i = 24; i < 536; i+= 4){
          if(x == i){
            point(x+4, y);
                break;
          }
        }*/

    }

};

#endif

