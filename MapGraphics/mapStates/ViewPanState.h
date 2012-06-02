#ifndef VIEWPANSTATE_H
#define VIEWPANSTATE_H

#include "IMapState.h"
#include <QObject>
#include "MapGraphics_global.h"

/**
 * @brief This State pans the QGraphicsView viewport around the scene.
 * It blocks all mouse events to the scene and it's items.
 * The only way to do this smoothly is by changing the QGraphicsView
 * scrollbar positions.
 *
 * Look at this thread for an example
 * http://stackoverflow.com/questions/4753681/how-to-pan-images-in-qgraphicsview
 */
class MAPGRAPHICSSHARED_EXPORT ViewPanState : public IMapState
{
    Q_OBJECT
    Q_INTERFACES(IMapState)
public:
    explicit ViewPanState(IMapState *parent = 0);

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
    
private:
    qint32 _pan_x, _pan_y;
    bool _panning;
};

#endif // VIEWPANSTATE_H
