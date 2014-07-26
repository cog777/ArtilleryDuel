#-------------------------------------------------
#
# Project created by QtCreator 2014-07-21T18:15:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArtilleryDuel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    landscape.cpp

HEADERS  += mainwindow.h \
    game.h \
    landscape.h \
    settings.h \
    debug.h

FORMS    += mainwindow.ui
