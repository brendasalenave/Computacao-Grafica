/*********************************************************************
// Computacao Grafica - Trabalho 1.
//  Autor: Brenda Salenave Santana
//         2016/1
//  E-mail: bsantana@inf.ufsm.br
//
//  Classe Botao: Classe utilizada para implementar metodos relacionadas
//  aos botoes e seus eventos.
// *********************************************************************/

#ifndef __BOTAO_H__
#define __BOTAO_H__

#include <math.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

#define PI_2 6.2831853


class Botao{
  int posx, posy;
  int largura;
  int sinF;
  int drawF;
  int dctF;
  int quantF;
  int r;
  public:
      int t;

public:
  Botao(){
     posy = 20;
     posx = 20;
     largura = 80;
     t = 2;
     sinF = 0;  /* Flag para 'apagar' funcao seno */
     drawF = 0; /* Flag para 'apagar' desenho */
     dctF = 0;  /* Flag botao dct */
     quantF = 0;
     r = 0;
  }

  /* Metodo utilizado para desenho dos botoes criados*/
  void desenha(){
    clear(255,255,255);
    //criaBotao(posx, posy, " DCT");
    criaBotao(posx, posy, "--  ++");
    criaBotao(posx + 100, posy, " SENO");
    criaBotao(posx + 200, posy, "LIMPAR");
    criaBotao(posx + 300, posy, " DRAW");
    criaBotao(posx + 400, posy, "QUANTI"); //Quantizacao
  }

  /*Cria botao nas coordenadas passadas por parametro*/
  void criaBotao(int x, int y, const char* t){
    color(0, 0.6,0.9);
    rectFill(x, y, x+largura, y+60/2 ); //coordenadas do retangulo x1, y1, x2, y2
    color(0,0,0);
    text(x+12,y+12,t);
  }

  /*Verifica se o mouse foi pressionado dentro da area de um botao */
  void getMousePosition(int x, int y){
    int key = 0;

    if((posy <= y) && ((posy+60/2) >= y)){
        if(posx <= x && (posx+40) >= x){
            key = 1;

        }else if((posx+40) <= x && (posx+80) >= x){
            key = 2;

        }else if((posx+100) <= x && (posx+largura+100) >= x){
            key = 3;

        }else if((posx+200) <= x && (posx+largura+200) >= x){
            key = 4;

        }else if((posx+300) <= x && (posx+largura+300) >= x){
            key = 5;
        }else if((posx+400) <= x && (posx+largura+400) >= x){
            key = 6;
        }
    }else if(x > r+28 && x < r+48 && y > 188 && y < 208){
        key = 7;
    }
    eventoBotao(key);

  }

  int getSinF(){
    return sinF;
  }

  int getDrawF(){
    return drawF;
  }

  int getDctF(){
    return dctF;
  }

  int getQuantF(){
    return quantF;
  }

  void setRazao(int razao){
    r = razao;
  }

  /* vetor de quantizacao */
  void quantizacao(double vet[128], int t){
      double *v = (double*)malloc(128 * sizeof(double));
      if (t== 0) t=2;
      for(int u = 0; u < 128; u++)
        v[u] = (t*1.9999);

      for(int u = 0; u < 128; u++)
        vet[u] /= v[u];
  }

  /* Metodo utilizado para gerar 1 período da funcao seno */
  void seno(){
    float x=0, y;
    color(1, 0, 0.55);

    glBegin(GL_LINE_STRIP);
    for(float i=0; i < PI_2 ; i+= PI_2/128){
      y = sin(i)*95;
      //glPointSize(3.0);
      //point((int)x+24, y+300);
      glVertex2i((int)x+24, y+481);
      x+= 3.99999;
    }
    glEnd();
    line(531,475,535,480);
  }

  /*Metodo utilizado para verificar e chamar o evento relacionado a cada botao */
  void eventoBotao(int c){
    switch(c){
        case 1:
            printf("\n*BOTAO 1 PRESSIONADO* ");
            if(t > 0) t-=2;
            break;
        case 2:
            printf("\n*BOTAO 2 PRESSIONADO* ");
            if(t < 100) t+=2;
            break;
        case 3:
            sinF = 1;
            dctF = 1;
            drawF = 1;
            printf("\n*BOTAO 3 PRESSIONADO* ");
            break;
        case 4:
           sinF = 0;
           drawF = 1;
           printf("\n*BOTAO 4 PRESSIONADO* ");
           break;
        case 5:
           if(drawF == 1)
               drawF = 0;
           else
               printf("\n'DRAW: ja esta ativo");
           printf("\n*BOTAO 5 PRESSIONADO* ");
           break;
        case 6:
            quantF = 1;
            printf("BOTAO 'QUANTIZACAO' PRESSIONADO");
            break;
        case 7:
           printf("\n*BOTAO DCT PRESSIONADO* ");
           if(dctF == 0)
             dctF = 1;
           else
            dctF = 0;
           break;

    }

  }


};

#endif
