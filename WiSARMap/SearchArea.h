#ifndef SEARCHAREA_H
#define SEARCHAREA_H

#include "WiSARMap_global.h"
#include <QGraphicsRectItem>
#include <QPointF>

class WISARMAPSHARED_EXPORT SearchArea : public QGraphicsRectItem
{
public:
    explicit SearchArea(QGraphicsRectItem *parent = 0);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    
signals:
    
public slots:

private:
    bool _resizing_height;
    bool _resizing_width;
    bool _moving;
    QPointF _move_start;
    QPointF _local_diff;
};

#endif // SEARCHAREA_H
