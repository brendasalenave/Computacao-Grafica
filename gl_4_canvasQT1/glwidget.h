/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QPushButton>
#include <QOpenGLFunctions_1_1>

#include <QKeyEvent>


class MainWindow;

class GLWidget : public QOpenGLWidget, public QOpenGLFunctions_1_1
{
    Q_OBJECT
private:
    MainWindow *mw;
public:
    GLWidget(MainWindow *mw);
    ~GLWidget();

//Callbacks de Widgets
public slots:
    void showMsg(); //metodo chamado quando o botao eh pressionado

protected:
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void initializeGL() Q_DECL_OVERRIDE;

    //mouse functions
    void mousePressEvent(QMouseEvent  *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    //keyboard functions
    void keyPressEvent(QKeyEvent* event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent* event);



    //Canvas2D functions
    //************************************************************************
    void point(int x, int y); //coordeandas do ponto
    void line( int x1, int y1, int x2, int y2 ); //coordenadas da linha x1, y1, x2, y2

    //desenha um retangulo alinhado nos eixos x e y
    void rect( int x1, int y1, int x2, int y2 ); //coordenadas do retangulo x1, y1, x2, y2
    void rectFill( int x1, int y1, int x2, int y2 ); //coordenadas do retangulo x1, y1, x2, y2

    //desenha um poligono CONVEXO. Para um retangulo, deve-se passar 4 vertices
    void polygon(float vx[], float vy[], int n_elems);
    void polygonFill(float vx[], float vy[], int n_elems);

    //centro e raio do circulo
    void circle( int x, int y, int raio, int div );
    void circleFill( int x, int y, int raio, int div );

    //especifica a cor de desenho e de limpeza de tela
    void color(float r, float g, float b);
    void clear(float r, float g, float b);

    //desenha texto
    void text(int x, int y, const char *t);

    //Draw functions
    void drawNave(float vecx[3], float vecy[3]);
    void drawTiro();
};

#endif
