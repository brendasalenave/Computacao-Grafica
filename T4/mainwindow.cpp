#include <QGridLayout>
#include <QGroupBox>
#include <QMenuBar>
#include <QMessageBox>


#include "mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    // Seta o titulo da janela
    this->setWindowTitle("T4 - DRAGA");

    // Cria os Widgets da tela
    this->glwidget = new GLWidget(this);

    QMenu *fileMenu = menuBar()->addMenu("&Arquivo");
    QAction *actShowMsg = new QAction("Comandos", fileMenu);
    QAction *actExit        = new QAction("Sair", fileMenu);
    fileMenu->addAction(actShowMsg);
    fileMenu->addAction(actExit);

    // Cria o layout da tela
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(glwidget, 0, 0, 0, 0);

    QGroupBox *groupbox = new QGroupBox();
    groupbox->setLayout(gridLayout);
    this->setCentralWidget(groupbox);

    connect(actShowMsg, SIGNAL(triggered(bool)),   this,   SLOT(showMsg()));
    connect(actExit,SIGNAL(triggered(bool)),   this,   SLOT(close()));

}

void MainWindow::showMsg(){
    QMessageBox* msg = new QMessageBox(this);
    msg->setWindowTitle("Draga: Comandos");
    msg->setText("Espaço: Muda o modo de visualização"
                 "\nW: aumenta ângulo da concha"
                 "\nS: diminui ângulo da concha"
                 "\nD: aumenta o tamanho do segundo braço"
                 "\nA: diminui o tamanho do segundo braço"
                 "\nDireita(→): aumenta tamanho do terceiro braço"
                 "\nEsquerda(←): diminui tamanho do terceiro braço"
                 "\nBotão direito mouse: aumenta ângulo de rotação da parte superior em relação a base"
                 "\nBotão esquerdo mouse: diminui ângulo de rotação da parte superior em relação a base");
    msg->show();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    this->glwidget->keyboard(event);
}

MainWindow::~MainWindow(){ }
