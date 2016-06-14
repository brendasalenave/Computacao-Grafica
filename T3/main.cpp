/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

#include <QApplication>
#include <QMainWindow>
#include "mainwindow.h"

//Baseado no demo C:\Qt\Qt5.5.1\Examples\Qt-5.5\opengl\qopenglwidget

int main( int argc, char ** argv ){
    QApplication a( argc, argv );

    MainWindow mw;
    mw.setWindowTitle("Computação Gráfica: trabalho 3");
    mw.setMinimumSize(600,800);
    mw.setMinimumWidth(1200);
    mw.resize(800,600);

    mw.show();

    return a.exec();
}
