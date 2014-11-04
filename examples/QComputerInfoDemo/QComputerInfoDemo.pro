#-------------------------------------------------
#
# Project created by QtCreator 2014-11-03T16:16:21
#
#-------------------------------------------------

QT       += core network
QT       -= gui

TARGET = QComputerInfoDemo
CONFIG   += console
CONFIG   -= app_bundle

#include pro's depends
include(./QComputerInfoDemo_depends.pri)

TEMPLATE = app

SOURCES += main.cpp

win32 {
    message(the QComputerInfoDemo will create in folder: ../daodaoliang)
        DESTDIR = ../../daodaoliang/bin

        MOC_DIR = ../../daodaoliang/moc/QComputerInfoDemo

        RCC_DIR = ../../daodaoliang/rcc/QComputerInfoDemo

        UI_DIR = ../../daodaoliang/ui/QComputerInfoDemo

        OBJECTS_DIR = ../../daodaoliang/obj/QComputerInfoDemo
}
