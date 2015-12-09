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
    dialogmodificarcampo.cpp \
    file.cpp \
    record.cpp \
    campo.cpp \
    nodo.cpp \
    key.cpp \
    btree.cpp

HEADERS  += mainwindow.h \
    dialogcampo.h \
    dialogmodificarcampo.h \
    file.h \
    record.h \
    campo.h \
    nodo.h \
    key.h \
    btree.h

FORMS    += mainwindow.ui \
    dialogcampo.ui \
    dialogmodificarcampo.ui
