#-------------------------------------------------
#
# Project created by QtCreator 2015-12-15T15:08:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestBrower
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mybrowser.cpp

HEADERS  += widget.h \
    mybrowser.h

CONFIG += mobility
MOBILITY = 

