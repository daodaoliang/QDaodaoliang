#-------------------------------------------------
#
# Project created by QtCreator 2014-11-03T15:53:54
#
#-------------------------------------------------

QT       += network
QT       -= gui

TARGET = QComputerInfo
TEMPLATE = lib

DEFINES += QCOMPUTERINFO_LIBRARY

include(./QComputerInfo_depends.pri)
include(./QComputerInfo_others.pri)
include(./QComputerInfo_inc.pri)

INCLUDEPATH += ./inc/ \

win32 {
    message(the QBaseUiKit will create in folder: ../daodaoliang)
        DESTDIR = ../daodaoliang/bin

        MOC_DIR = ../daodaoliang/moc

        RCC_DIR = ../daodaoliang/rcc

        UI_DIR = ../daodaoliang/ui

        OBJECTS_DIR = ../daodaoliang/obj
}

