#-------------------------------------------------
#
# Project created by QtCreator 2022-10-22T04:15:47
#
#-------------------------------------------------

QT       += core sql

LIBS += -L$$PWD/lib -lcustomqtlib

TARGET = wrapper
TEMPLATE = lib

DEFINES += WRAPPER_LIBRARY

SOURCES += wrapper.cpp

HEADERS += wrapper.h \
            customqtlib.h \
            customqtlib_global.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    lib/customqtlib.dll
