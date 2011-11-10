#-------------------------------------------------
#
# Project created by QtCreator 2011-11-09T13:48:50
#
#-------------------------------------------------

QT       += core gui

TARGET = Stacknoob
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    core/player.cpp \
    core/grid.cpp \
    core/board.cpp \
    core/cell.cpp \
    core/piecefactory.cpp \
    core/piece.cpp \
    core/workflow.cpp \
    core/game.cpp

HEADERS  += mainwindow.h \
    core/player.h \
    core/grid.h \
    core/board.h \
    core/cell.h \
    core/piecefactory.h \
    core/piece.h \
    core/workflow.h \
    core/game.h

FORMS    += mainwindow.ui


