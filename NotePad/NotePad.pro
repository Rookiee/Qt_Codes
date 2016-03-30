#-------------------------------------------------
#
# Project created by QtCreator 2016-01-22T20:41:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NotePad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    about.h

FORMS    += mainwindow.ui \
    about.ui

RESOURCES += \
    myresource.qrc

RC_FILE = myapp.rc
