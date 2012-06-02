#ifndef IMAPSTATE_H
#define IMAPSTATE_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

#include "MapGraphics_global.h"

class MAPGRAPHICSSHARED_EXPORT IMapState : public QObject
{
    Q_OBJECT
public:

    virtual void viewKeyPressEvent( QKeyEvent* event, QGraphicsView* view) = 0;
    virtual void viewKeyReleaseEvent( QKeyEvent* event, QGraphicsView* view) = 0;
    virtual void viewMouseDoubleClickEvent( QMouseEvent* event, QGraphicsView* view) = 0;
    virtual void viewMousePressEvent( QMouseEvent* event, QGraphicsView* view) = 0;
    virtual void viewMouseMoveEvent( QMouseEvent* event, QGraphicsView* view) = 0;
    virtual void viewMouseReleaseEvent( QMouseEvent* event, QGraphicsView* view) = 0;

    /**
     * @brief The following events are all Scene Events
     *
     * @param event
     */
    virtual void keyPressEvent( QKeyEvent* event, QGraphicsScene* scene) = 0;
    virtual void keyReleaseEvent( QKeyEvent* event, QGraphicsScene* scene) = 0;
    virtual void mouseDoubleClickEvent( QGraphicsSceneMouseEvent* event, QGraphicsScene* scene) = 0;
    virtual void mouseMoveEvent( QGraphicsSceneMouseEvent* event, QGraphicsScene* scene) = 0;
    virtual void mousePressEvent( QGraphicsSceneMouseEvent* event, QGraphicsScene* scene) = 0;
    virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent* event, QGraphicsScene* scene) = 0;

signals:
    
public slots:
    
};
Q_DECLARE_INTERFACE(IMapState, "edu.byu.cs.mapgraphics.IMapState")
#endif // ISCENESTATE_H
