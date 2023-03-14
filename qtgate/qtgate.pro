#-------------------------------------------------
#
# Project created by QtCreator 2022-10-22T04:40:40
#
#-------------------------------------------------

QT       -= core gui

LIBS += -L$$PWD/lib/32bit -llua51 -L$$PWD/lib -lwrapper

QMAKE_CXX = gcc
QMAKE_CXXFLAGS = -x c

TARGET = qtgate
TEMPLATE = lib

DEFINES += QTGATE_LIBRARY

SOURCES += qtgate.c

HEADERS += qtgate.h \
            wrapper.h \
            lauxlib.h \
            lua.h \
            luaconf.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    lib/32bit/lua51.lib \
    lib/64bit/lua51.lib \
    lib/32bit/lua51.dll \
    lib/64bit/lua51.dll \
    lib/wrapper.dll
