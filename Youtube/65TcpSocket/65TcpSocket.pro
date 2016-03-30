QT += core
QT -= gui
QT += network

TARGET = 65TcpSocket
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    sockettest.cpp

HEADERS += \
    sockettest.h

