#-------------------------------------------------
#
# Project created by QtCreator 2014-09-26T15:37:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QBasicUiKitDemo
TEMPLATE = app


SOURCES += ./src/main.cpp \
           ./src/popdialogdemo.cpp \
           ./src/miniiconwidgetdemo.cpp

HEADERS  += ./inc/popdialogdemo.h \
            ./inc/miniiconwidgetdemo.h

FORMS    += ./form/popdialogdemo.ui \
            ./form/miniiconwidgetdemo.ui

RESOURCES += ./res/QBasicUiKitResource.qrc

INCLUDEPATH += ./inc/ \
                ./form/
win32 {
    message(the QBasicUiKitDemo will create in folder: ../daodaoliang)
        DESTDIR = ../../daodaoliang/bin

        MOC_DIR = ../../daodaoliang/moc

        RCC_DIR = ../../daodaoliang/rcc

        UI_DIR = ../../daodaoliang/ui

        OBJECTS_DIR = ../../daodaoliang/obj
}

#inport pro's depends files
include(./QBasicUiKitDemo_depends.pri)

#import Lib's header file
include(./../../QBaseUiKit/QBaseUiKit_inc.pri)

#import QtSingleApp file
include(./../../QtSingleApplication/qtsingleapplication.pri)

#import MiniDump file
include(./../../Dump/MiniDump/MiniDump.pri)

#import crashDump file
include(./../../Dump/crashdump/crashdump_inc.pri)
