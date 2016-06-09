QT += widgets

SOURCES += main.cpp \
           mainwindow.cpp \
           glCanvas2d.cpp \
           glWidget.cpp \
           pontos.cpp \
           sweep.cpp

HEADERS += \
           mainwindow.h \
           glwidget.h \
           pontos.h \
           sweep.h

target.path = $$[QT_INSTALL_EXAMPLES]/opengl/qopenglwidget

INSTALLS += target

RESOURCES += rsc.qrc

win32: LIBS += -lopengl32

win32: LIBS += -lglu32
