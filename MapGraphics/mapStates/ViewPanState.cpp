#include "ViewPanState.h"
#include <QGraphicsView>
#include <QScrollBar>
#include <QDebug>

ViewPanState::ViewPanState(IMapState *parent)
{
}

void ViewPanState::viewKeyPressEvent(QKeyEvent *event, QGraphicsView *view)
{
    event->accept();
}

void ViewPanState::viewKeyReleaseEvent(QKeyEvent *event, QGraphicsView *view)
{
    event->accept();
}

void ViewPanState::viewMouseDoubleClickEvent(QMouseEvent *event, QGraphicsView *view)
{
    event->accept();
}

/**
 * @brief Set the panning state by setting panning to true and saving the current
 * mouse position.
 *
 * @param event
 * @param view
 */
void ViewPanState::viewMousePressEvent(QMouseEvent *event, QGraphicsView *view)
{
    /*If the left mouse button is pressed then start the panning mode, otherwise
    do nothing*/

    if ( event->button() == Qt::LeftButton && view != NULL ) {
        _panning = true;
        _pan_x = event->x();
        _pan_y = event->y();
        view->setCursor(Qt::ClosedHandCursor);
    }
    event->accept();
}

/**
 * @brief If in panning mode then check the distance that the mouse has moved from
 * the last event and adjust the scrollbars by that amount.
 * After adjusting the scrollbars save the new mouse position.
 *
 * @param event
 * @param view
 */
void ViewPanState::viewMouseMoveEvent(QMouseEvent *event, QGraphicsView *view)
{
    if ( _panning && view != NULL ) {
        int delta_x = (event->x() - _pan_x);
        int delta_y = (event->y() - _pan_y);
        view->horizontalScrollBar()->setValue( view->horizontalScrollBar()->value() - delta_x );
        view->verticalScrollBar()->setValue( view->verticalScrollBar()->value() - delta_y );
        _pan_x = event->x();
        _pan_y = event->y();
        return;
    }
    event->accept();
}

/**
 * @brief If the left mouse button is released then set panning mode to false
 * and return the cursor to it's original state.
 *
 * @param event
 * @param view
 */
void ViewPanState::viewMouseReleaseEvent(QMouseEvent *event, QGraphicsView *view)
{
    if ( event->button() == Qt::LeftButton && view != NULL) {
        _panning = false;
        view->setCursor(Qt::ArrowCursor);
        return;
    }
    event->accept();
}



/**
  *
  * SCENE EVENTS
  *
  */
void ViewPanState::keyPressEvent(QKeyEvent *event, QGraphicsScene *scene)
{
    event->accept();
}

void ViewPanState::keyReleaseEvent(QKeyEvent *event, QGraphicsScene *scene)
{
    event->accept();
}

void ViewPanState::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    event->accept();
}

void ViewPanState::mousePressEvent(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    event->accept();
}

void ViewPanState::mouseMoveEvent(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    event->accept();
}

void ViewPanState::mouseReleaseEvent(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    event->accept();
}

