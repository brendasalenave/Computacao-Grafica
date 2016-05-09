QT += widgets
QT += multimedia

SOURCES += main.cpp \
           mainwindow.cpp \
           glCanvas2d.cpp \
           glWidget.cpp \
           nave.cpp \
           transformacoes.cpp \
    tiro.cpp \
    desenho.cpp

HEADERS += \
           mainwindow.h \
           glwidget.h \
           nave.h \
           transformacoes.h \
    tiro.h

target.path = $$[QT_INSTALL_EXAMPLES]/opengl/qopenglwidget

INSTALLS += target

RESOURCES += \
    rcc.qrc
