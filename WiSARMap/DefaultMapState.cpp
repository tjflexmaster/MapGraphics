#include "DefaultMapState.h"
#include <QDebug>

DefaultMapState::DefaultMapState()
{
    _scene = 0;

}

QString DefaultMapState::getName()
{
    return "Default";
}

QIcon DefaultMapState::getIcon()
{
    return QIcon();
}

quint16 DefaultMapState::getLayerId()
{
    return 0;
}

void DefaultMapState::setScene(QGraphicsScene* scene)
{
    _scene = scene;
}

QGraphicsView::DragMode DefaultMapState::getDragMode()
{
    return QGraphicsView::ScrollHandDrag;
}

void DefaultMapState::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "Default Double Click";
    event->setAccepted(false);
}

void DefaultMapState::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Default Move";
    event->setAccepted(false);
}

void DefaultMapState::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Default Press";
    event->setAccepted(false);
}

void DefaultMapState::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Default Release";
    event->setAccepted(false);
}
