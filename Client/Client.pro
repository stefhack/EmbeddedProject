#-------------------------------------------------
#
# Project created by QtCreator 2015-02-02T19:49:35
#
#-------------------------------------------------

#QT       += core

#QT       -= gui
QT       += core
QT         += network
QT       -= gui

QMAKE_CXXFLAGS += -std=c++11


TARGET = Client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    client.cpp

HEADERS += \
    client.h
