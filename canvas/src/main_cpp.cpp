/*********************************************************************
// Computacao Grafica - Trabalho 1.
//  Autor: Brenda Salenave Santana
//         2016/1
//  E-mail: bsantana@inf.ufsm.br
//
//  Programa desenvolvido para a disciplina de Computacao Grafica, afim de demonstrar
//  connhecimentos obtidos.
//  Este programa captura um desenho feito com o mouse, e apos aplica a dct e idct sobre seus pontos.
//  Tambem e ofericida a funcao que exibe um periodo da funcao seno.
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "gl_canvas2d.h"

#include "Botao.h"
#include "Pontos.h"
#include "DCT.h"


std:: vector <char> vety;
std:: vector <int> vetx;
//int array_x[128];
//char array_y[128];

//variaveis globais
int   opcao  = 50;
int xv = 0;
int px, py;
int height = 0;
int width = 0;
int razaoL, razaoH;

int insercao = 0;

int pressionado = 0;

Botao  * b = new Botao();
Pontos * p = new Pontos(px, py, 1, 0, 0);
DCT    * d = new DCT();

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render();
//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key);
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key);
//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y);

int main(int argc, char const *argv[]) {
    height = 630;
    width = 800;
    initCanvas(width,height);

   runCanvas();
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render(){
    int tamL = glutGet(GLUT_WINDOW_WIDTH);
    int tamH = glutGet(GLUT_WINDOW_HEIGHT);

    razaoL = (int)ceil((tamL * 512)/800);
    b->setRazao(razaoL);
    d->setRazao(razaoL);
    razaoH = (tamH * 193)/630;
    //printf("RAZAO L : %d", razaoL);

   color(0, 0, 0);
   rectFill(0 , 0, tamL, 60);
   glLineWidth(2.0);
   rect(24, 578, razaoL + 24, 385);
   line(24,481,razaoL + 24,481); /* (0,0)*/
   rect(24, 70 ,razaoL + 24, 325);
   //line(24,198,536,198); /* (0,0)*/


    rect(razaoL + 28, 188, razaoL+48 ,208); //caixinha
    if(b->getDctF() == 0){
      color(0.156,0.192,0.592);
      glLineWidth(3.0);
      line(razaoL + 28,198 ,razaoL + 38, 188);
      line(razaoL + 38,188 , razaoL + 58, 215);
      glLineWidth(2.0);
    }

    color(0,0,0);
    rect(razaoL + 88,70, razaoL + 232, 90);
    text(razaoL + 91,76,"Threshold: ");

    text(24, 455, "(0,0)");
    text(124, 603, "Area para desenho do Grafico");
    text(124, 328, "Sinal Reconstruido");


    b->desenha();
    line(60, 20, 60, 60);
    if(b->getSinF() == 1){
        b->seno();
    }


    if(b->getDrawF() == 0){
        for(int u = 1; u < vety.size(); u++){
        p->desenha(vetx[u-1], vety[u-1], vetx[u], vety[u],0,0);
    }
        if(b->getDctF() == 0){
            double* m1 = (double*)malloc(128*sizeof(double));
            m1 = d->fdct(vety);
            d->setThreshold(b->t);
            if(b->getQuantF() == 1)
                b->quantizacao(m1,d->getThreshold());
            d->threshold(m1);
            int * m = (int*)malloc(128 * sizeof(int));
            m = d->idct(m1);
            for(int u = 1; u < vety.size(); u++){
                color(1,0.5,0);
                int y  = (int)m[u-1] - 48; // converte para inteiro
                int y1 = (int)m[u] - 48;  // converte para inteiro
                p->desenha(vetx[u-1], y, vetx[u], y1,1,1);
            }
        }
    }
    color(0, 0, 0);
}
//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key){
   printf("\nTecla: %d" , key);
   if( key < 200 ){
      opcao = key;
   }

   switch(key){
      case 27:
	     exit(0);
	  break;
   }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key){
   printf("\nLiberou: %d" , key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y){
    y = height - y;

    if((state == 0) && (button == 0)){
        pressionado = 1;
        b->getMousePosition(x,y);
    }

    if((state == 1) && (button == 0))
        pressionado = 0;

    if(pressionado == 1){
      if(x > 24 && x < razaoL+24 && y > 385 && y <578 && x > xv){
          printf("  vety size: %d", vety.size());
          if(insercao < 128){
            for(int i = 24; i < razaoL+24; i+= ((razaoL+24)/128)){
                if(x==i){
                  vetx.push_back(x);
                  vety.push_back(y);
                  xv = x;
                  insercao++;
                }
            }

          }
      }
    }
}
