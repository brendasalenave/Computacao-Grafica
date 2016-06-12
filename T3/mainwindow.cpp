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
#include <QGridLayout>
#include <QRadioButton>
#include <QVBoxLayout>

#include "glwidget.h"

MainWindow::MainWindow(){
    //****************************************************
    //cria os Widgets
    //****************************************************

    Canvas2D *canvas = new Canvas2D(this);
    canvas->setMinimumHeight(600);
    canvas->setMaximumHeight(600);

    QLabel *label = new QLabel(this);
    label->setText("A scrollable QOpenGLWidget");
    label->setAlignment(Qt::AlignHCenter);

    list = new QListWidget(this);
    list->setMaximumWidth(170);

    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 50);
    slider->setSliderPosition(30);

    refreshRate = new QSpinBox(this);
    refreshRate->setSuffix(" ms");
    refreshRate->setValue(10);
    refreshRate->setSingleStep(10);
    refreshRate->setToolTip("Dica do que o componente faz");

    QCheckBox *timerBased = new QCheckBox("Use timer", this);
    timerBased->setChecked(true);
    timerBased->setToolTip("Toggles using a timer to trigger update()");

    //QPushButton *button1 = new QPushButton("Button 1 - Status Bar");
    QPushButton *button2 = new QPushButton("Limpar");
    QPushButton *button3 = new QPushButton("Sweep");
    button2->setStyleSheet("background-color: red;");
    button3->setStyleSheet("background-color: green;");

    QFont f( "Tahoma", 10, QFont::Bold);
    QFont f1( "Tahoma", 10);
    f1.setItalic(true);

    QRadioButton *radioB1 = new QRadioButton("Perspectiva");
    radioB1->setToolTip("Projeção em perpectiva do objeto");
    QRadioButton *radioB2 = new QRadioButton("Ortográfica");
    radioB2->setToolTip("Projeção ortográfica do objeto");
    radioB1->setChecked(true);

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
    updateGroupBox->setTitle("QGroupBox Horizontal");

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(radioB1);
    verticalLayout->addWidget(radioB2);

    QGroupBox *radioGroupBox = new QGroupBox(this);
    radioGroupBox->setLayout(verticalLayout);
    radioGroupBox->setTitle("            PROJEÇÃO");
    radioGroupBox->setFont(f);
    radioGroupBox->setMinimumWidth(170);
    radioGroupBox->setMaximumWidth(170);
    radioGroupBox->setFixedHeight(140);

    QGridLayout *gridLayout = new QGridLayout;// Pozzer: aqui estava QGridLayout(groupBox);
    gridLayout->addWidget(canvas,       0, 0, 3, 1);
    gridLayout->addWidget(radioGroupBox, 2, 1, 1, 1);
    gridLayout->addWidget(button2,      1, 1, 1, 1);
    gridLayout->addWidget(button3,      0, 1, 1, 1);
    //gridLayout->addWidget(list,       3, 1, 1, 1);
    gridLayout->addWidget(updateGroupBox, 3, 0, 1, 2); //row, column, rowSpan, colSpan
    gridLayout->addWidget(slider,         4, 0, 1, 1);

    QGroupBox * groupBox = new QGroupBox(this);
    groupBox->setLayout(gridLayout);
    //groupBox->setTitle("QGroupBox Grid");
    setCentralWidget(groupBox);

    //QScrollArea *scrollArea = new QScrollArea;
    //scrollArea->setWidget(canvas);
    //gridLayout->addWidget(scrollArea,1,0,8,1);

    menuBar()->setFont(f1);
    menuBar()->setStyleSheet("background-color: green;");
    QMenu *fileMenu = menuBar()->addMenu("&Arquivo");
    QMenu *showMenu = menuBar()->addMenu("&Ajuda");
    //statusBar()->addWidget(button1);

    QAction *actExit        = new QAction("E&xit", fileMenu);
    QAction *actShowMsgGL   = new QAction("Show Msg na Canvas", showMenu);
    QAction *actShowMsgThis = new QAction("Pontos", showMenu);
    QAction *aboutMenu = new QAction("Sobre", showMenu);


    fileMenu->addAction(actExit);
    showMenu->addAction(actShowMsgGL);
    showMenu->addAction(actShowMsgThis);
    showMenu->addAction(aboutMenu);


    //o timer eh usado para controlar o refresh de tela, via SLOT(update()) abaixo. Ele nao faz controle de FPS
    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    m_timer->start();


    //tratamento de eventos de menu, checkbox, timer, botao, slider e QSpinBox (e etc)
    connect(m_timer,        SIGNAL(timeout()),         canvas, SLOT(update()));
    connect(actExit,        SIGNAL(triggered(bool)),   this,   SLOT(close())   );
    connect(actShowMsgGL,   SIGNAL(triggered(bool)),   canvas, SLOT(showMsg()) );
    connect(actShowMsgThis, SIGNAL(triggered(bool)),   this,   SLOT(showMsg()) );
    connect(aboutMenu, SIGNAL(triggered(bool)),   this,   SLOT(showMsg2()) );
    connect(button3, SIGNAL(clicked()), canvas, SLOT(buttonPressed()));
    connect(button2, SIGNAL(clicked()), canvas, SLOT(button2Pressed()));
    //connect(button1,        SIGNAL(released()) ,       canvas, SLOT(showMsg()) );
    connect(refreshRate,    SIGNAL(valueChanged(int)), this,   SLOT(updateIntervalChanged(int)) );
    connect(slider,         SIGNAL(valueChanged(int)), this,   SLOT(sliderChanged(int)) );
    connect(timerBased,     SIGNAL(clicked(bool)),     this,   SLOT(checkBoxChanged(bool)));
}

void MainWindow::checkBoxChanged(bool enabled)
{
    qDebug("Checkbox: %d", enabled );
    if (enabled) {
        m_timer->start();
    } else {
        m_timer->stop();
    }
    refreshRate->setEnabled(enabled);
}

void MainWindow::sliderChanged(int i){
    qDebug("Slider: %d", i );
}


void MainWindow::showMsg(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setWindowTitle("Pontos");
    msg->setText("Movimentação dos pontos:\n• Para criação dos pontos basta clicar na àrea de desenho utilizando"
                 " o botão direito do mouse"
                 "\n\n• Para movimentação dos pontos já existentes clique sobre o ponto que deseja mover utilizando"
                 " o botão esquerdo do mouse");
    msg->show();
}

void MainWindow::showMsg2(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setWindowTitle("Sobre");
    msg->setText("Programa implementado em C++ para fazer a modelagem e visualização"
                 " de um objeto 3D, representado por meio de sweep, utilizando uma câmera sintética."
                 " A visualização pode ser feita por meio de projeção em perspectiva ou ortográfica"
                 "\n\nBrenda Salenave Santana\nbsantana@inf.ufsm.br");
    msg->show();
}

void MainWindow::updateIntervalChanged(int value){
    m_timer->setInterval(value);
    if (m_timer->isActive())
        m_timer->start();
}

void MainWindow::resizeEvent(QResizeEvent *e){
     qDebug("janela redimensionada" );
}
