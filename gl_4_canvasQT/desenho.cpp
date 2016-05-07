#include "desenho.h"
#include "glwidget.h"

Desenho::Desenho(){

}

void Desenho::nave(float vx[3], float vy[3]){
    //GLWidget * g = new GLWidget();
    polygonFill(vx,vy,3);
}
