#-------------------------------------------------
#
# Project created by QtCreator 2013-09-23T16:31:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlyingAlien
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    flyingobjects.cpp \
    plane.cpp

HEADERS  += mainwindow.h \
    flyingobjects.h \
    plane.h

FORMS    += mainwindow.ui
