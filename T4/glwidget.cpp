#include "glwidget.h"
#include "draw.h"
#include <GL/glu.h>
#include <QKeyEvent>

//float rx = 0, rz = 0;


// Camera
// Ponto onde esta
float x_eye;
float y_eye;
float z_eye;

// Ponto para onde olha
float x_center;
float y_center;

int   polygonMode = 1;
float rx = 0, rz = 0;

   float abertura = 44.0;
   float znear  = 1;
   float zfar   = 20;
   float aspect = 1;

float z_center;

 GLfloat xRotated, yRotated, zRotated;
GLWidget::GLWidget(MainWindow *mw){
    this->mw = mw;
    this->setMinimumSize(800, 600);
    x_eye = 10.0;
    y_eye = 10.0;
    z_eye = 10.0;
    x_center = 0.0;
    y_center = 0.0;
    z_center = 0.0;
}



void GLWidget::paintGL(){
    glMatrixMode(GL_MODELVIEW);
       // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-10.5);
    Draw *d = new Draw();
    d->cube_(0.0,0.0,-10.0,0.0, xRotated, yRotated, zRotated);

  /*glRotatef(xRotated,1.0,0.0,0.0);
  // rotation about Y axis
  glRotatef(yRotated,0.0,1.0,0.0);
  // rotation about Z axis
  glRotatef(zRotated,0.0,0.0,1.0);*/

   glFlush();
   yRotated += 0.01;
   xRotated += 0.02;


}

void GLWidget::initializeGL(){
    initializeOpenGLFunctions();


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      // printf("\n%f", abertura);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity( );
       //glOrtho(-1,1,-1,1,1,-1);

       //printMatrix(GL_PROJECTION_MATRIX);

       gluPerspective(abertura, aspect, znear, zfar);

       //printMatrix(GL_MODELVIEW_MATRIX);

       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity( );
       gluLookAt(0, 0, 3,  //from. Posicao onde a camera esta posicionada
                 0, 0, 0,  //to. Posicao absoluta onde a camera esta vendo
                 0, 1, 0); //up. Vetor Up.


}

void GLWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    glLoadIdentity();
    gluPerspective(45, (float)(w/h), 0.1, 500);
    glLoadIdentity();
    gluLookAt(x_eye, y_eye, z_eye, 0, 0, 0, 0, 1, 0);
}

void GLWidget::mousePressEvent(QMouseEvent  *event){

}

void GLWidget::mouseMoveEvent(QMouseEvent * event){

}

void GLWidget::mouseReleaseEvent(QMouseEvent *event){

}

void GLWidget::keyboard(QKeyEvent *event){
    this->keyPressEvent(event);
}

void GLWidget::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Y:
            y_eye += 0.1;
            break;
        case Qt::Key_Z:
            z_eye += 0.1;
            break;
        case Qt::Key_X:
            x_eye += 1;
            break;
        case Qt::Key_Q:
            exit(1);
    }

}
