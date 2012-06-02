#ifndef PRIVATEQGRAPHICSVIEW_H
#define PRIVATEQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QPointF>
#include "IMapState.h"
#include <QSharedPointer>

class PrivateQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PrivateQGraphicsView(QWidget *parent = 0);
    PrivateQGraphicsView(QGraphicsScene* scene, QWidget * parent=0);
    virtual ~PrivateQGraphicsView();

    /**
     * @brief Set the views state object for handling mouse and keyboard events.
     *
     * @param state
     */
    void setMapState(QSharedPointer<IMapState> state);

protected:
    //virtual from QGraphicsView
    virtual void contextMenuEvent(QContextMenuEvent *event);

    //virtual from QGraphicsView
    virtual void wheelEvent(QWheelEvent *event);

    //Override view mouse events for controlling MapState
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void hadContextMenuEvent(QContextMenuEvent *);
    void hadWheelEvent(QWheelEvent *);
    
public slots:

private slots:
    void handleMapStateChanged(QSharedPointer<IMapState>);

private:
    QSharedPointer<IMapState> _mapState;

};

#endif // PRIVATEQGRAPHICSVIEW_H
