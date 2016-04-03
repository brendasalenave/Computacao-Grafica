#ifndef __BOTAO_H__
#define __BOTAO_H__

#include "gl_canvas2d.h"

class Botao{
  int posx, posy;
  float r, g, b; //cor do botao

public:
  Botao(){
     posy = 20;
     posx = 20;
     r = 0;
     g = 0;
     b = 0;
  }

  void anima(){
      clear(255,255,255);
      criaBotao(posx, posy, "T", 0.5, 0.03, 0.8);
      criaBotao(posx + 40, posy, "<", 0.94, 0.05, 0.01);
      criaBotao(posx + 80, posy, ">", 0.94, 0.05, 0.01);

  }

  /*Cria botao com as dimensoes, texto e cores passados por parametro*/
  void criaBotao(int x, int y, const char* t, float r, float g, float b){
    color(r, g, b);
    rectFill(x, y, x+35, y+35 ); //coordenadas do retangulo x1, y1, x2, y2
    color(0,0,0);
    text(x+14,y+14,t);
  }

  int getMousePosition(int x, int y){
    if(posx <= x && (posx+35) >= x && posy <= y && (posy+35) >= y){
        color(1,0,0);
        printf("FUNCIONOU");
        return 1;
    }
    return 0;
  }

};

#endif
