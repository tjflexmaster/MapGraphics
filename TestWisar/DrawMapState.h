#ifndef DRAWMAPSTATE_H
#define DRAWMAPSTATE_H

#include "IMapState.h"

class DrawMapState : public IMapState
{
    Q_OBJECT
    Q_INTERFACES(IMapState)
public:
    Q_INVOKABLE DrawMapState();
    QString getName();
    QIcon getIcon();
    quint16 getLayerId();
    void setScene(QGraphicsScene* scene);
    QGraphicsView::DragMode getDragMode();

signals:

public slots:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    QGraphicsScene* _scene;
    quint16 _layer_id;
    QPoint _start;

};

#endif // DRAWMAPSTATE_H
