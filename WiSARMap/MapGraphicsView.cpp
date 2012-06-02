#include "MapGraphicsView.h"
#include "DefaultMapState.h"
#include <cmath>
#include <QMetaObject>
#include <QDebug>

MapGraphicsView::MapGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    _state = 0;

    _zoom_level = 5;
    _tile_size = 256;

    long double tilecount = pow(4.0, _zoom_level);
    long double tiledepthcount = sqrt(tilecount);
    long double pixelcount = tiledepthcount * _tile_size;
    const QRectF scene_rect(0,0, pixelcount, pixelcount);
    _scene = new QGraphicsScene(scene_rect);

    setScene(_scene);

    //Set the Default Map State
//    DefaultMapState* state = new DefaultMapState();
//    setMapState(qobject_cast<IMapState*>(state));
    setMapState(DefaultMapState::staticMetaObject);
}

void MapGraphicsView::setMapState(IMapState *state)
{
    if ( _state != 0 )
        delete(_state);

    _state = state;

    _state->setScene(_scene);
    setDragMode(_state->getDragMode());

}

void MapGraphicsView::setMapState(QMetaObject meta)
{
    if ( _state != 0 )
        delete(_state);

    //Use Reflection
    _state = qobject_cast<IMapState*>(meta.newInstance());

    _state->setScene(_scene);
    setDragMode(_state->getDragMode());

}

void MapGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    _state->mouseDoubleClickEvent(event);

    if ( event->isAccepted() )
        return;

    QGraphicsView::mouseDoubleClickEvent(event);
}

void MapGraphicsView::mouseMoveEvent(QMouseEvent* event)
{
    _state->mouseMoveEvent(event);

    if ( event->isAccepted() )
        return;

    QGraphicsView::mouseMoveEvent(event);
}

void MapGraphicsView::mousePressEvent(QMouseEvent* event)
{
    _state->mousePressEvent(event);
    QPointF scene_point = this->mapToScene(event->x(), event->y());

    if ( event->isAccepted() )
        return;

    QGraphicsView::mousePressEvent(event);
    qDebug() << "Real Press";
}

void MapGraphicsView::mouseReleaseEvent(QMouseEvent* event)
{
    _state->mouseReleaseEvent(event);

    if ( event->isAccepted() )
        return;

    QGraphicsView::mouseReleaseEvent(event);
}
