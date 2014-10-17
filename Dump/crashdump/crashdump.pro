TEMPLATE = lib
TARGET = gbreakpad

win32 {
    message(the crashdump will create in folder: ../daodaoliang)
        DESTDIR = ../../daodaoliang/bin

        MOC_DIR = ../../daodaoliang/moc

        RCC_DIR = ../../daodaoliang/rcc

        UI_DIR = ../../daodaoliang/ui

        OBJECTS_DIR = ../../daodaoliang/obj
}

## google breakpad svn 969

CONFIG += warn_off thread exceptions rtti stl
CONFIG += static
QT -= gui

##why
DEFINES += QT_NO_CAST_TO_ASCII
DEFINES += QT_NO_CAST_FROM_ASCII

unix:!mac {
    debug {
        QMAKE_CFLAGS_DEBUG += -gstabs
        QMAKE_CXXFLAGS_DEBUG += -gstabs
    }
}

mac {
    LIBS += -lcrypto
}

LIST = thread exceptions rtti stl
for(f, LIST) {
    !CONFIG($$f){
        warning("Add '$$f' to CONFIG, or you will find yourself in 'funny' problems.")
    }
}
INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/inc/

HEADERS += $$PWD/inc/BreakpadHandler.h
SOURCES += $$PWD/src/BreakpadHandler.cpp

include($$PWD/gbreakpad/gbreakpad.pri)
