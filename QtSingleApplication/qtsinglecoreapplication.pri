INCLUDEPATH	+= $$PWD
DEPENDPATH      += $$PWD

HEADERS		+= $$PWD/inc/qtsinglecoreapplication.h \
                    $$PWD/inc/qtlocalpeer.h
					
SOURCES		+= $$PWD/src/qtsinglecoreapplication.cpp \
                    $$PWD/src/qtlocalpeer.cpp

QT *= network
