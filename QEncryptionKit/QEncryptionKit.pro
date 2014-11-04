#-------------------------------------------------
#
# Project created by QtCreator 2014-11-04T10:23:13
#
#-------------------------------------------------

QT       -= gui

TARGET = QEncryptionKit
TEMPLATE = lib

DEFINES += QENCRYPTIONKIT_LIBRARY

include(./QEncryptionKit_depends.pri)
include(./QEncryptionKit_others.pri)
include(./QEncryptionKit_inc.pri)

INCLUDEPATH += ./inc/ \

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
win32{
    message(the QComputerInfo will create in folder: ../daodaoliang)
        DESTDIR = ../daodaoliang/bin

        MOC_DIR = ../daodaoliang/moc

        RCC_DIR = ../daodaoliang/rcc

        UI_DIR = ../daodaoliang/ui

        OBJECTS_DIR = ../daodaoliang/obj
}
