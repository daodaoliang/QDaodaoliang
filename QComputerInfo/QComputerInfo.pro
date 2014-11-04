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
    message(the QComputerInfo will create in folder: ../daodaoliang)
        DESTDIR = ../daodaoliang/bin

        MOC_DIR = ../daodaoliang/moc/QComputerInfo

        RCC_DIR = ../daodaoliang/rcc/QComputerInfo

        UI_DIR = ../daodaoliang/ui/QComputerInfo

        OBJECTS_DIR = ../daodaoliang/obj/QComputerInfo
}

