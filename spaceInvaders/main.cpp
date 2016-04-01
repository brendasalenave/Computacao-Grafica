#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <freeglut.h>
#include "Draw.h"
#include "Ship.h"
#include "Bullet.h"

int width = 1350;
int height = 650;
Draw *d = new Draw();
Ship *a = new Ship();

int pulo = 5;

void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glOrtho (0, 256, 0, 256, -1 ,1);
}

void onKeyboard(int key, int x, int y){
    x = a->getX();
    y = a->getY();
    if(key=='f'){
        a->setPosition(x+pulo,y);
    }else if(key=='d'){
        a->setPosition(x-pulo,y);
    }

}

void onKeyboardascii(unsigned char key, int x, int y){
    if(key=='a'){
        a->shoot();
        a->imprimeShoots();
    }
}

void render(){
    glClear(GL_COLOR_BUFFER_BIT);
    //a->scale(20);
    if(a->getX()<0){
        a->setPosition(0,a->getY());
    }else if(a->getX()>240){
        a->setPosition(240,a->getY());
    }
    d->ship2d(a->getShape(),a->getX(),a->getY(),5.0);
    a->renderShoots();
    a->updateBulletsPosition();
    a->liberaShoots();
}

void display(int n){
    render();
    glutTimerFunc(50,display,1000);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0,0);

    glutInitWindowSize(width,height);

    glutCreateWindow("Space Invaders");

    init();

    a->setShape();

    a->iniciaShoots();

    glutDisplayFunc(render);
    glutTimerFunc(1000,display,1000);

    glutKeyboardFunc(onKeyboardascii);

    glutSpecialFunc(onKeyboard);

    glutMainLoop();

    return 0;

}
