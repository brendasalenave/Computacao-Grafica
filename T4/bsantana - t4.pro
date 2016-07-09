#-------------------------------------------------
#
# Project created by QtCreator 2016-07-03T11:52:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mdonato
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    draw.cpp \
    cube.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    draw.h \
    cube.h


unix|win32: LIBS += -lfreeglut

unix|win32: LIBS += -lglfw3

unix|win32: LIBS += -lglu32

unix|win32: LIBS += -lopengl32

