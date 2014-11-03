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
#include dll's header
include(./../../QComputerInfo/QComputerInfo_inc.pri)

TEMPLATE = app

SOURCES += main.cpp

win32 {
    message(the QBasicUiKitDemo will create in folder: ../daodaoliang)
        DESTDIR = ../../daodaoliang/bin

        MOC_DIR = ../../daodaoliang/moc

        RCC_DIR = ../../daodaoliang/rcc

        UI_DIR = ../../daodaoliang/ui

        OBJECTS_DIR = ../../daodaoliang/obj
}
