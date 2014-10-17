#-------------------------------------------------
#
# Project created by QtCreator 2014-09-26T14:33:45
#
#-------------------------------------------------

TARGET = QBaseUiKit
TEMPLATE = lib

DEFINES += QBASEUIKIT_LIBRARY

include(./QBaseUiKit_inc.pri)
include(./QBaseUiKit_depends.pri)
include(./QBaseUiKit_others.pri)

INCLUDEPATH += ./form/  \
                ./inc/

win32 {
    message(the QBaseUiKit will create in folder: ../daodaoliang)
        DESTDIR = ../daodaoliang/bin

        MOC_DIR = ../daodaoliang/moc

        RCC_DIR = ../daodaoliang/rcc

        UI_DIR = ../daodaoliang/ui

        OBJECTS_DIR = ../daodaoliang/obj
}

