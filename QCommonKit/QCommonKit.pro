#-------------------------------------------------
#
# Project created by QtCreator 2014-11-17T11:36:30
#
#-------------------------------------------------

QT       -= gui

TARGET = QCommonKit
TEMPLATE = lib

DEFINES += QCOMMONKIT_LIBRARY

include(./QCommonKit_depends.pri)
include(./QCommonKit_inc.pri)
include(./QCommonKit_others.pri)

INCLUDEPATH += ./inc/

unix {
    target.path = /usr/lib
    INSTALLS += target
}
win32 {
    message(the QCommonKit will create in folder: ../daodaoliang)
        DESTDIR = ../daodaoliang/bin

        MOC_DIR = ../daodaoliang/moc/QBaseUiKit

        RCC_DIR = ../daodaoliang/rcc/QBaseUiKit

        UI_DIR = ../daodaoliang/ui/QBaseUiKit

        OBJECTS_DIR = ../daodaoliang/obj/QBaseUiKit
}
