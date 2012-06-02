#-------------------------------------------------
#
# Project created by QtCreator 2012-04-19T13:29:49
#
#-------------------------------------------------

QT       += core gui

TARGET = TestWisar
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    DrawMapState.cpp

HEADERS  += MainWindow.h \
    DrawMapState.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../WiSARMap/release/ -lWiSARMap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../WiSARMap/debug/ -lWiSARMap
else:symbian: LIBS += -lWiSARMap
else:unix: LIBS += -L$$OUT_PWD/../WiSARMap/ -lWiSARMap

INCLUDEPATH += $$PWD/../WiSARMap
DEPENDPATH += $$PWD/../WiSARMap
