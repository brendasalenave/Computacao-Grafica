#include <QGridLayout>
#include <QGroupBox>

#include "mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    // Seta o titulo da janela
    this->setWindowTitle("T4");

    // Cria os Widgets da tela
    this->glwidget = new GLWidget(this);

    // Cria o layout da tela
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(glwidget, 0, 0, 0, 0);

    QGroupBox *groupbox = new QGroupBox();
    groupbox->setLayout(gridLayout);
    this->setCentralWidget(groupbox);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    this->glwidget->keyboard(event);
}

MainWindow::~MainWindow(){ }
