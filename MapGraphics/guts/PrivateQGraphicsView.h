#ifndef PRIVATEQGRAPHICSVIEW_H
#define PRIVATEQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QPointF>

class PrivateQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PrivateQGraphicsView(QWidget *parent = 0);
    PrivateQGraphicsView(QGraphicsScene* scene, QWidget * parent=0);
    virtual ~PrivateQGraphicsView();


protected:
    //virtual from QGraphicsView
    virtual void contextMenuEvent(QContextMenuEvent *event);

    //virtual from QGraphicsView
    virtual void wheelEvent(QWheelEvent *event);

    //Override view mouse events for controlling MapState
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void hadContextMenuEvent(QContextMenuEvent *);
    void hadWheelEvent(QWheelEvent *);
    
public slots:

};

#endif // PRIVATEQGRAPHICSVIEW_H
