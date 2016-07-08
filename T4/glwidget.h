#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_1_1>
#include "mainwindow.h"

class MainWindow;

class GLWidget : public QOpenGLWidget, public QOpenGLFunctions_1_1{
    Q_OBJECT

private:
    MainWindow *mw;

protected:
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void initializeGL() Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent  *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent * event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent* event);

public:
    GLWidget(MainWindow *mw);
    void keyboard(QKeyEvent *event);
};

#endif // GLWIDGET_H
