#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include "WiSARMap_global.h"
#include <QWidget>
#include <QtGui>
#include "MapGraphicsView.h"
#include <QMetaObject>
#include "MapGraphicsScene.h"

class WISARMAPSHARED_EXPORT MapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = 0);
    MapWidget(QMetaObject obj, QWidget* parent = 0);
    ~MapWidget();
    void setMapState(QMetaObject meta);

private:
    MapGraphicsView* _view;
    QGraphicsView* _view2;
    MapGraphicsScene* _scene;

signals:
    
public slots:
    
};

#endif // MAPWIDGET_H
