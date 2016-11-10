#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T15:13:04
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app


SOURCES += main.cpp\
        logwindow.cpp

HEADERS  += logwindow.h

FORMS    += logwindow.ui

QMAKE_CXXFLAGS      +=  -std=gnu++11
