
// *********************************************************************
// Canvas para desenho - Versao C.
//  Autor: Cesar Tadeu Pozzer
//         01/2016
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Tem tratamento de mosue
// *
// *   bsantana@inf.ufsm.br
// *

#include "glwidget.h"
#include "mainwindow.h"
#include "pontos.h"

#include <GL/glu.h>
#include <time.h>

#include <QPainter>
#include <QPaintEngine>
#include <QCoreApplication>
#include <math.h>
#include <QMessageBox>
#include <QWheelEvent>

#define PI2 6.28318530717958
#define PI 3.14159265359

int flag = 0;
int up = 0, down = 0, left = 0, right = 0;
int b = 0;
int v;


Pontos* ptos = new Pontos();

GLWidget::GLWidget(MainWindow *_mw){
    setMinimumSize(300, 250);
    mw = _mw;
    this->setFocusPolicy(Qt::StrongFocus);

}

GLWidget::~GLWidget(){

}



void GLWidget::paintGL(){

    clear(0,0,0.1);
    mw->setStyleSheet("background-image:url(:/images/background.jpg);");

    for(int u = 0; u < 10; u ++){
        if(v == u){
            movimenta(u);
            break;
        }
    }
    color(1,0,0);
    glPointSize(3.0);

    if(b==0){
        b = 1;
        ptos->inicializa(mw->width()-100, mw->height()-200);
    }

    for(int i = 0; i < 10; i++){
        if(i < 9){
            color(1,1,1);
            line(ptos->ptosX[i],ptos->ptosY[i],ptos->ptosX[i+1],ptos->ptosY[i+1]);
        }
        //if(i == 1)
        //   printf("PX: %d  PY: %d", ptos->ptosX[i],ptos->ptosY[i]);
        color(1,0,0);
        rectFill(ptos->ptosX[i]-2, ptos->ptosY[i]-2, ptos->ptosX[i]+2, ptos->ptosY[i]+2);
    }
    //qDebug("LARGURA: %d", mw->width());

}

void GLWidget::movimenta(int u){
    /*arrumar a posicao que deve movimentar */
    if(ptos->ptosY[u] > 15){
        if(down)
            ptos->setY(u, ptos->ptosY[u] -2);
    }
    if(ptos->ptosY[u] < 590){
        if(up == 1)
            ptos->setY(u, ptos->ptosY[u] +2);
    }
    if(ptos->ptosX[u] > 15){
        if(left)
            ptos->setX(u, ptos->ptosX[u] -2);
    }
    if(ptos->ptosX[u] < mw->width() - 165){
        if(right)
        ptos->setX(u, ptos->ptosX[u] +2);
    }
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

    int aux  = 600 - event->y();

    for(int u = 0; u < 10; u++){
        //int l =(h-40)/10;
        //printf("\nAUX: %d", aux);
        if((event->x() > ptos->ptosX[u]-2) && (event->x() < ptos->ptosX[u]+2) && (aux > ptos->ptosY[u]-2) && (aux < ptos->ptosY[u]+2)){
            v = u;
            break;
        }
    }
    mw->list->addItem("Mouse Click event");
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event){
    qDebug("\nMouse Release: %d %d", event->x(), event->y());
}

void GLWidget::mouseMoveEvent(QMouseEvent * event){
    int aux  = 600 - event->y();

    qDebug("\nMouse Move: %d %d", event->x(), aux);
    mw->list->addItem("Mouse Move event");
}

void GLWidget::keyPressEvent(QKeyEvent* event){
      qDebug("\nKeyboard Press: %d", event->key());
      mw->list->addItem("Keyboard Press Event");

      switch(event->key()){
        case Qt::Key_Right:
            right = 1;
            break;
        case Qt::Key_Left:
            left = 1;
            break;
        case Qt::Key_Up:
            up = 1;
            break;
        case Qt::Key_Down:
            down = 1;
            break;
        case Qt::Key_B:
            if(b == 0)
                b = 1;
            else
                b = 0;
            break;
        }
}

void GLWidget::keyReleaseEvent(QKeyEvent* event){
    qDebug("\nKeyboard Release: %c", event->key());

    switch(event->key()){
        case Qt::Key_Right:
            right = 0;
            break;
          case Qt::Key_Left:
            left = 0;
            break;
          case Qt::Key_Up:
            up = 0;
            break;
          case Qt::Key_Down:
            down = 0;
            break;
          case Qt::Key_B:
            //b = 0;
            break;
     }
}


//callback para botao definido na mainWindow.
void GLWidget::showMsg(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Msg GlWidget");
    msg->show();
}
