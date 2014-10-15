#-------------------------------------------------
#
# Project created by QtCreator 2014-08-23T07:23:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBprom3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    core/node.cpp \
    subwindows/addattributedialog.cpp \
    core/storage.cpp \
    core/nodecontainer.cpp

HEADERS  += mainwindow.h \
    core/node.h \
    subwindows/addattributedialog.h \
    core/storage.h \
    core/nodecontainer.h

FORMS    += mainwindow.ui \
    subwindows/addattributedialog.ui

CONFIG   += c++11
