#-------------------------------------------------
#
# Project created by QtCreator 2015-11-23T17:24:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OAR
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogcampo.cpp \
    dialogmodificarcampo.cpp

HEADERS  += mainwindow.h \
    dialogcampo.h \
    Campo.h \
    dialogmodificarcampo.h

FORMS    += mainwindow.ui \
    dialogcampo.ui \
    dialogmodificarcampo.ui
