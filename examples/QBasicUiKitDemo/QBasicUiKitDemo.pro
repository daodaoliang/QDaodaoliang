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
           ./src/miniiconwidgetdemo.cpp \
           ./src/formfadewidgetdemo.cpp

HEADERS  += ./inc/popdialogdemo.h \
            ./inc/miniiconwidgetdemo.h \
            ./inc/formfadewidgetdemo.h

FORMS    += ./form/popdialogdemo.ui \
            ./form/miniiconwidgetdemo.ui \
            ./form/formfadewidgetdemo.ui

RESOURCES += ./res/QBasicUiKitResource.qrc

INCLUDEPATH += ./inc/ \
               ./form/
win32 {
    message(the QBasicUiKitDemo will create in folder: ../daodaoliang)
        DESTDIR = ../../daodaoliang/bin

        MOC_DIR = ../../daodaoliang/moc/QBasicUiKitDemo

        RCC_DIR = ../../daodaoliang/rcc/QBasicUiKitDemo

        UI_DIR = ../../daodaoliang/ui/QBasicUiKitDemo

        OBJECTS_DIR = ../../daodaoliang/obj/QBasicUiKitDemo
}

#inport pro's depends files
include(./QBasicUiKitDemo_depends.pri)

#import QtSingleApp file
include(./../../QtSingleApplication/qtsingleapplication.pri)

#import MiniDump file
include(./../../Dump/MiniDump/MiniDump.pri)

#import crashDump file
include(./../../Dump/crashdump/crashdump_inc.pri)
