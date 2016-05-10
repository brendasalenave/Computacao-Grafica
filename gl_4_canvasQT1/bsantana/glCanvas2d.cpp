// *********************************************************************
//  Autor: Brenda Salenave Santana
//         05/2016
//
// *
// *   bsantana@inf.ufsm.br
// *
//



#include <math.h>
#include <QPainter>

#include <QPaintEngine>
#include <QCoreApplication>

#include "glwidget.h"


#define PI_2 6.28318530717958


void GLWidget::point(int x, int y){
   glBegin(GL_POINTS);
      glVertex2d(x, y);
   glEnd();
}

void GLWidget::line( int x1, int y1, int x2, int y2 ){
   glBegin(GL_LINES);
      glVertex2d(x1, y1);
      glVertex2d(x2, y2);
   glEnd();
}

void GLWidget::rect( int x1, int y1, int x2, int y2 ){
   glBegin(GL_LINE_LOOP);
      glVertex2d(x1, y1);
      glVertex2d(x1, y2);
      glVertex2d(x2, y2);
      glVertex2d(x2, y1);
   glEnd();
}

void GLWidget::rectFill( int x1, int y1, int x2, int y2 )
{
   glBegin(GL_QUADS);
      glVertex2d(x1, y1);
      glVertex2d(x1, y2);
      glVertex2d(x2, y2);
      glVertex2d(x2, y1);
   glEnd();
}

void GLWidget::polygon(float vx[], float vy[], int elems){
   int cont;
   glBegin(GL_LINE_LOOP);
      for(cont=0; cont<elems; cont++){
         glVertex2d(vx[cont], vy[cont]);
      }
   glEnd();

}

void GLWidget::polygonFill(float vx[], float vy[], int elems){
   int cont;
   glBegin(GL_POLYGON);
      for(cont=0; cont<elems; cont++){
         glVertex2d(vx[cont], vy[cont]);
      }
   glEnd();

}

void GLWidget::text(int x, int y, const char *t){
    QPainter painter;
    painter.begin(this);

    painter.setPen(Qt::black );
    painter.drawText(x, y, t);
    //painter.

    painter.end();
}

void GLWidget::clear(float r, float g, float b){
   glClearColor( r, g, b, 1 );
}

void GLWidget::circle( int x, int y, int raio, int div ){
   float ang, x1, y1;
   float inc = PI_2/div;
   glBegin(GL_LINE_LOOP);
      for(ang=0; ang<6.27; ang+=inc) //nao vai ateh PI_2 pois o ultimo ponto eh fechado automaticamente com o primeiro, pois tem o tipo LINE_LOOP
      {
         x1 = (cos(ang)*raio);
         y1 = (sin(ang)*raio);
         glVertex2d(x1+x, y1+y);
      }
   glEnd();
}

void GLWidget::circleFill( int x, int y, int raio, int div ){
   float ang, x1, y1;
   float inc = PI_2/div;
   glBegin(GL_POLYGON);
      for(ang=0; ang<6.27; ang+=inc)      {
         x1 = (cos(ang)*raio);
         y1 = (sin(ang)*raio);
         glVertex2d(x1+x, y1+y);
      }
   glEnd();
}

void GLWidget::color(float r, float g, float b){
   glColor3d(r, g, b  );
}


void GLWidget::resizeGL(int w, int h){
    printf("\n Resize w=%d h=%d", w, h);

    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    //cria uma projecao ortografica com z entre (-1, 1).
    //parametros: left, right, bottom, top, ou seja, (0,0) --> (largura,altura)
    glOrtho (0.0, (GLdouble) w, 0.0, (GLdouble) h, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();
}


void GLWidget::initializeGL(){
    initializeOpenGLFunctions();

    glClearColor(0,0,0,1.0);

    glPolygonMode(GL_FRONT, GL_FILL);


    //define o framerate de desenho.
    //**************************************

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1);
    timer->setInterval(20);
}
