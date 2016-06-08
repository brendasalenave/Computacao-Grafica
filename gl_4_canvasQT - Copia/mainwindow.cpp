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
#include <QRadioButton>
#include <QVBoxLayout>

#include "glwidget.h"

MainWindow::MainWindow(){

    //****************************************************
    //cria os Widgets
    //****************************************************

    GLWidget *glwidget = new GLWidget(this);
    m_glWidget = glwidget;
    m_glWidget->setMinimumHeight(600);
    m_glWidget->setMaximumHeight(600);

    QFont f( "Tahoma", 10, QFont::Bold);
    QFont f1( "Tahoma", 10);
    f1.setItalic(true);

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

    QCheckBox *timerBased = new QCheckBox("Timer", this);
    timerBased->setChecked(true);
    timerBased->setToolTip("Toggles using a timer to trigger update()");

    //QPushButton *button1 = new QPushButton("Button 1 - Status Bar");
    //QPushButton *button2 = new QPushButton("Button 2 - Dummy");
    QPushButton *button3 = new QPushButton("Button 3 - Dummy");
    button3->setStyleSheet("background-color: green;");

    QRadioButton *radioB1 = new QRadioButton("Copo");
    QRadioButton *radioB2 = new QRadioButton("Vaso");
    QRadioButton *radioB3 = new QRadioButton("Personalizado");

    QRadioButton *button_r1 = new QRadioButton("Perspectiva");
    button_r1->setToolTip("Projeção em perpectiva do objeto");
    QRadioButton *button_r2 = new QRadioButton("Ortográfica");
    button_r2->setToolTip("Projeção ortográfica do objeto");


    QLabel *updateLabel = new QLabel("Tempo de Espera entre updates");

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
    verticalLayout->addWidget(radioB3);

    QGroupBox *radioGroupBox = new QGroupBox(this);
    radioGroupBox->setLayout(verticalLayout);
    radioGroupBox->setTitle("     FORMAS");
    radioGroupBox->setFont(f);

    radioB3->setChecked(true);

    QVBoxLayout *verticalLayout2 = new QVBoxLayout;
    verticalLayout2->addWidget(button_r1);
    verticalLayout2->addWidget(button_r2);

    QGroupBox *radioGroupBox2 = new QGroupBox(this);
    radioGroupBox2->setLayout(verticalLayout2);
    radioGroupBox2->setTitle("  PROJEÇÃO");
    radioGroupBox2->setFont(f);

    button_r1->setChecked(true);

    QGridLayout *gridLayout = new QGridLayout;// Pozzer: aqui estava QGridLayout(groupBox);
    gridLayout->addWidget(glwidget,       0, 0, 3, 1);
    //gridLayout->addWidget(button2,        0, 1, 1, 1);
    gridLayout->addWidget(radioGroupBox,  0, 1, 1, 1);
    gridLayout->addWidget(radioGroupBox2,  1, 1, 1, 1);
    gridLayout->addWidget(button3,        2, 1, 1, 1);
    gridLayout->addWidget(updateGroupBox, 5, 0, 1, 2); //row, column, rowSpan, colSpan
    gridLayout->addWidget(slider,         4, 0, 1, 1);

    QGroupBox * groupBox = new QGroupBox(this);
    groupBox->setLayout(gridLayout);
    //groupBox->setTitle("QGroupBox Grid");
    setCentralWidget(groupBox);


    //QScrollArea *scrollArea = new QScrollArea;
    //scrollArea->setWidget(glwidget);
    //gridLayout->addWidget(scrollArea,1,0,8,1);
    menuBar()->setFont(f1);
    menuBar()->setStyleSheet("background-color: green;");
    QMenu *fileMenu = menuBar()->addMenu("&File");
    QMenu *showMenu = menuBar()->addMenu("&Infomações");
    //statusBar()->addWidget(button1);

    QAction *actExit        = new QAction("E&xit", fileMenu);
    QAction *actShowMsgGL   = new QAction("Show Msg na GLWidget", showMenu);
    QAction *actShowMsgThis = new QAction("Show Msg na MainWindow", showMenu);

    fileMenu->addAction(actExit);
    showMenu->addAction(actShowMsgGL);
    showMenu->addAction(actShowMsgThis);


    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    m_timer->start();

    connect(m_timer, SIGNAL(timeout()), glwidget, SLOT(update()));

    //tratamento de eventos de menu, botao e QSpinBox
    connect(actExit,        SIGNAL(triggered(bool)),   this,     SLOT(close())   );
    connect(actShowMsgGL,   SIGNAL(triggered(bool)),   glwidget, SLOT(showMsg()) );
    connect(actShowMsgThis, SIGNAL(triggered(bool)),   this,     SLOT(showMsg()) );
    //connect(button1,        SIGNAL(released()) ,       glwidget, SLOT(showMsg()) );
    connect(refreshRate,    SIGNAL(valueChanged(int)), this,     SLOT(updateIntervalChanged(int)) );

    //tratamento de checkbox
    connect(timerBased,  &QCheckBox::toggled, this,        &MainWindow::timerUsageChanged);
    connect(timerBased,  &QCheckBox::toggled, refreshRate, &QWidget::setEnabled);


}

void MainWindow::showMsg(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Movimentação dos pontos: ");
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
