#ifndef __BOTAO_H__
#define __BOTAO_H__

#include <math.h>

#include "gl_canvas2d.h"

#define PI_2 6.2831853

class Botao{
  int posx, posy;
  int largura;
  int flag;
  float r, g, b; //cor do botao

public:
  Botao(){
     posy = 20;
     posx = 20;
     largura = 80;
     flag = 0;
     r = 0;
     g = 0;
     b = 0;
  }

  void exibe(){
    clear(255,255,255);
    criaBotao(posx, posy, " DCT");
    criaBotao(posx + 100, posy, " IDCT");
    criaBotao(posx + 200, posy, " SENO");
    criaBotao(posx + 300, posy, "LIMPAR");
  }

  /*Cria botao com as dimensoes, texto e cores passados por parametro*/
  void criaBotao(int x, int y, const char* t){
    color(0, 0.6,0.9);
    rectFill(x, y, x+largura, y+largura/2 ); //coordenadas do retangulo x1, y1, x2, y2
    color(0,0,0);
    text(x+12,y+15,t);
  }

  void getMousePosition(int x, int y){
    if((posy <= y) && ((posy+largura/2) >= y)){
        if(posx <= x && (posx+largura) >= x){
            printf("\n*BOTAO 1 PRESSIONADO* ");
        }else if((posx+100) <= x && (posx+largura+100) >= x){
            printf("\n*BOTAO 2 PRESSIONADO* ");
        }else if((posx+200) <= x && (posx+largura+200) >= x){
            flag = 1;
            printf("\n*BOTAO 3 PRESSIONADO* ");
        }else if((posx+300) <= x && (posx+largura+300) >= x){
            flag = 0;
            printf("\n*BOTAO 4 PRESSIONADO* ");
        }
    }
  }

    int getFlag(){
       return flag;
    }

    void setFlag(){
        flag = 0;
    }

    void seno(){
        float x=0, y;
        color(1, 0, 0.55);
        for(float i=0; i < PI_2; i+= PI_2/128){
          y = sin(i)*128;
          point((int)x+24, y+350);
          x+=3.85;
       }
    }



};

#endif
