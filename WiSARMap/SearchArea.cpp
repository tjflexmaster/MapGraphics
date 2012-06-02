#include "SearchArea.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QCursor>
#include <QDebug>

SearchArea::SearchArea(QGraphicsRectItem *parent) :
    QGraphicsRectItem(parent)
{
    _resizing_height = false;
    _resizing_width = false;
    _moving = false;
    setAcceptHoverEvents(true);
}

void SearchArea::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "MousePress" << this->scenePos().x() << " - " << this->scenePos().y();
    event->setAccepted(true);
    _local_diff = event->scenePos() - scenePos();
}

void SearchArea::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    QPointF scenediff = event->scenePos() - scenePos();
    setPos( scenePos() + (scenediff - _local_diff) );
    qDebug() << "ScenePos:" << scenediff.x() << "-" << scenediff.y() << " Diff:" << _local_diff.x() << "-" << _local_diff.y();
}

void SearchArea::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    _resizing_height = false;
    _resizing_width = false;
    _moving = false;
    _local_diff = QPointF(0,0);
    qDebug() << "Mouse Release" << this->scenePos().x() << " - " << this->scenePos().y();
}

void SearchArea::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug() << "Item Hover Enter";
//    QGraphicsView* view;
//    foreach ( view, this->scene()->views() ) {
//        view->viewport()->setCursor(Qt::BusyCursor);
//    }
}

void SearchArea::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug() << "Item Hover Move";
//    QPainterPath path = this->shape();
//    if ( path.contains(event->pos()) ) {
//        qDebug() << "Over Edge";
//    }
}

void SearchArea::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug() << "Item Hover Leave";
//    QGraphicsView* view;
//    foreach ( view, this->scene()->views() ) {
//        view->viewport()->setCursor(Qt::ArrowCursor);
//    }
}
