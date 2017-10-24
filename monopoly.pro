#-------------------------------------------------
#
# Project created by QtCreator 2017-09-25T23:39:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = monopoly
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    player.cpp \
    card.cpp \
    cardui.cpp \
    game.cpp \
    board.cpp \
    boardui.cpp \
    playerui.cpp

HEADERS += \
        mainwindow.h \
    card.h \
    player.h \
    cardui.h \
    game.h \
    board.h \
    boardui.h \
    playerui.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    Monopoly.jpg

RESOURCES += \
    resource.qrc
