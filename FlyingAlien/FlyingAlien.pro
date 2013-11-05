#-------------------------------------------------
#
# Project created by QtCreator 2013-10-13T20:11:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = customItem
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    newitem.cpp \
    background.cpp \
    plane.cpp

HEADERS  += dialog.h \
    newitem.h \
    background.h \
    plane.h

FORMS    += dialog.ui

RESOURCES += \
    OurResources.qrc
