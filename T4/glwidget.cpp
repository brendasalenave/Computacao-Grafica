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

float angley = 0;
float anglex = 0;

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
float znear = 0.1;
float zfar = 900;
float aspect = 1;

int space = 0;
float angClaw = 0;
float sizeA3 = 0.0;
float sizeA2 = 0.0;
float angA2 = 0.0;

GLfloat xRotated, yRotated, zRotated;
GLWidget::GLWidget(MainWindow *mw){
    this->mw = mw;
    this->setMinimumSize(800, 600);
    eyex = 0.0;
    eyey = 0.0;
    eyez = 10.0;
    centerx = 0.0;
    centery = 0.0;
    centerz = 0.0;
/*
    float abertura = 44.0;
    float znear  = 0.1;
    float zfar   = 500;
    float aspect = mw->width()/mw->height();*/
}



void GLWidget::paintGL(){
    this->update();
    if(space == 0)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity( );
    gluLookAt(eyex, eyey, eyez,          //from. Posicao onde a camera esta posicionada
              centerx, centery, centerz, //to. Posicao absoluta onde a camera esta vendo
              0, 1, 0);                  //up. Vetor Up.



   /* Draw base plataform */
   float ***m_base = base->setForm(5.0,0.10,3.0,0.50,1.0,0.0);
   d->cube_(-0.50,-2.70,-10.0,0.0, xRotated, yRotated, zRotated,m_base);

   /* Draw cabin */
   float ***m_cabin = cabin->setForm(0.80,0.80,0.80,0.0,0.4,1.0);
   d->cube_(-0.50,-1.80,-9.0,0.0, xRotated+anglex, yRotated+angley, zRotated,m_cabin);

   m_cabin = cabin->setForm(1.30,1.30,1.30,0.0,0.3,0.60);
   d->cube_(-1.50,-1.80,-9.0,0.0, xRotated+anglex, yRotated+angley, zRotated,m_cabin);

   /* Draw arm1 */
   float ***m_arms = arms->setForm(0.20,2.30,0.40,1.0,1.0,0.0);
   d->cube_(-0.50,-0.60,-9.0,0.0, xRotated+anglex, yRotated+angley, zRotated-10,m_arms);

   /* Draw arm2 */
   m_arms = arms->setForm(0.20,1.50+sizeA2,0.40,1.0,1.0,0.0);
   d->cube_(0.20+(sizeA2/5),0.70+(sizeA2/3)-(angA2/80),-9.0,0.0, xRotated+anglex, yRotated+angley, zRotated-50-angA2,m_arms);

   /* Draw arm3 */
   m_arms = arms->setForm(0.20,1.50+sizeA3,0.40,1.0,1.0,0.0);
   d->cube_(0.80+(sizeA3/3)+(sizeA2/1.6)+(angA2/300),1.1-(sizeA3/3)+(sizeA2/2)-(angA2/40),-9.0,0.0, xRotated+anglex, yRotated+angley, zRotated+45-angA2,m_arms);

   /* Draw claw */
   float ***m_claw = claw->setForm(0.80,0.80,0.80,0.70,0.70,0.70);
   d->cube_(1.5+(sizeA3/3.5)+(sizeA2/1.2)-(angA2/110),0.30-(sizeA3/1.8)+(sizeA2*0.70)-(angA2/35),-09.30,0.0, xRotated+anglex, yRotated+angley, zRotated+45+angClaw-angA2,m_claw);

   /* Piston 1 */
   float ***m_p = piston->setForm(0.02,1.5+(sizeA2*0.2)-(angA2/45),0.02,0.8,0.8,0.8);
   d->cube_(-0.2,0.050,-09.80,0.0, xRotated+anglex, yRotated, zRotated-30,m_p);

   /* Piston 2 */
   m_p = piston->setForm(0.02,0.8+(sizeA2*-0.003)-(angA2/150)+(sizeA3/30),0.02,0.8,0.8,0.8);
   d->cube_(0.30+(sizeA2 /1.5)+(angA2/90)+(sizeA3/8),1.10+(sizeA2*0.6)-(angA2/70)+(sizeA3/25),-09.80,0.0, xRotated+anglex, yRotated, zRotated-10,m_p);


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

    glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h){
    /*glViewport(0, 0, w, h);
    glLoadIdentity();
    gluPerspective(45, (float)(w/h), 0.1, 500);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 0, 0, 0, upx, upy, upz);*/

    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
}

void GLWidget::mousePressEvent(QMouseEvent  *event){
    qDebug("\nMouse Press: %d %d", event->x(), 600 - event->y() );
    switch(event->buttons()){
        case Qt::RightButton:
            if(angley >= -20)
                angley -= 5;
            qDebug("\n angley :%f", angley);
            break;
        case Qt::LeftButton:
            if(angley < 20)
                angley += 5;
            qDebug("\n angley :%f", angley);
            break;
    }
    //xRotated = event->x();
    //yRotated = mw->height() - event->y();
    //eyex = event->x();
    //eyey = event->y();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event){

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
        if(sizeA3 < 0.9)
            sizeA3 += 0.1;
        break;
    case Qt::Key_Left:
        if(sizeA3 > 0.0)
            sizeA3 -= 0.1;
        break;
    case Qt::Key_Up:
        if(anglex >= -10)
            anglex -= 5;
        qDebug("\n anglex :%f", anglex);
        break;
    case Qt::Key_Down:
        if(anglex < 10)
            anglex += 5;
        qDebug("\n anglex :%f", anglex);
        break;
    case Qt::Key_Space:
        if(space == 0)
            space = 1;
        else
            space = 0;
        break;
    case Qt::Key_W:
        if(angClaw < 10)
            angClaw += 1;
        break;
    case Qt::Key_S:
        if(angClaw > -15)
            angClaw -= 1;
        break;
    case Qt::Key_D:
        if(sizeA2 < 0.9)
            sizeA2 += 0.1;
        break;
    case Qt::Key_A:
        if(sizeA2 > 0)
            sizeA2 -= 0.1;
        break;
    case Qt::Key_E:
        if(angA2 < 30)
            angA2 += 1.0;
        break;
    case Qt::Key_Q:
        if(angA2 > 0)
            angA2 -= 1.0;
        break;
    default:
        break;
    }
}

void GLWidget::keyReleaseEvent(QKeyEvent* event){
    qDebug("\nKeyboard Release: %c", event->key());
}
