#-------------------------------------------------
#
# Project created by QtCreator 2016-01-20T11:12:25
#
#-------------------------------------------------

QT       += core gui

include(../../qmmp.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32:{
    TARGET = ../../../bin/$$TTKMusicPlayer/app
    LIBS += -L../../bin/$$TTKMusicPlayer -lqmmp0
}
unix:{
    TARGET = ../../lib/$$TTKMusicPlayer/app
    LIBS += -L../../lib/$$TTKMusicPlayer -lqmmp
    LIBS += -L../../../extra/gcc/libtaglib/lib -ltag$$STATIC_LIBRARY_SUFFIX
}
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        musicplaylist.cpp \
        musicplayer.cpp

HEADERS  += mainwindow.h \
        musicplaylist.h \
        musicplayer.h

FORMS    += mainwindow.ui