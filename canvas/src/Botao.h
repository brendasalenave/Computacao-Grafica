#ifndef __BOTAO_H__
#define __BOTAO_H__

#include "gl_canvas2d.h"

class Botao{
  int posx, posy;
  float r, g, b; //cor do botao

public:
  Botao(){
     posy = 20;
     posx = 850;
     r = 0;
     g = 20;
     b = 0;
  }

  void anima(){
      //r = altura/400.0;
      clear(0,0,0);
      color(r, g, b);
      /*if( altura > 10 && caindo == true ) //caindo
      {
         vel += 0.001;
         altura -= vel;
      }
      //bate no chao
      else if( altura < 10 && caindo == true ){
         vel = -vel;
         altura -= vel;
         caindo = false;
      }
      //subindo
      if( altura < 400 && caindo == false ){
         vel += 0.001;
         altura-= vel;
      }
      else if( vel < 0 && caindo == false ){
         vel    = 0.001;
         caindo = true;
      }*/

      rectFill(posx, posy, posx+35, posy+35 ); //coordenadas do retangulo x1, y1, x2, y2
      color(0,0,0);
      text(posx+14,posy+14,"T");


  }

  void move(int delta){
     //posicao += delta;
  }
};

#endif
