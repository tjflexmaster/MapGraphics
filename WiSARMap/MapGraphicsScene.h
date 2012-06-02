#ifndef MAPGRAPHICSSCENE_H
#define MAPGRAPHICSSCENE_H

#include "WiSARMap_global.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "SearchArea.h"

class WISARMAPSHARED_EXPORT MapGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MapGraphicsScene(QGraphicsScene *parent = 0);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
signals:
    
public slots:
    

private:
    SearchArea* _current_item;
    QPointF _start_point;
    quint8 _zoom_level;
    quint16 _tile_size;
    bool _drawing;
};

#endif // MAPGRAPHICSSCENE_H
