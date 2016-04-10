#ifndef __BOTAO_H__
#define __BOTAO_H__

#include <math.h>

#include "gl_canvas2d.h"

#define PI_2 6.2831853


class Botao{
  int posx, posy;
  int largura;
  int sinF;
  int drawF;
  int dctF;

public:
  Botao(){
     posy = 20;
     posx = 20;
     largura = 80;
     sinF = 0;  /* Flag para 'apagar' funcao seno */
     drawF = 0; /* Flag para 'apagar' desenho */
     dctF = 0;  /* Flag botao dct */
  }

  void desenha(){
    clear(255,255,255);
    criaBotao(posx, posy, " DCT");
    criaBotao(posx + 100, posy, "<    >");
    criaBotao(posx + 200, posy, " SENO");
    criaBotao(posx + 300, posy, "LIMPAR");
    criaBotao(posx + 400, posy, " DRAW");
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

        }else if((posx+100) <= x && (posx+largura+50) >= x){
            printf("\n*BOTAO 2 PRESSIONADO* ");

        }else if((posx+150) <= x && (posx+largura+150) >= x){
            printf("\n*BOTAO 3 PRESSIONADO* ");

        }else if((posx+200) <= x && (posx+largura+200) >= x){
            sinF = 1;
            printf("\n*BOTAO 4 PRESSIONADO* ");

        }else if((posx+300) <= x && (posx+largura+300) >= x){
            sinF = 0;
            drawF = 1;
            printf("\n*BOTAO 5 PRESSIONADO* ");

        }else if((posx+400) <= x && (posx+largura+400) >= x){
            drawF = 0;
            printf("\n*BOTAO 6 PRESSIONADO* ");
        }
    }
  }

  int getSinF(){
    return sinF;
  }

  int getDrawF(){
    return drawF;
  }

  void seno(){
    float x=0, y;
    color(1, 0, 0.55);
    for(float i=0; i < PI_2 ; i+= PI_2/128){
      y = sin(i)*150;
      glPointSize(3.0);
      point((int)x+24, y+300);
      glVertex2f((int)x+24, y+300);
      x+= 3.83;
    }
  }



};

#endif
