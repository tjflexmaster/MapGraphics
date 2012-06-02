#include "Marker.h"

Marker::Marker()
{

}


QRectF Marker::boundingRect() const
{
    QPointF middle = this->qGraphicsItem()->scenePos();
    QPointF topleft(middle.x() - 2, middle.y() - 2);
    QPointF botright(middle.x() + 2, middle.y() + 2);
    return QRectF(topleft, botright );
}

void Marker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(QColor(255,0,0,225));

    QPointF pos = this->qGraphicsItem()->scenePos();
    //draw the inner ellipse
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawPoint(pos.x(), pos.y());
}

