#-------------------------------------------------
#
# Project created by QtCreator 2013-10-13T20:11:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = customItem
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    newitem.cpp \
    background.cpp \
    plane.cpp \
    bird.cpp \
    fuel.cpp \
    mineral.cpp \
    pet.cpp \
    blackout.cpp \
    asteroid.cpp \
    background2.cpp \
    background3.cpp \
    ship.cpp \
    upgrade.cpp \
    gamelabel.cpp \
    script.cpp

HEADERS  += dialog.h \
    newitem.h \
    background.h \
    plane.h \
    bird.h \
    fuel.h \
    mineral.h \
    pet.h \
    blackout.h \
    asteroid.h \
    background2.h \
    background3.h \
    ship.h \
    upgrade.h \
    gamelabel.h \
    script.h

FORMS    += dialog.ui

RESOURCES += \
    OurResources.qrc
