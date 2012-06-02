#-------------------------------------------------
#
# Project created by QtCreator 2012-04-19T10:49:04
#
#-------------------------------------------------

QT       += network

TARGET = WiSARMap
TEMPLATE = lib

DEFINES += WISARMAP_LIBRARY

SOURCES += \
    MapWidget.cpp \
    MapGraphicsView.cpp \
    IMapState.cpp \
    DefaultMapState.cpp \
    MapGraphicsScene.cpp \
    SearchArea.cpp \
    TestGraphicsScene.cpp

HEADERS +=\
        WiSARMap_global.h \
    MapWidget.h \
    MapGraphicsView.h \
    IMapState.h \
    DefaultMapState.h \
    MapGraphicsScene.h \
    SearchArea.h \
    TestGraphicsScene.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE836C420
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = WiSARMap.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
