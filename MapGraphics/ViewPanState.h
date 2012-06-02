#ifndef VIEWPANSTATE_H
#define VIEWPANSTATE_H

#include "ISceneState.h"
#include <QObject>
#include "MapGraphics_global.h"

class MAPGRAPHICSSHARED_EXPORT ViewPanState : public ISceneState
{
    Q_OBJECT
    Q_INTERFACES(ISceneState)
public:
    explicit ViewPanState(ISceneState *parent = 0);

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
    
private:
    QGraphicsView* _view;
    qint32 _pan_x, _pan_y;
    bool _panning;
};

#endif // VIEWPANSTATE_H
