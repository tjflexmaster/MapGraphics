#ifndef DEFAULTMAPSTATE_H
#define DEFAULTMAPSTATE_H

#include "WiSARMap_global.h"
#include "IMapState.h"

class WISARMAPSHARED_EXPORT DefaultMapState : public IMapState
{
    Q_OBJECT
    Q_INTERFACES(IMapState)
public:
    Q_INVOKABLE DefaultMapState();
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
};

#endif // DEFAULTMAPSTATE_H
