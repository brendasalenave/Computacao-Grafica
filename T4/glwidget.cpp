#include "glwidget.h"
#include "draw.h"
#include "cube.h"
#include <math.h>
#include <GL/glu.h>
#include <QKeyEvent>

#define PI_2 6.28318530718


//float rx = 0, rz = 0;

Draw *d = new Draw();
Cube *base = new Cube();
Cube *a1 = new Cube();
Cube *a2 = new Cube();
Cube *a3 = new Cube();
Cube *claw = new Cube();

// Camera
// Ponto onde esta
float eyex;
float eyey;
float eyez;

// Ponto para onde olha
float centerx;
float centery;
float centerz;

//UP
const GLdouble upx = 0;
const GLdouble upy = 1;
const GLdouble upz = 0;

int   polygonMode = 1;
float rx = 0, rz = 0;

   float abertura = 44.0;
   float znear  = 1;
   float zfar   = 20;
   float aspect = 1;

GLfloat xRotated, yRotated, zRotated;
GLWidget::GLWidget(MainWindow *mw){
    this->mw = mw;
    this->setMinimumSize(800, 600);
    eyex = 10.0;
    eyey = 10.0;
    eyez = 10.0;
    centerx = 0.0;
    centery = 0.0;
    centerz = 0.0;
}



void GLWidget::paintGL(){
    glLoadIdentity( );
    gluLookAt(eyex, eyey, eyez,  //from. Posicao onde a camera esta posicionada
              centerx, centery, centerz,  //to. Posicao absoluta onde a camera esta vendo
              0, 1, 0); //up. Vetor Up.
    //glRotatef ((GLfloat) xRotated, 0.0f, 1.0f, 0.0f);
    //glRotatef ((GLfloat) yRotated, 1.0f, 0.0f, 0.0f);

   /* Draw base plataform */
   float ***m_base = base->setForm(5.0,0.10,3.0,1.0,1.0,1.0);
   d->cube_(0.0,-2.50,-10.0,0.0, xRotated, yRotated, zRotated,m_base);

   /* Draw the first arm */
   float ***m_arm1 = a1->setForm(0.30,3.0,0.50,1.0,1.0,0.0);
   d->cube_(-1.0,-0.90,-09.5,0.0, xRotated, yRotated, zRotated,m_arm1);

   /* Draw the second arm */
   float ***m_arm2 = a2->setForm(0.30,1.50,0.50,1.0,1.0,0.0);
   d->cube_(-0.50,1.0,-09.30,0.0, xRotated, yRotated, zRotated-45,m_arm2);

   /* Draw the third arm */
   float ***m_arm3 = a2->setForm(0.30,1.50,0.50,0.50,1.0,0.0);
   d->cube_(0.40,1.3,-09.30,0.0, xRotated, yRotated, zRotated+45,m_arm3);

   /* Draw claw */
   float ***m_claw = claw->setForm(1.0,1.0,1.0,0.70,0.70,0.70);
   d->cube_(1.20,0.50,-09.30,0.0, xRotated, yRotated, zRotated+45,m_claw);


   /* d->cylinder_(10,10,10);*/

   /*glFlush();
   yRotated += 0.01;
   xRotated += 0.02;*/

}

void GLWidget::initializeGL(){
    initializeOpenGLFunctions();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    gluPerspective(abertura, aspect, znear, zfar);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0, 0, 0, 1);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    glLoadIdentity();
    gluPerspective(45, (float)(w/h), 0.1, 500);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 0, 0, 0, upx, upy, upz);
}

void GLWidget::mousePressEvent(QMouseEvent  *event){
    qDebug("\nMouse Press: %d %d", event->x(), 600 - event->y() );
    //xRotated = event->x();
    //yRotated = mw->height() - event->y();
    //eyex = event->x();
    //eyey = event->y();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event){
    //qDebug("\nMouse Press: %d %d", event->x(), 600 - event->y() );
    xRotated = event->x();
    yRotated = mw->height() - event->y();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event){
    qDebug("\nMouse Release: %d %d", event->x(),event->y());
}

void GLWidget::keyboard(QKeyEvent *event){
    this->keyPressEvent(event);
}

void GLWidget::keyPressEvent(QKeyEvent *event){
    qDebug("\nKeyboard Press: %c", event->key());
}

void GLWidget::keyReleaseEvent(QKeyEvent* event){
    qDebug("\nKeyboard Release: %c", event->key());
}
