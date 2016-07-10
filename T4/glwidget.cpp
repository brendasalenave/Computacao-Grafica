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
Cube *cabin = new Cube();
Cube *arms = new Cube();
Cube *piston = new Cube();
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

   float abertura;// = 44.0;
   float znear;//  = 0.1;
   float zfar;//   = 20;
   float aspect;// = mw->1;

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

    float abertura = 44.0;
    float znear  = 0.1;
    float zfar   = 500;
    float aspect = mw->width()/mw->height();
}



void GLWidget::paintGL(){
    this->update();
    glLoadIdentity( );
    gluLookAt(10, 10, 10,          //from. Posicao onde a camera esta posicionada
              centerx, centery, centerz, //to. Posicao absoluta onde a camera esta vendo
              0, 1, 0);                  //up. Vetor Up.

    qDebug("\neyex: %f",eyez);





    /* Draw cabin */
    float ***m_cabin = cabin->setForm(1.20,1.20,1.20,0.0,0.55,0.80);
    d->cube_(-1.80,-1.70,-9.20,0.0, xRotated, yRotated, zRotated,m_cabin);

   /* Draw base plataform */
   float ***m_base = base->setForm(5.0,0.10,3.0,0.50,1.0,0.0);
   d->cube_(-0.50,-2.50,-10.0,0.0, xRotated, yRotated, zRotated,m_base);

   /* Draw arm1 */
   float ***m_arms = arms->setForm(0.30,2.50,0.50,1.0,1.0,0.0);
   d->cube_(-1.0,-0.90,-09.5,0.0, xRotated, yRotated, zRotated-10,m_arms);

   /* Draw arm2 */
   m_arms = arms->setForm(0.30,1.50,0.50,1.0,1.0,0.0);
   d->cube_(-0.3,0.70,-09.30,0.0, xRotated, yRotated, zRotated-45,m_arms);

   /* Draw arm3 */
   m_arms = arms->setForm(0.30,1.50,0.50,1.0,1.0,0.0);
   d->cube_(0.40,1.3,-09.30,0.0, xRotated, yRotated, zRotated+45,m_arms);

   /* Draw claw */
   float ***m_claw = claw->setForm(0.80,0.80,0.80,0.70,0.70,0.70);
   d->cube_(1.21,0.50,-09.30,0.0, xRotated, yRotated, zRotated+45,m_claw);

   /* Piston 1 */
   float ***m_p = piston->setForm(0.02,1.40,0.02,0.8,0.8,0.8);
   d->cube_(-0.55,0.050,-09.30,0.0, xRotated, yRotated-30, zRotated-30,m_p);

   /* Piston 2 */
   m_p = piston->setForm(0.02,1.0,0.02,0.8,0.8,0.8);
   d->cube_(-0.20,1.20,-09.30,0.0, xRotated, yRotated-30, zRotated-10,m_p);


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
    //xRotated = event->x();
    //yRotated = mw->height() - event->y();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event){
    qDebug("\nMouse Release: %d %d", event->x(),event->y());
}

void GLWidget::keyboard(QKeyEvent *event){
    this->keyPressEvent(event);
}

void GLWidget::keyPressEvent(QKeyEvent *event){
    qDebug("\nKeyboard Press: %c", event->key());
    switch (event->key()) {
    case Qt::Key_Right:
        eyez += 5;
        qDebug("\neye x:%f", eyex);
        break;
    case Qt::Key_Left:
        zRotated -= 0.5;
        break;
    default:
        break;
    }
}

void GLWidget::keyReleaseEvent(QKeyEvent* event){
    qDebug("\nKeyboard Release: %c", event->key());
}
