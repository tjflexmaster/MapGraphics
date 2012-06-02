#include "DefaultMapState.h"

DefaultMapState::DefaultMapState(DefaultMapState *parent)
{
}

void DefaultMapState::viewKeyPressEvent(QKeyEvent *event, QGraphicsView *view)
{
    event->ignore();
}

void DefaultMapState::viewKeyReleaseEvent(QKeyEvent *event, QGraphicsView *view)
{
    event->ignore();
}

void DefaultMapState::viewMouseDoubleClickEvent(QMouseEvent *event, QGraphicsView *view)
{
    event->ignore();
}

void DefaultMapState::viewMousePressEvent(QMouseEvent *event, QGraphicsView *view)
{
    event->ignore();
}

void DefaultMapState::viewMouseMoveEvent(QMouseEvent *event, QGraphicsView *view)
{
    event->ignore();
}

void DefaultMapState::viewMouseReleaseEvent(QMouseEvent *event, QGraphicsView *view)
{
    event->ignore();
}


/**
  *
  * SCENE EVENTS
  *
  */

void DefaultMapState::keyPressEvent(QKeyEvent *event, QGraphicsScene *scene)
{
    event->ignore();
}

void DefaultMapState::keyReleaseEvent(QKeyEvent *event, QGraphicsScene *scene)
{
    event->ignore();
}

void DefaultMapState::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    event->ignore();
}

void DefaultMapState::mousePressEvent(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    event->ignore();
}

void DefaultMapState::mouseMoveEvent(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    event->ignore();
}

void DefaultMapState::mouseReleaseEvent(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    event->ignore();
}
