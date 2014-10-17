INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/inc/
DEPENDPATH += $$PWD

QT *= network

SOURCES += $$PWD/src/qtsingleapplication.cpp \
            $$PWD/src/qtlocalpeer.cpp

HEADERS += $$PWD/inc/qtsingleapplication.h \
            $$PWD/inc/qtlocalpeer.h
