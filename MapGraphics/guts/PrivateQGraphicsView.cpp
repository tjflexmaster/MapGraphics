#include "PrivateQGraphicsView.h"

#include <QWheelEvent>
#include <QContextMenuEvent>
#include <QtDebug>
#include <QScrollBar>
#include <QSharedPointer>
#include "IMapState.h"

PrivateQGraphicsView::PrivateQGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setDragMode(QGraphicsView::ScrollHandDrag);
}

PrivateQGraphicsView::PrivateQGraphicsView(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene,parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

PrivateQGraphicsView::~PrivateQGraphicsView()
{
}

void PrivateQGraphicsView::setMapState(QSharedPointer<IMapState> state)
{
    //Clear out the current map state if it isn't Null
    //This should cause the shared pointer to delete the object if no one else is using it
    if ( !_mapState.isNull() )
        _mapState.clear();

    //Use the new shared pointer
    _mapState = state;

}

void PrivateQGraphicsView::handleMapStateChanged(QSharedPointer<IMapState> state)
{
    setMapState(state);
}

//protected
////virtual from QGraphicsView
void PrivateQGraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
    this->hadContextMenuEvent(event);
}

//protected
//virtual from QGraphicsView
void PrivateQGraphicsView::wheelEvent(QWheelEvent *event)
{
    //QGraphicsView::wheelEvent(event);
    this->hadWheelEvent(event);
}

void PrivateQGraphicsView::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "view key press";
    if (_mapState.isNull())
        return;

    _mapState->viewKeyPressEvent(event, this);

    if (!event->isAccepted())
        QGraphicsView::keyPressEvent(event);

}

void PrivateQGraphicsView::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "view key release";
    if (_mapState.isNull())
        return;

    _mapState->viewKeyReleaseEvent(event, this);

    if (!event->isAccepted())
        QGraphicsView::keyReleaseEvent(event);
}

void PrivateQGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "view mouse doubleclick";
    if (_mapState.isNull())
        return;

    _mapState->viewMouseDoubleClickEvent(event, this);

    if (!event->isAccepted())
        QGraphicsView::mouseDoubleClickEvent(event);
}

void PrivateQGraphicsView::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "view mouse press";
    if (_mapState.isNull())
        return;

    _mapState->viewMousePressEvent(event, this);

    if (!event->isAccepted())
        QGraphicsView::mousePressEvent(event);
}

void PrivateQGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "view mouse move";
    if (_mapState.isNull())
        return;

    _mapState->viewMouseMoveEvent(event, this);

    if (!event->isAccepted())
        QGraphicsView::mouseMoveEvent(event);
}

void PrivateQGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "view mouse release";
    if (_mapState.isNull())
        return;

    _mapState->viewMouseReleaseEvent(event, this);

    if (!event->isAccepted())
        QGraphicsView::mouseReleaseEvent(event);
}
