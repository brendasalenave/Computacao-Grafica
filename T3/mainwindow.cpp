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
#include <QKeyEvent>

#include "glwidget.h"


MainWindow::MainWindow(){
    //****************************************************
    //cria os Widgets
    //****************************************************

    Canvas2D *canvas = new Canvas2D(this);
    canvas->setMinimumHeight(600);
    canvas->setMaximumHeight(600);
    canvas->setMinimumWidth(1000);

    canvas->setFocusPolicy(Qt::StrongFocus);


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

    QPushButton *button1 = new QPushButton("Delete");
    QPushButton *button2 = new QPushButton("Limpar");
    button1->setStyleSheet("background-color: red;");
    button2->setStyleSheet("background-color: blue;");
    button1->setMinimumHeight(15);
    button2->setMinimumHeight(15);
    button1->setToolTip("Deleta último ponto adicionado");
    button2->setToolTip("Remove todos os pontos");

    //radioGroupBox->setMinimumWidth(170);

    QFont f( "Tahoma", 10, QFont::Bold);
    QFont f1( "Tahoma", 10);
    f1.setItalic(true);

    QRadioButton *radioB1 = new QRadioButton("Perspectiva");
    radioB1->setToolTip("Projeção em perpectiva do objeto");
    QRadioButton *radioB2 = new QRadioButton("Ortográfica");
    radioB2->setToolTip("Projeção ortográfica do objeto");
    radioB1->setChecked(true);
    radioB1->setMinimumHeight(15);
    radioB2->setMinimumHeight(15);

    QRadioButton *radioB3 = new QRadioButton("Eixo X");
    radioB1->setToolTip("Rotaciona o objeto no eixo X");
    QRadioButton *radioB4 = new QRadioButton("Eixo Y");
    radioB2->setToolTip("Rotaciona o objeto no eixo Y");
    QRadioButton *radioB5 = new QRadioButton("Nenhum");
    radioB5->setToolTip("Objeto estático");
    radioB5->setChecked(true);


    QLabel *updateLabel = new QLabel("Tempo de Espera entre updates da Canvas");

    //****************************************************
    //cria os Layouts
    //****************************************************

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(updateLabel);
    horizontalLayout->addWidget(refreshRate);
    horizontalLayout->addWidget(timerBased);

    QGroupBox *updateGroupBox = new QGroupBox(this);
    updateGroupBox->setLayout(horizontalLayout);
    //updateGroupBox->setTitle("QGroupBox Horizontal");

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(radioB1);
    verticalLayout->addWidget(radioB2);
    verticalLayout->setSpacing(2);

    QVBoxLayout *verticalLayout2 = new QVBoxLayout;
    verticalLayout2->addWidget(radioB5);
    verticalLayout2->addWidget(radioB3);
    verticalLayout2->addWidget(radioB4);
    verticalLayout2->setSpacing(2);

    QVBoxLayout *verticalLayout3 = new QVBoxLayout;
    verticalLayout3->addWidget(button1);
    verticalLayout3->addWidget(button2);
    verticalLayout3->setSpacing(2);

    QGroupBox *radioGroupBox = new QGroupBox(this);
    radioGroupBox->setLayout(verticalLayout);
    radioGroupBox->setTitle("            PROJEÇÃO");
    radioGroupBox->setFont(f);
    radioGroupBox->setMinimumWidth(170);
    radioGroupBox->setMaximumWidth(170);
    radioGroupBox->setFixedHeight(140);

    QGroupBox *radioGroupBox2 = new QGroupBox(this);
    radioGroupBox2->setLayout(verticalLayout2);
    radioGroupBox2->setTitle("            ROTAÇÃO");
    radioGroupBox2->setFont(f);
    radioGroupBox2->setMinimumWidth(170);
    radioGroupBox2->setMaximumWidth(170);
    radioGroupBox2->setFixedHeight(140);

    QGroupBox *radioGroupBox3 = new QGroupBox(this);
    radioGroupBox3->setLayout(verticalLayout3);
    radioGroupBox3->setFont(f);
    radioGroupBox3->setMinimumWidth(170);
    radioGroupBox3->setMaximumWidth(170);
    radioGroupBox3->setFixedHeight(140);


    QGridLayout *gridLayout = new QGridLayout;// Pozzer: aqui estava QGridLayout(groupBox);
    gridLayout->addWidget(canvas,       0, 0, 3, 1);
    gridLayout->addWidget(radioGroupBox, 0, 1, 1, 1);
    gridLayout->addWidget(radioGroupBox2, 1, 1, 1, 1);
    gridLayout->addWidget(radioGroupBox3, 2, 1, 1, 1);
    gridLayout->addWidget(updateGroupBox, 3, 0, 1, 2); //row, column, rowSpan, colSpan
    gridLayout->addWidget(slider,         4, 0, 1, 1);

    QGroupBox * groupBox = new QGroupBox(this);
    groupBox->setLayout(gridLayout);
    setCentralWidget(groupBox);

    menuBar()->setFont(f1);
    menuBar()->setStyleSheet("background-color: green;");
    QMenu *fileMenu = menuBar()->addMenu("&Arquivo");
    QMenu *showMenu = menuBar()->addMenu("&Ajuda");

    QAction *actExit        = new QAction("E&xit", fileMenu);
    QAction *actShowMsgThis = new QAction("Pontos", showMenu);
    QAction *aboutMenu = new QAction("Sobre", showMenu);


    fileMenu->addAction(actExit);
    showMenu->addAction(actShowMsgThis);
    showMenu->addAction(aboutMenu);


    //o timer eh usado para controlar o refresh de tela, via SLOT(update()) abaixo. Ele nao faz controle de FPS
    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    m_timer->start();


    //tratamento de eventos de menu, checkbox, timer, botao, slider e QSpinBox (e etc)
    connect(m_timer,        SIGNAL(timeout()),         canvas, SLOT(update()));
    connect(actExit,        SIGNAL(triggered(bool)),   this,   SLOT(close())   );
    connect(actShowMsgThis, SIGNAL(triggered(bool)),   this,   SLOT(showMsg()) );
    connect(aboutMenu, SIGNAL(triggered(bool)),   this,   SLOT(showMsg2()) );
    connect(button2, SIGNAL(clicked()), canvas, SLOT(button2Pressed()));
    connect(button1,        SIGNAL(released()) ,       canvas, SLOT(button1Pressed()) );
    connect(refreshRate,    SIGNAL(valueChanged(int)), this,   SLOT(updateIntervalChanged(int)) );
    connect(slider,         SIGNAL(valueChanged(int)), this,   SLOT(sliderChanged(int)) );
    connect(radioB1,         SIGNAL(toggled(bool)), canvas,   SLOT(radioCheck(bool)) );
    connect(radioB3,         SIGNAL(toggled(bool)), canvas,   SLOT(radioCheck3(bool)) );
    connect(radioB4,         SIGNAL(toggled(bool)), canvas,   SLOT(radioCheck4(bool)) );
    connect(radioB5,         SIGNAL(toggled(bool)), canvas,   SLOT(radioCheck2(bool)) );
    connect(timerBased,     SIGNAL(clicked(bool)),     this,   SLOT(checkBoxChanged(bool)));
}

void MainWindow::checkBoxChanged(bool enabled){
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
    msg->setText("• Para movimentação dos pontos já existentes clique sobre o ponto que deseja mover utilizando"
                 " o botão direito do mouse");
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
