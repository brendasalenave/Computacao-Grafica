
// *********************************************************************
//  Autor: Brenda S. Santana
//         05/2016
// *
// *   bsantana@inf.ufsm.br
// *
//

#include "glwidget.h"
#include "mainwindow.h"
#include "nave.h"

#include <QPainter>
#include <QPaintEngine>
#include <QCoreApplication>
#include <math.h>
#include <QMessageBox>
#include <QWheelEvent>
#include <QKeyEvent>


float global = 0;
int r_dir = 0, r_esq = 0;
int up = 0, down = 0;
int a = 0, s = 0;
Nave *n = new Nave();

GLWidget::GLWidget(MainWindow *_mw){
    setMinimumSize(600, 250);
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
        if(n->getTheta() >= 6.27)
            n->setTheta(0);
        n->setTheta(n->getTheta() + 0.05);
        n->rotacao(1, 0.05);
    }
    if(r_esq == 1){
        if(n->getTheta() >= 6.27)
            n->setTheta(0);
        n->setTheta(n->getTheta() - 0.05);
        n->rotacao(0, 0.05);
    }
    if(up == 1){
        n->deslocamento();
    }
    if(a == 1){
        n->setSpeed(0.1, 1);
    }
    if(s == 1){
        n->setSpeed(0.1, 2);

    }
    /*float vecX[3], vecY[3];
    vecX[0] = 350; vecY[0] = 275;
    vecX[1] = 250; vecY[1] = 275;
    vecX[2] = 300; vecY[2] = 325;
    polygonFill(vecX,vecY,3);*/

    /*for(int i = 0; i < 3; i++){
        printf("vx[%d]: %f  -  vy[%d]: %f", i, n->vx[i],i,n->vy[i]);
    }*/

    drawNave(n->vx,n->vy);

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
        case Qt::Key_A:
          a = 1;
          break;
        case Qt::Key_S:
          s = 1;
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
      case Qt::Key_A:
        a = 0;
        break;
      case Qt::Key_S:
        s = 0;
        break;
    }
}

//callback para botao definido na mainWindow
void GLWidget::showMsg(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("A : acelera \nS : freia \n"
                 "Up arrow: desloca nave \nRight arrow: giro à direita \n"
                 "Left arrow: giro à esquerda \n"
                 "\n**PARA INICIAR O JOGO, CLIQUE NA TELA!");
    msg->setWindowTitle("Comandos de Jogo");
    msg->show();
}

void GLWidget::drawNave(float vpx[3], float vpy[3]){
    color(0,0.4,1);
    polygonFill(vpx,vpy,3);
}
