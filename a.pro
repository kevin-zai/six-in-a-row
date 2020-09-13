#-------------------------------------------------
#
# Project created by QtCreator 2020-09-12T10:08:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = a
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG+=C++11

SOURCES += \
        main.cpp \
        widget.cpp \
    mo.cpp \
    qi.cpp \
    fault.cpp \
    jie.cpp \
    qi2.cpp

HEADERS += \
        widget.h \
    mo.h \
    qi.h \
    fault.h \
    jie.h \
    qi2.h

RESOURCES += \
    image.qrc

DISTFILES += \
    template.jpg
