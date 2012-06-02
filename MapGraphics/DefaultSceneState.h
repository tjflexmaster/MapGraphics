#ifndef DEFAULTSCENESTATE_H
#define DEFAULTSCENESTATE_H

#include "ISceneState.h"
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

#include "MapGraphics_global.h"

class MAPGRAPHICSSHARED_EXPORT DefaultSceneState : public ISceneState
{
    Q_OBJECT
    Q_INTERFACES(ISceneState)
public:
    explicit DefaultSceneState(DefaultSceneState *parent = 0);
    
    void setView( QGraphicsView* view );
    void keyPressEvent( QKeyEvent* event );
    void keyReleaseEvent( QKeyEvent* event);

//    void viewMouseDoubleClickEvent(QMouseEvent *event);
//    void viewMousePressEvent(QMouseEvent *event);
//    void viewMouseMoveEvent(QMouseEvent *event);
//    void viewMouseReleaseEvent(QMouseEvent *event);

    void mouseDoubleClickEvent( QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent( QGraphicsSceneMouseEvent* event);
    void mousePressEvent( QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent( QGraphicsSceneMouseEvent* event);


signals:
    
public slots:
    
};

#endif // DEFAULTSCENESTATE_H
