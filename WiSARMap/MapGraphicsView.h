#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H

#include "WiSARMap_global.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "IMapState.h"

class WISARMAPSHARED_EXPORT MapGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapGraphicsView(QWidget *parent = 0);
    void setMapState(IMapState* state);
    void setMapState(QMetaObject meta);
    
signals:

    
public slots:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    QGraphicsScene* _scene;
    IMapState* _state;
    quint8 _zoom_level;
    quint16 _tile_size;

};

#endif // MAPGRAPHICSVIEW_H
