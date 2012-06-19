#-------------------------------------------------
#
# Project created by QtCreator 2012-03-03T10:50:47
#
#-------------------------------------------------

QT       += network sql

TARGET = MapGraphics
TEMPLATE = lib

DEFINES += MAPGRAPHICS_LIBRARY

HEADERS += MapGraphicsScene.h\
        MapGraphics_global.h \
    MapGraphicsObject.h \
    MapGraphicsView.h \
    guts/PrivateQGraphicsScene.h \
    guts/PrivateQGraphicsObject.h \
    guts/Conversions.h \
    MapTileSource.h \
    tileSources/GridTileSource.h \
    guts/MapTileGraphicsObject.h \
    guts/PrivateQGraphicsView.h \
    tileSources/OSMTileSource.h \
    guts/MapGraphicsNetwork.h \
    tileSources/CompositeTileSource.h \
    guts/SQLiteKeyValueStore.h \
    guts/MapTileLayerListModel.h \
    guts/MapTileSourceDelegate.h \
    guts/CompositeTileSourceConfigurationWidget.h \
    CircleObject.h \
    guts/PrivateQGraphicsInfoSource.h \
    PolygonObject.h \
    IMapState.h \
    mapStates/ViewPanState.h \
    mapStates/DefaultMapState.h \
    gui/mapstate/IMapStateWidgetController.h \
    gui/mapstate/IMapStateWidgetView.h \
    gui/mapstate/MapStateWidgetController.h \
    gui/mapstate/MapStateWidgetView.h

SOURCES += MapGraphicsScene.cpp \
    MapGraphicsObject.cpp \
    MapGraphicsView.cpp \
    guts/PrivateQGraphicsScene.cpp \
    guts/PrivateQGraphicsObject.cpp \
    guts/Conversions.cpp \
    MapTileSource.cpp \
    tileSources/GridTileSource.cpp \
    guts/MapTileGraphicsObject.cpp \
    guts/PrivateQGraphicsView.cpp \
    tileSources/OSMTileSource.cpp \
    guts/MapGraphicsNetwork.cpp \
    tileSources/CompositeTileSource.cpp \
    guts/SQLiteKeyValueStore.cpp \
    guts/MapTileLayerListModel.cpp \
    guts/MapTileSourceDelegate.cpp \
    guts/CompositeTileSourceConfigurationWidget.cpp \
    CircleObject.cpp \
    guts/PrivateQGraphicsInfoSource.cpp \
    PolygonObject.cpp \
    IMapState.cpp \
    mapStates/ViewPanState.cpp \
    mapStates/DefaultMapState.cpp \
    gui/mapstate/IMapStateWidgetController.cpp \
    gui/mapstate/IMapStateWidgetView.cpp \
    gui/mapstate/MapStateWidgetController.cpp \
    gui/mapstate/MapStateWidgetView.cpp

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE4F7F973
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = MapGraphics.dll
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

FORMS += \
    guts/CompositeTileSourceConfigurationWidget.ui \
    gui/mapstate/MapStateWidgetView.ui
