#include "DrawMapState.h"
#include "IMapState.h"
#include <QDebug>
#include <QPoint>

DrawMapState::DrawMapState()
{
    _scene = 0;
    _start = QPoint(0,0);
}

QString DrawMapState::getName()
{
    return "Default";
}

QIcon DrawMapState::getIcon()
{
    return QIcon();
}

quint16 DrawMapState::getLayerId()
{
    return 0;
}

void DrawMapState::setScene(QGraphicsScene* scene)
{
    _scene = scene;
}

QGraphicsView::DragMode DrawMapState::getDragMode()
{
    return QGraphicsView::NoDrag;
}

void DrawMapState::mouseDoubleClickEvent(QMouseEvent* event)
{
    qDebug() << "Double Click";
    event->setAccepted(false);
}

void DrawMapState::mouseMoveEvent(QMouseEvent* event)
{
    qDebug() << "Draw Line";
    _scene->addLine(_start.x(), _start.y(), event->x(), event->y());
    event->setAccepted(true);
}

void DrawMapState::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Start Line Point";
    _start = QPoint(event->x(), event->y());

    event->setAccepted(true);
}

void DrawMapState::mouseReleaseEvent(QMouseEvent* event)
{
    qDebug() << "Release";
    event->setAccepted(false);
}
