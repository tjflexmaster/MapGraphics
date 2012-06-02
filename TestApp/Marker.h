#ifndef MARKER_H
#define MARKER_H

#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include "MapGraphicsItem.h"

class Marker : public MapGraphicsItem
{
public:
    Marker();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

//    void contextMenuEvent(QGraphicsSceneContextMenuEvent *);

//    void mousePressEvent(QGraphicsSceneMouseEvent *);

//    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    
signals:
    
public slots:
    
};

#endif // MARKER_H
