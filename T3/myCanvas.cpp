
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

    for(int u = 0; u < (int)tam; u ++){
        if(v == u){
            movimenta(u);
            break;
        }
    }

    color(0.9,0.9,0.8);
    glLineWidth(3.0);
    int cWidth = (mw->width() / 2) - 100;
    line(cWidth, 0, cWidth, 600);
    glLineWidth(1.0);

    int oldX = 0, oldY = 0;

    for(int u = 0; u < (int)tam ; u++){
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

    ponto2 = ponto;
    ponto2 = t->cria(ponto2,tam,c);

    int x = (cWidth + (cWidth /4)) + 30;
    int y = 200;
    std::vector<Ponto>::size_type tam2 = ponto2.size();
    oldX = 0, oldY = 0;
    for(int u = 0; u < (int)tam2 ; u++){
        if((u+20) < (int)tam2){
            line(ponto2[u+20].getX()+x, ponto2[u+20].getY()+y, ponto2[u].getX()+x, ponto2[u].getY()+y);
        }

        if(((u + 1) < (int)tam2)){ // && ((u%20) != 0)
            line(ponto2[u+1].getX()+x, ponto2[u+1].getY()+y, ponto2[u].getX()+x, ponto2[u].getY()+y);
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

    int cWidth = (mw->width() / 2) - 100;

    if((f==1) && (event->x() > 5) && (event->x() < cWidth-5) && (mouse_y > 15) && (mouse_y < 590)){
        Ponto p;
        p.setX(event->x());
        p.setY(mouse_y);
        ponto.push_back(p);
    }
    if(!f){
        for(int u = 0; u < (int)ponto.size(); u++){
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

void Canvas2D::radioCheck(bool enabled){
    if(enabled == true)
        c = 1;
}

void Canvas2D::radioCheck2(bool enabled){
    if(enabled == true)
        c = 0;
}

void Canvas2D::button2Pressed(){
    qDebug("Clean Button Pressed");

    std::vector<Ponto>::size_type tam = ponto.size();
    for(int u = 0; u < (int)tam ; u++){
        ponto.pop_back();
    }
    std::vector<Ponto>::size_type tam2 = ponto2.size();
    for(int u = 0; u < (int)tam2 ; u++){
        ponto2.pop_back();
    }
}

void Canvas2D::button1Pressed(){
    qDebug("Delete Button Pressed");

    ponto.pop_back();
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

