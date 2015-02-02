#-------------------------------------------------
#
# Project created by QtCreator 2015-01-24T11:26:31
#
#-------------------------------------------------

QT       += core
QT         += network
QT       -= gui

QMAKE_CXXFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    server.cpp \
    window.cpp

HEADERS += \
    server.h \
    window.h
