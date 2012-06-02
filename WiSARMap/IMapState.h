#ifndef IMAPSTATE_H
#define IMAPSTATE_H

#include "WiSARMap_global.h"
#include <QObject>
#include <QIcon>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>

class WISARMAPSHARED_EXPORT IMapState : public QObject
{
    Q_OBJECT
public:
    virtual QString getName() = 0;
    virtual QIcon getIcon() = 0;
    virtual quint16 getLayerId() = 0;
    virtual void setScene(QGraphicsScene* scene) = 0;
    virtual QGraphicsView::DragMode getDragMode() = 0;

signals:
    
public slots:
    virtual void mousePressEvent(QMouseEvent *event) = 0;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) = 0;
    virtual void mouseMoveEvent(QMouseEvent *event) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *event) = 0;
    
};

Q_DECLARE_INTERFACE(IMapState, "cs.byu.edu.uewisar.IMapState")

#endif // IMAPSTATE_H
