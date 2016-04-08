/*********************************************************************
// Canvas para desenho - Versao CPP.
//  Autor: Cesar Tadeu Pozzer
//         10/2007
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Instruções:
//    Para compilar em C, basta comentar o comando #define _CPP_
//	  Para alterar a animacao, digite numeros entre 1 e 7
// *********************************************************************/

/*
  Autor: Cesar Tadeu Pozzer
         04/2013

  Instruções:
	  Para alterar a animacao, digite numeros entre 1 e 7
*/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "gl_canvas2d.h"

#include "Bola.h"
#include "Botao.h"


Botao *b = NULL;
Bola  *ball = NULL;

std:: vector <int> vety;
//std:: vector <int> vetx;

//int vety[128];
//int vetx[128];

int pt = 0;
//variaveis globais
int   opcao  = 50;
float global = 0;
int xv = 0;
int yv = 0;
int height = 0;
int width = 0;

int pressionado = 0;


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

   b = new Botao();
   ball = new Bola();

   runCanvas();
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render(){
   rect(24, 150, 512, 550);
   line(24,350,512,350);
   text(24, 353, "(0,0)");
   text(124, 555, "Area para desenho do Grafico");


   for(float i=0; i<950; i++){
	   color(i/900, i/900, i/900);
	   point((int)(i), (int)(68));
   }
    for(float i=0; i<950; i++){
	   color(i/900, i/900, i/900);
	   point((int)(i), (int)(70));
   }
    for(float i=0; i<950; i++){
	   color(i/900, i/900, i/900);
	   point((int)(i), (int)(72));
   }

   if( opcao == 49 ){ // = '1' bola
      ball->anima();
   }
   if( opcao == '2' ){ // = 50 botao
      b->anima();
   }
   if( opcao == 51){ // = '3' linha animada
      clear(1,1,1); //limpa a tela de branco
      color(0.7, 0.7, 0);
      line((int)global, 100, (int)global, 400);
      global += 0.1;
   }
   if( opcao == 52 ){ // = '5' linha andando
      clear(0,0,0);
      color(1, 1, 0);
      rect(200-(int)global, 200-(int)global, 200+(int)global, 200 + (int)global);
      global += 0.05;
   }
   if( opcao == 54 ){ // = '7' senoide
       //line( 10,10, 300,300 );
       //circle( 300,300, 100, 1150);
       float x=0, y;
       color(0, 1, 0);
       for(float i=0; i < 6.28; i+=0.001){
          y = sin(i)*50;
          point((int)x, y+100);
          x+=0.01;
       }
       //rectFill( 20,20,230,130 );
   }

   for(int u = 0; u < vety.size(); u+=2){
      color(1, 0, 0);
      point(vety[u], vety[u+1]);
      /*color(0,1,0.9);
      point(vety[u],350);*/
      //printf("\ntamanho vetor: %d", vety.size());
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

	  //seta para a esquerda
      case 200:
         ball->move(-10);
	  break;

	  //seta para a direita
	  case 202:
         ball->move(10);
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
        yv = y;
        if(x > 24 && x < 512 && y > 150 && y <550){
            if(x > xv){
                /* ceilf((float)x/(width/128.0f)) */
                vety.push_back(x);
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
