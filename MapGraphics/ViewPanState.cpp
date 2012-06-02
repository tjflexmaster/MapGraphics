#include "ViewPanState.h"
#include <QGraphicsView>
#include <QScrollBar>
#include <QDebug>

ViewPanState::ViewPanState(ISceneState *parent)
{
}

void ViewPanState::setView(QGraphicsView *view)
{
    _view = view;
}

void ViewPanState::keyPressEvent(QKeyEvent *event)
{
    event->ignore();
}

void ViewPanState::keyReleaseEvent(QKeyEvent *event)
{
    event->ignore();
}

//void ViewPanState::viewMouseDoubleClickEvent(QMouseEvent *event)
//{
//    event->ignore();
//}

//void ViewPanState::viewMousePressEvent(QMouseEvent *event)
//{
//    if ( event->button() == Qt::LeftButton && _view != NULL ) {
//        _panning = true;
//        _pan_x = event->x();
//        _pan_y = event->y();
//        _view->setCursor(Qt::ClosedHandCursor);
//        event->accept();
//        return;
//    }
//    event->ignore();
//}

//void ViewPanState::viewMouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    if ( _panning && _view != NULL ) {
//        _view->horizontalScrollBar()->setValue( _view->horizontalScrollBar()->value() - (event->x() - _pan_x));
//        _view->verticalScrollBar()->setValue( _view->verticalScrollBar()->value() - (event->y() - _pan_y));
//        _pan_x = event->x();
//        _pan_y = event->y();
//        event->accept();
//        return;
//    }
//    event->ignore();
//}

//void ViewPanState::viewMouseReleaseEvent(QMouseEvent *event)
//{
//    if ( event->button() == Qt::LeftButton && _view != NULL) {
//        _panning = false;
//        _view->setCursor(Qt::ArrowCursor);
//        event->accept();
//        return;
//    }
//    event->ignore();
//}

void ViewPanState::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}

void ViewPanState::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if ( event->button() == Qt::LeftButton && _view != NULL ) {
        qDebug() << "Pan Click";
        _panning = true;
        _pan_x = event->screenPos().x();
        _pan_y = event->screenPos().y();
        _view->setCursor(Qt::ClosedHandCursor);
        event->accept();
        return;
    }
    event->ignore();
}

void ViewPanState::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if ( _panning && _view != NULL ) {
        qDebug() << "Pan Move";
        qDebug() << "delta x" << event->screenPos().x() << _pan_x;
        _view->horizontalScrollBar()->setValue( _view->horizontalScrollBar()->value() - (event->screenPos().x() - _pan_x));
        _view->verticalScrollBar()->setValue( _view->verticalScrollBar()->value() - (event->screenPos().y() - _pan_y));
        _pan_x = event->pos().x();
        _pan_y = event->pos().y();
        event->accept();
        return;
    }
    event->ignore();
}

void ViewPanState::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton && _view != NULL) {
        _panning = false;
        _view->setCursor(Qt::ArrowCursor);
        event->accept();
        return;
    }
    event->ignore();
}
