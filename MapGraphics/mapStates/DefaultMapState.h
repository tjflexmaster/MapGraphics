#ifndef DEFAULTMAPSTATE_H
#define DEFAULTMAPSTATE_H

#include "IMapState.h"
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "MapGraphics_global.h"

class MAPGRAPHICSSHARED_EXPORT DefaultMapState : public IMapState
{
    Q_OBJECT
    Q_INTERFACES(IMapState)
public:
    explicit DefaultMapState(DefaultMapState *parent = 0);
    
    void viewKeyPressEvent( QKeyEvent* event, QGraphicsView* view);
    void viewKeyReleaseEvent( QKeyEvent* event, QGraphicsView* view);
    void viewMouseDoubleClickEvent(QMouseEvent *event, QGraphicsView* view);
    void viewMousePressEvent(QMouseEvent *event, QGraphicsView* view);
    void viewMouseMoveEvent(QMouseEvent *event, QGraphicsView* view);
    void viewMouseReleaseEvent(QMouseEvent *event, QGraphicsView* view);

    void keyPressEvent( QKeyEvent* event, QGraphicsScene* scene);
    void keyReleaseEvent( QKeyEvent* event, QGraphicsScene* scene);
    void mouseDoubleClickEvent( QGraphicsSceneMouseEvent* event, QGraphicsScene* scene);
    void mouseMoveEvent( QGraphicsSceneMouseEvent* event, QGraphicsScene* scene);
    void mousePressEvent( QGraphicsSceneMouseEvent* event, QGraphicsScene* scene);
    void mouseReleaseEvent( QGraphicsSceneMouseEvent* event, QGraphicsScene* scene);


signals:
    
public slots:
    
};

#endif // DEFAULTSCENESTATE_H
