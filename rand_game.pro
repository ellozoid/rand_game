#-------------------------------------------------
#
# Project created by QtCreator 2015-06-25T21:51:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = rand_game
TEMPLATE = app


SOURCES += main.cpp\
        rand_game.cpp \
    game_rect.cpp

HEADERS  += rand_game.h \
    game_rect.h \
    ui_rand_game.h

FORMS    += rand_game.ui
