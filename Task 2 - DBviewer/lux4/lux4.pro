#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T19:26:06
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += release
TARGET = lux4
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    createdialog.cpp \
    opendialog.cpp \
    showdbdialog.cpp

HEADERS  += widget.h \
    createdialog.h \
    opendialog.h \
    showdbdialog.h

FORMS    += widget.ui \
    createdialog.ui \
    opendialog.ui \
    showdbdialog.ui
