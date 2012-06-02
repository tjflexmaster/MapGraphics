#ifndef TESTGRAPHICSSCENE_H
#define TESTGRAPHICSSCENE_H

#include "WiSARMap_global.h"
#include <QGraphicsScene>
#include "SearchArea.h"
#include <QPointF>

class WISARMAPSHARED_EXPORT TestGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TestGraphicsScene(QGraphicsScene *parent = 0);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
signals:
    
public slots:

private:
    SearchArea* _current_item;
    QPointF _start_point;
    bool _drawing;
    quint8 _zoom_level;
    quint16 _tile_size;
    
};

#endif // TESTGRAPHICSSCENE_H
