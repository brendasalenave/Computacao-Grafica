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


std:: vector <int> vety;
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
       for(int u = 1; u < vety.size(); u++){
          //if(vety[u-1] != 0){
            p->desenha(vetx[u-1], vety[u-1], vetx[u], vety[u],0);

            /*int i = u-1;
            if(i%8 == 0){
                int c = 0;
                int m[8], mx[8];
                double* m1 = (double*)malloc(8*sizeof(double));
                int *m2 = (int*)malloc(8*sizeof(int));

                int j = i+8;
                for(i, c; i < j; i++, c++){
                    m[c] = vety[i];
                    mx[c] = vetx[i];
                }
                m1 = d->fdct(m);
                d->t = 10;
                d->threshold(m2);
                m2 = d->idct(m1);

                color(1,1,0.1);
                for(c = 1; c < 8; c++){
                    p->desenha(mx[c-1],m2[c-1],mx[c],m2[c],1);
                }
            }*/

           //}
       }
   }
   /*for(int u = 1; u < 128; u++){
      if(array_y[u-1] != 0){
        p->desenha(array_x[u-1], array_y[u-1], array_x[u], array_y[u]);
        //pt++;
       }
      //color(0,0,0);
   }*/

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
          /* ceilf((float)x/(width/128.0f)) */
          //array_x[i] = x;
          //array_y[i] = y;

          //  xv = x;
          printf("  vety size: %d", vety.size());
          if(insercao < 128){
            for(int i =24; i<526; i+= 4){
                if(x==i){
                  vetx.push_back(x);
                  vety.push_back(y);
                  xv = x;
                  insercao++;
                  printf("   insercao: %d", insercao);
                }
            }

          }

          /*if(j % 4 == 0){
              printf("  j: %d", j);
              array_y[j] = y;
              array_x[j] = x;
              j++;
          }*/

        }
      }
    }
   //printf("\n BOTAO: %d ESTADO: %d X: %d Y:%d", button, state, x, y);
}

/*void geraGrafico(int x1, int x2, int y1, int y2){
    line(x1, y1, x2, y2 );
    point(x1, y1);
}*/
