#-------------------------------------------------
#
# Project created by QtCreator 2013-07-24T07:41:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Staff
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    staff.cpp \
    staffwriter.cpp \
    stafflist.cpp

HEADERS  += mainwindow.h \
    staff.h \
    staffwriter.h \
    stafflist.h

FORMS    += mainwindow.ui
