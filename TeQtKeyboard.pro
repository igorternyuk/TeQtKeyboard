#-------------------------------------------------
#
# Project created by QtCreator 2018-05-09T10:48:31
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++1z
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeQtKeyboard
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    button.cpp \
    keyboardform.cpp

HEADERS  += widget.h \
    button.hpp \
    keyboardform.hpp

FORMS    += widget.ui \
    keyboardform.ui
