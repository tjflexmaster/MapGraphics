#include "PrivateQGraphicsView.h"

#include <QWheelEvent>
#include <QContextMenuEvent>
#include <QtDebug>
#include <QScrollBar>

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

void PrivateQGraphicsView::mousePressEvent(QMouseEvent *event)
{
//    if ( event->button() == Qt::LeftButton ) {
//        _panning = true;
//        _pan_x = event->x();
//        _pan_y = event->y();
//        setCursor(Qt::ClosedHandCursor);
//        event->accept();
//        return;
//    }
    event->ignore();
}

void PrivateQGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
//    if ( _panning ) {
//        horizontalScrollBar()->setValue( horizontalScrollBar()->value() - (event->x() - _pan_x));
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - _pan_y));
//        _pan_x = event->x();
//        _pan_y = event->y();
//        event->accept();
//        return;
//    }
    event->ignore();
}

void PrivateQGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
//    if ( event->button() == Qt::LeftButton) {
//        _panning = false;
//        setCursor(Qt::ArrowCursor);
//        event->accept();
//        return;
//    }
    event->ignore();
}

void PrivateQGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    event->ignore();
}

