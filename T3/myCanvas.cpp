
// *********************************************************************
// Canvas para desenho - Versao C.
//  Autor: Cesar Tadeu Pozzer
//         07/2016
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Tem tratamento de mosue
// *
// *   pozzer@inf.ufsm.br
// *   pozzer3@gmail.com
// *
//

#include "glCanvas2d.h"
#include "mainwindow.h"
#include "ponto.h"
#include "transformacoes.h"

#include <math.h>
#include <QMessageBox>
#include <QWheelEvent>
#include <vector>

using namespace std;

float global = 0;

std::vector<Ponto> ponto;
std::vector<Ponto> ponto2;

Transformacoes *t = new Transformacoes();

int f, v = -1;
int up = 0, down = 0, l = 0, r = 0;
//int del = 0;
int b = 0;
int c = 1;


// *******************************************************************************
//Coloque seu codigo aqui, usando as funcoes da Canvas2D defindas na classe glWidgets.
// *******************************************************************************
void Canvas2D::paintGL(){
    clear(0,0,0.1);
    mw->setStyleSheet("background-image:url(:/images/background.jpg);");
    mw->update();


    std::vector<Ponto>::size_type tam = ponto.size();

    for(int u = 0; u < tam; u ++){
        if(v == u){
            movimenta(u);
            break;
        }
    }

    int oldX = 0, oldY = 0;

    for(int u = 0; u < tam ; u++){
        if(oldX !=0 && oldY !=0){
            color(1,1,1);
            line(oldX, oldY, ponto[u].getX(), ponto[u].getY());
        }
        glPointSize(3);
        color(1,0.5,0);
        rectFill(ponto[u].getX()-2, ponto[u].getY()-2, ponto[u].getX()+2, ponto[u].getY()+2);

        oldX = ponto[u].getX();
        oldY = ponto[u].getY();
    }


    std::vector<Ponto>::size_type tam2 = ponto2.size();
    oldX = 0, oldY = 0;
    for(int u = 0; u < tam2 ; u++){
        if((u+20) < tam2){
            line(ponto2[u+20].getX(), ponto2[u+20].getY(), ponto2[u].getX(), ponto2[u].getY());
        }

        if(((u + 1) < tam2)){ // && ((u%20) != 0)
            line(ponto2[u+1].getX(), ponto2[u+1].getY(), ponto2[u].getX(), ponto2[u].getY());
        }
     }
}

void Canvas2D::movimenta(int u){
    if(ponto[u].getY() > 15){
        if(down)
            ponto[u].setY(ponto[u].getY() - 2);
    }
    if(ponto[u].getY() < 590){
        if(up)
            ponto[u].setY(ponto[u].getY() + 2);
    }
    if(ponto[u].getX() > 15){
        if(l)
            ponto[u].setX(ponto[u].getX() - 2);
    }
    if(ponto[u].getX() < mw->width() - 215){
        if(r)
            ponto[u].setX(ponto[u].getX() + 2);
    }
}

void Canvas2D::wheelEvent(QWheelEvent *event){
    //printf("\nMouse Wheel event: %d", event->delta() );
    qDebug("Mouse Wheel event %d", event->delta() );
    mw->list->addItem("Mouse Wheel event");
}

void Canvas2D::mousePressEvent(QMouseEvent *event){
    qDebug("\nMouse Press: %d %d", event->x(), 600 - event->y() );
    if(event->buttons() == Qt::RightButton)
        f = 0;
    else if(event->buttons() == Qt::LeftButton)
        f = 1;
    mw->list->addItem("Mouse Click event");
    int mouse_y = 600 - event->y();

    if((f==1) && (event->x() > 15) && event->x() < mw->width()-215 && (mouse_y > 15) && (mouse_y < 590)){
        Ponto p;
        p.setX(event->x());
        p.setY(mouse_y);
        ponto.push_back(p);
    }
    if(!f){
        for(int u = 0; u < ponto.size(); u++){
            if((event->x() > ponto[u].getX()-2) && (event->x() < ponto[u].getX()+2) && (mouse_y > ponto[u].getY()-2) && (mouse_y < ponto[u].getY()+2)){
                v = u;
                break;
            }
        }
    }
}

void Canvas2D::mouseReleaseEvent(QMouseEvent *event){
    qDebug("\nMouse Release: %d %d", event->x(),600-event->y());
}

void Canvas2D::mouseMoveEvent(QMouseEvent * event){
    qDebug("\nMouse Move: %d %d", event->x(), event->y());
    mw->list->addItem("Mouse Move event");
}

//callback para botao definido na mainWindow.
void Canvas2D::showMsg(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Msg GlWidget");
    msg->show();
}

void Canvas2D::radioCheck(bool enabled){
    if(enabled == true)
        c = 1;
}

void Canvas2D::radioCheck2(bool enabled){
    if(enabled == true)
        c = 0;
}

void Canvas2D::buttonPressed(){
    qDebug("Sweep Button Pressed");
    std::vector<Ponto>::size_type tam = ponto.size();
    ponto2 = ponto;
    //qDebug("C: %d", c);
    ponto2 = t->cria(ponto2,tam,c);
    std::vector<Ponto>::size_type tam2 = ponto.size();
}

void Canvas2D::button2Pressed(){
    qDebug("Clean Button Pressed");

    std::vector<Ponto>::size_type tam = ponto.size();
    for(int u = 0; u < tam ; u++){
        ponto.pop_back();
    }
    std::vector<Ponto>::size_type tam2 = ponto2.size();
    for(int u = 0; u < tam2 ; u++){
        ponto2.pop_back();
    }
}

void Canvas2D::button1Pressed(){
    qDebug("Delete Button Pressed");

    ponto.pop_back();
    ponto2.pop_back();
}

void Canvas2D::keyPressEvent(QKeyEvent* event){
      qDebug("\nKeyboard Press: %d", event->key());
      mw->list->addItem("Keyboard Press Event");
      switch(event->key()){
        case Qt::Key_Right:
            r = 1;
            break;
        case Qt::Key_Left:
            l = 1;
            break;
        case Qt::Key_Up:
            up = 1;
            break;
        case Qt::Key_Down:
            down = 1;
            break;
        }
}

void Canvas2D::keyReleaseEvent(QKeyEvent* event){
    qDebug("\nKeyboard Release: %c", event->key());

    switch(event->key()){
        case Qt::Key_Right:
            r = 0;
            break;
          case Qt::Key_Left:
            l = 0;
            break;
          case Qt::Key_Up:
            up = 0;
            break;
          case Qt::Key_Down:
            down = 0;
            break;
     }
}

