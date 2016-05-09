/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

//Baseado no demo C:\Qt\Qt5.5.1\Examples\Qt-5.5\opengl\qopenglwidget

#include "mainwindow.h"

#include <QApplication>
#include <QMenuBar>
#include <QStatusBar>
#include <QGroupBox>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QScrollArea>
#include <QMessageBox>
#include <QResizeEvent>
#include <QListWidget>

#include "glwidget.h"

MainWindow::MainWindow(){
    //****************************************************
    //cria os Widgets
    //****************************************************

    GLWidget *glwidget = new GLWidget(this);
    m_glWidget = glwidget;

    QLabel *label = new QLabel(this);
    label->setText("A scrollable QOpenGLWidget");
    label->setAlignment(Qt::AlignHCenter);

    list = new QListWidget(this);
    list->setMaximumWidth(170);

    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 50);
    slider->setSliderPosition(30);

    QSpinBox *refreshRate = new QSpinBox(this);
    refreshRate->setSuffix(" ms");
    refreshRate->setValue(10);
    refreshRate->setSingleStep(10);
    refreshRate->setToolTip("Dica do que o componente faz");

    QCheckBox *timerBased = new QCheckBox("Use timer", this);
    timerBased->setChecked(true);
    timerBased->setToolTip("Toggles using a timer to trigger update()");

    //QPushButton *button1 = new QPushButton("Button 1 - Status Bar");
    QPushButton *button2 = new QPushButton("Visualizar comandos");

    QLabel *updateLabel = new QLabel("Tempo de Espera entre updates da Canvas");

    //****************************************************
    //cria os Layouts
    //****************************************************

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(updateLabel);
    horizontalLayout->addWidget(refreshRate);
    horizontalLayout->addWidget(timerBased);
    //horizontalLayout->addWidget(button1);

    QGroupBox *updateGroupBox = new QGroupBox(this);
    updateGroupBox->setLayout(horizontalLayout);
    //updateGroupBox->setTitle("QGroupBox Horizontal");


    QGridLayout *gridLayout = new QGridLayout;// Pozzer: aqui estava QGridLayout(groupBox);
    gridLayout->addWidget(glwidget,       0, 0, 3, 1);
    gridLayout->addWidget(button2,        0, 1, 1, 1);
    gridLayout->addWidget(list,           1, 1, 1, 1);
    gridLayout->addWidget(updateGroupBox, 3, 0, 1, 2); //row, column, rowSpan, colSpan
    gridLayout->addWidget(slider,         4, 0, 1, 1);

    QGroupBox * groupBox = new QGroupBox(this);
    groupBox->setLayout(gridLayout);
    groupBox->setTitle("PARA INICIAR O JOGO CLIQUE NA TELA!!");
    setCentralWidget(groupBox);


    //QScrollArea *scrollArea = new QScrollArea;
    //scrollArea->setWidget(glwidget);
    //gridLayout->addWidget(scrollArea,1,0,8,1);

    QMenu *fileMenu = menuBar()->addMenu("&File");
    QMenu *showMenu = menuBar()->addMenu("&Info");
    //statusBar()->addWidget(button1);

    QAction *actExit        = new QAction("E&xit", fileMenu);
    QAction *actShowMsgGL   = new QAction("Comandos", showMenu);
    //QAction *actShowMsgThis = new QAction("Show Msg na MainWindow", showMenu);

    fileMenu->addAction(actExit);
    showMenu->addAction(actShowMsgGL);
    //showMenu->addAction(actShowMsgThis);


    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    m_timer->start();

    connect(m_timer, SIGNAL(timeout()), glwidget, SLOT(update()));

    //tratamento de eventos de menu, botao e QSpinBox
    connect(actExit,        SIGNAL(triggered(bool)),   this,     SLOT(close())   );
    connect(actShowMsgGL,   SIGNAL(triggered(bool)),   glwidget, SLOT(showMsg()) );
    //connect(actShowMsgThis, SIGNAL(triggered(bool)),   this,     SLOT(showMsg()) );
    connect(button2,        SIGNAL(released()) ,       glwidget, SLOT(showMsg()) );
    connect(refreshRate,    SIGNAL(valueChanged(int)), this,     SLOT(updateIntervalChanged(int)) );

    //tratamento de checkbox
    connect(timerBased,  &QCheckBox::toggled, this,        &MainWindow::timerUsageChanged);
    connect(timerBased,  &QCheckBox::toggled, refreshRate, &QWidget::setEnabled);
}

void MainWindow::showMsg(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Msg MainWindow\n Metodo showMsg()");
    msg->show();
}

void MainWindow::updateIntervalChanged(int value){
    m_timer->setInterval(value);
    if (m_timer->isActive())
        m_timer->start();
}

void MainWindow::timerUsageChanged(bool enabled){
    if (enabled) {
        m_timer->start();
    } else {
        m_timer->stop();
        m_glWidget->update();
    }
}

void MainWindow::resizeEvent(QResizeEvent *e){
    printf("\nJanela redimensionada %d %d",e->size().height(), e->size().width() );
}
