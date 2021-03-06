
// *********************************************************************
// Canvas para desenho - Versao C baseado nos demos de Computação Gráfica (Pozzer).
//  Autora: Brenda Salenave Santana
//         07/2016
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Tem tratamento de mosue
// *
// *   bsantana@inf.ufsm.br
// *
//

#include "glCanvas2d.h"
#include "mainwindow.h"
#include "ponto.h"
#include "transformacoes.h"

#include <math.h>
#include <time.h>
#include <QMessageBox>
#include <QWheelEvent>
#include <QLabel>
//#include <QMediaPlayer>
#include <QSound>
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
int rot;


// *******************************************************************************
//Coloque seu codigo aqui, usando as funcoes da Canvas2D defindas na classe glWidgets.
// *******************************************************************************
void Canvas2D::paintGL(){
    QLabel *label = new QLabel(this);
    label->setText("Área para Desenho");
    label->setAlignment(Qt::AlignHCenter);
    label->setGeometry(QRect(150, 0, 100, 15));


    srand( (unsigned)time(NULL) );

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
    int cWidth = (mw->width() / 2) - 150;
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
        //point(ponto[u].getX(), ponto[u].getY());
        rectFill(ponto[u].getX()-2, ponto[u].getY()-2, ponto[u].getX()+2, ponto[u].getY()+2);

        oldX = ponto[u].getX();
        oldY = ponto[u].getY();
    }

    ponto2 = ponto;
    ponto2 = t->cria(ponto2,tam,c,rot);

    int x, y;
    if(rot == 0){
        x = (cWidth + (cWidth /4)) + 30;
        y = 200;
    }else if(rot == 1){
        x = (cWidth + (cWidth /4)) + 100;
        y = 300;
    }else{
        x = (cWidth + (cWidth /4)) + 200;
        y = 200;
    }

    /* Linhas dos eixos */
    line(cWidth+10, 5, cWidth + 10, 25);
    line(cWidth+10, 5, cWidth + 30, 5);
    line(cWidth+10, 5, cWidth + 30, 20);

    std::vector<Ponto>::size_type tam2 = ponto2.size();
    oldX = 0, oldY = 0;

    float r = 1+(rand() % 101);
    r = r/100;
    float b = 1+(rand() % 101);
    b = b/100;

    color(r,1,b);
    for(int u = 0; u < (int)tam2 ; u++){
        if((u+20) < (int)tam2){
            line(ponto2[u+20].getX()+x, ponto2[u+20].getY()+y, ponto2[u].getX()+x, ponto2[u].getY()+y);
        }

        if(((u + 1) < (int)tam2)&& ((u%20) != 0)){
            line(ponto2[u+1].getX()+x, ponto2[u+1].getY()+y, ponto2[u].getX()+x, ponto2[u].getY()+y);
        }
     }

}

void Canvas2D::movimenta(int u){
    if((ponto[u].getY() > 15) && (down == 1)){
        ponto[u].setY(ponto[u].getY() - 2);
    }
    if(ponto[u].getY() < 590 && up == 1){
        ponto[u].setY(ponto[u].getY() + 2);
    }
    if(ponto[u].getX() > 15 && l == 1){
        ponto[u].setX(ponto[u].getX() - 2);
    }
    int cWidth = ((mw->width() / 2) - 100) - 5;
    if(ponto[u].getX() < cWidth && r == 1){
        ponto[u].setX(ponto[u].getX() + 2);
    }
}

void Canvas2D::wheelEvent(QWheelEvent *event){
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

    int cWidth = (mw->width() / 2) - 150;


    if((f==1) && (event->x() > 5) && (event->x() < cWidth-5) && (mouse_y > 15) && (mouse_y < 585)){
        Ponto p;
        int f1 = 0;
        int u;
        for(int i = 0; i < (int)ponto.size(); i++){
            if((event->x() > ponto[i].getX() -2) && (event->x() < ponto[i].getX() +2) &&
               (mouse_y > ponto[i].getY() -2) && (mouse_y > ponto[i].getY() -2)){
                f1 = 1;
                u = i;
                break;
            }
        }
        if(f1 == 0){
            QSound::play(":/sounds/blup.wav");
            p.setX(event->x());
            p.setY(mouse_y);
            ponto.push_back(p);

        }else if(f1 == 1){
            v = u;
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
    else c = 0;
}

void Canvas2D::radioCheck2(bool enabled){
    if(enabled == true)
        rot = 0;
}

void Canvas2D::radioCheck3(bool enabled){
    if(enabled == true)
        rot = 1;
}

void Canvas2D::radioCheck4(bool enabled){
    if(enabled == true)
        rot = 2;
}

void Canvas2D::button2Pressed(){
    qDebug("Clean Button Pressed");

    QSound::play(":/sounds/clean.wav");

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
    QSound::play(":/sounds/pop.wav");

    std::vector<Ponto>::size_type tam = ponto.size();
    if((int)tam != 0)
        ponto.pop_back();
}

void Canvas2D::keyPressEvent(QKeyEvent* event){
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
        case Qt::Key_S:
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

