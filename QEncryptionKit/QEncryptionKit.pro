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
    message(the QEncryptionKit will create in folder: ../daodaoliang)
        DESTDIR = ../daodaoliang/bin

        MOC_DIR = ../daodaoliang/moc/QEncryptionKit

        RCC_DIR = ../daodaoliang/rcc/QEncryptionKit

        UI_DIR = ../daodaoliang/ui/QEncryptionKit

        OBJECTS_DIR = ../daodaoliang/obj/QEncryptionKit
}
