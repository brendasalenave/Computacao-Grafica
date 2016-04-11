/*********************************************************************
// Computacao Grafica - Trabalho 1.
//  Autor: Cesar Tadeu Pozzer
//         04/2016
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
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
    height = 600;
    width = 800;
    initCanvas(width,height);

   runCanvas();
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render(){
    color(0, 0, 0);
   rectFill(0, 0, 1200, 80);
   glLineWidth(2.0);
   rect(24, 150, 536, 450);
   line(24,300,536,300);
   rect(24,85, 168, 110);
   text(26,93,"Threshold: ");

   text(24, 302, "(0,0)");
   text(124, 455, "Area para desenho do Grafico");

   b->desenha();
   line(160, 20, 160, 60);
   if(b->getSinF() == 1){
      b->seno();
   }

   if(b->getDrawF() == 0){
       /*for(int u = 1; u < vety.size(); u++){
          //if(vety[u-1] != 0){
            int y = (int)vety[u-1] - 48; /* converte para inteiro
            int y1 = (int)vety[u] - 48;  /* converte para inteiro
            p->desenha(vetx[u-1], y, vetx[u], y1,0);
       }*/
        double* m1 = (double*)malloc(128*sizeof(double));
        m1 = d->fdct(vety);
        d->setThreshold(2);
        d->threshold(m1);
        int *m = (int*)malloc(128 * sizeof(int));
        m = d->idct(m1);
        for(int u = 1; u < vety.size(); u++){
            color(1,1,0);
            p->desenha(vetx[u-1], m[u-1], vetx[u], m[u],1);
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
      if(x > 24 && x < 536 && y > 150 && y <450){
        if(x > xv){
          printf("  vety size: %d", vety.size());
          if(insercao < 128){
            for(int i = 24; i < 536; i+= 4){
                if(x==i){
                  vetx.push_back(x);
                  vety.push_back(y);
                  xv = x;
                  insercao++;
                  printf("   insercao: %d", insercao);
                }
            }

          }
        }
      }
    }
   //printf("\n BOTAO: %d ESTADO: %d X: %d Y:%d", button, state, x, y);
}
