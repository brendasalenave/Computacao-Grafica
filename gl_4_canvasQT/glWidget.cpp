
// *********************************************************************
//  Autor: Brenda S. Santana
//         05/2016
// *
// *   bsantana@inf.ufsm.br
// *
//

#include <math.h>

#include "glwidget.h"
#include "mainwindow.h"
#include "nave.h"
#include "tiro.h"

#include <QPainter>
#include <QPaintEngine>
#include <QCoreApplication>
#include <math.h>
#include <QMessageBox>
#include <QWheelEvent>
#include <QKeyEvent>

#define PI_2 6.2831853

using namespace std;

float global = 0;
int r_dir = 0, r_esq = 0;
int up = 0, down = 0;
int space = 0;
Nave *n = new Nave();

GLWidget::GLWidget(MainWindow *_mw){
    setMinimumSize(600, 250);
    setMaximumHeight(600);

    mw = _mw;
    this->setFocusPolicy(Qt::StrongFocus);
}

GLWidget::~GLWidget(){

}


// *******************************************************************************
//Coloque seu codigo aqui, usando as funcoes da Canvas2D defindas na classe glWidgets.
// *******************************************************************************
void GLWidget::paintGL(){
    clear(0, 0, 0);

    //mw->setStyleSheet("color:white;");
    mw->setStyleSheet("background-image:url(:/images/background.jpg);");

    //n->setShape(n->getX(),n->getY());
    if(r_dir == 1){
        if(n->getTheta() >= PI_2)
            n->setTheta(0);
        else if(n->getTheta() <= 0)
            n->setTheta(PI_2);
        n->setTheta(n->getTheta() - 0.08);

        n->rotacao(1, 0.08);
    }
    if(r_esq == 1){
        if(n->getTheta() >= 6.27)
            n->setTheta(0);
        else if(n->getTheta() <= 0)
            n->setTheta(6.27);

        n->setTheta(n->getTheta() + 0.08);
        n->rotacao(0, 0.08);
    }

    if(up == 1){
        n->setSpeed(0.2, 1);
    }
    if(down == 1){
        n->setSpeed(0.2, 2);
    }
    if(space == 1){
        n->atira();
        drawTiro();
    }
    n->deslocamento(mw->width(),mw->height());
    n->deslocaTiro();

    drawNave(n->tempX,n->tempY);

}


void GLWidget::wheelEvent(QWheelEvent *event){
    //printf("\nMouse Wheel event: %d", event->delta() );
    qDebug("Mouse Wheel event %d", event->delta() );
    mw->list->addItem("Mouse Wheel event");
}

void GLWidget::mousePressEvent(QMouseEvent *event){
    qDebug("\nMouse Press: %d %d", event->x(), event->y() );
    if(event->buttons() == Qt::RightButton)
        qDebug( "Only right button" );
    mw->list->addItem("Mouse Click event");
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event){
    qDebug("\nMouse Release: %d %d", event->x(), event->y());
}

void GLWidget::mouseMoveEvent(QMouseEvent * event){
    qDebug("\nMouse Move: %d %d", event->x(), event->y());
    mw->list->addItem("Mouse Move event");
}

void GLWidget::keyPressEvent(QKeyEvent* event){
      qDebug("\nKeyboard Press: %d", event->key());
      mw->list->addItem("Keyboard Press Event");
      switch(event->key()){
        case Qt::Key_Right:
          r_dir = 1;
          break;
        case Qt::Key_Left:
          r_esq = 1;
          break;
        case Qt::Key_Up:
          up = 1;
          break;
        case Qt::Key_Down:
          down = 1;
          break;
        case Qt::Key_Space:
          space = 1;
          break;
        }

}

void GLWidget::keyReleaseEvent(QKeyEvent* event){
    qDebug("\nKeyboard Release: %c", event->key());

    switch(event->key()){
      case Qt::Key_Right:
        r_dir = 0;
        break;
      case Qt::Key_Left:
        r_esq = 0;
        break;
      case Qt::Key_Up:
        up = 0;
        break;
      case Qt::Key_Down:
        down = 0;
        break;
      case Qt::Key_Space:
        space = 0;
        break;
    }
}

//callback para botao definido na mainWindow
void GLWidget::showMsg(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setText(" Up arrow: acelera \n"
                 " Down arrow: freia \n"
                 " Right arrow: giro à direita \n"
                 " Left arrow: giro à esquerda \n"
                 "\n**PARA INICIAR O JOGO, CLIQUE NA TELA!");
    msg->setWindowTitle("Comandos do Jogo");
    msg->show();
}

void GLWidget::drawNave(float vpx[3], float vpy[3]){
    color(0,0.4,1);
    polygonFill(vpx,vpy,3);
}

void GLWidget::drawTiro(){
    std::vector<Tiro*> tmp;
    tmp = n->tiro;
    color(0.8, 0.8, 0);
    glPointSize(4.0);
    std::vector<Tiro*>::iterator it;

    for(it = tmp.begin(); it != tmp.end(); it++){
        /* por enquanto ta desenhando 'dentro' do poligono */
        point((*it)->getX(), (*it)->getY());
    }
}
