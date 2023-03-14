#-------------------------------------------------
#
# Project created by QtCreator 2022-10-19T21:52:33
#
#-------------------------------------------------

QT       += sql
QT       -= gui

TARGET = customqtlib
TEMPLATE = lib

DEFINES += CUSTOMQTLIB_LIBRARY

SOURCES += \
    customqtlib.cpp

HEADERS +=\
    customqtlib.h \
    customqtlib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
