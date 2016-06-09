/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGridLayout>
#include <QListWidget>


QT_FORWARD_DECLARE_CLASS(QOpenGLWidget)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    bool timerEnabled() const { return m_timer->isActive(); }
    void resizeEvent(QResizeEvent *);

    QListWidget *list;
    QOpenGLWidget *m_glWidget;

//Callbacks de Widgets
private slots:
    void updateIntervalChanged(int value);
    void timerUsageChanged(bool enabled);
    void showMsg();
    void showMsg2();

private:
    QTimer *m_timer;
};

#endif
