
// *********************************************************************
// Canvas para desenho - Versao C.
//  Autor: Cesar Tadeu Pozzer
//         01/2016
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Tem tratamento de mosue
// *
// *   pozzer@inf.ufsm.br
// *   pozzer3@gmail.com
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
int rdir = 0;
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

    //float x=0, y;

    n->setShape(0,0);
    if(rdir == 1){
        n->setTheta(n->getTheta() + 0.01);
        n->rotacao(n->getTheta());
    }
    /*for(int i = 0; i < 3; i++)
       printf("\nvx[%d]: %f", i, n->vx[i]);
    for(int i = 0; i < 3; i++)
       printf("\nvy[%d]: %f", i, n->vy[i]);*/

    drawNave(n->vx,n->vy);
}


void GLWidget::wheelEvent(QWheelEvent *event)
{
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
          rdir = 1;
         // n->setTheta(n->getTheta() + 0.26);
          break;
      }

}

void GLWidget::keyReleaseEvent(QKeyEvent* event){
    qDebug("\nKeyboard Release: %c", event->key());

    switch(event->key()){
      case Qt::Key_E:
        rdir = 0;
    }
}

//callback para botao definido na mainWindow.
void GLWidget::showMsg(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Computação Gráfica - T2\nbsantana@inf.ufsm.br");
    msg->show();
}

void GLWidget::drawNave(float vpx[3], float vpy[3]){
    color(0,0.4,1);
    polygonFill(vpx,vpy,3);
}
