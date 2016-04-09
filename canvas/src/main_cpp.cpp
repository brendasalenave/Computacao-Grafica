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
#include <vector>

#include "gl_canvas2d.h"

#include "Botao.h"
#include "Pontos.h"


std:: vector <int> vety (128);
std:: vector <int> vetx (128);

//variaveis globais
int   opcao  = 50;
int xv = 0;
int px, py;
int height = 0;
int width = 0;
int pt = 0;

int pressionado = 0;

Botao  * b = new Botao();
Pontos * p = new Pontos(px, py, 1, 0, 0);

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render();
//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key);
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key);
//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y);

int main(void){
    height = 600;
    width = 1100;
    initCanvas(width,height);

   runCanvas();
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render(){
   rect(24, 150, 536, 550);
   line(24,350,536,350);
   text(24, 353, "(0,0)");
   text(124, 555, "Area para desenho do Grafico");

   color(0, 0, 0);
   rectFill(0, 0, 1200, 80);

   b->desenha();
   if(b->getFlag() == 1){
      b->seno();
   }
   for(int u = 1; u < vety.size(); u++){
      p->desenha(vetx[u-1], vety[u-1]);
      //color(0,0,0);
      line(vetx[u-1], vety[u-1], vetx[u], vety[u]);
      pt++;
   }
   pt = 0;
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
        if(x > 24 && x < 512 && y > 150 && y <550){
            if(x > xv){
                /* ceilf((float)x/(width/128.0f)) */
                vetx.push_back(x);
                vety.push_back(y);
                xv = x;
            }
        }
    }

   //printf("\n BOTAO: %d ESTADO: %d X: %d Y:%d", button, state, x, y);
}

/*void geraGrafico(int x1, int x2, int y1, int y2){
    line(x1, y1, x2, y2 );
    point(x1, y1);
}*/
