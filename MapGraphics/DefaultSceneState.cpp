#include "DefaultSceneState.h"

DefaultSceneState::DefaultSceneState(DefaultSceneState *parent)
{
}

void DefaultSceneState::setView(QGraphicsView *view)
{
    //Do Nothing
}

void DefaultSceneState::keyPressEvent(QKeyEvent *event)
{
    event->ignore();
}

void DefaultSceneState::keyReleaseEvent(QKeyEvent *event)
{
    event->ignore();
}

//void DefaultSceneState::viewMouseDoubleClickEvent(QMouseEvent *event)
//{
//    event->ignore();
//}

//void DefaultSceneState::viewMousePressEvent(QMouseEvent *event)
//{
//    event->ignore();
//}

//void DefaultSceneState::viewMouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    event->ignore();
//}

//void DefaultSceneState::viewMouseReleaseEvent(QMouseEvent *event)
//{
//    event->ignore();
//}

void DefaultSceneState::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}

void DefaultSceneState::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}

void DefaultSceneState::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}

void DefaultSceneState::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}
