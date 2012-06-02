#include "MapWidget.h"
#include <QtGui>
#include <QDebug>
#include "MapGraphicsView.h"
#include <QMetaObject>
#include "MapGraphicsScene.h"
#include "SearchArea.h"

MapWidget::MapWidget(QWidget *parent) :
    QWidget(parent)
{
//    _view = new MapGraphicsView();

    SearchArea* area = new SearchArea();
    area->setRect( 10, 10, 30, 30);
    _scene = new MapGraphicsScene();
    _scene->addItem(area);
    _view2 = new QGraphicsView(_scene);

    QLabel* options = new QLabel("Map Options");

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(_view2, 0, 0);
    layout->addWidget(options, 0, 1);

    //Make the right column remain the same width
    layout->setColumnMinimumWidth(1, 300);
    layout->setColumnStretch(1, 0);

    setLayout(layout);
    setMouseTracking(true);
}

MapWidget::MapWidget(QMetaObject obj, QWidget *parent) :
    QWidget(parent)
{
    _view = new MapGraphicsView();
    _view->setMapState(obj);

    QLabel* options = new QLabel("Map Options");

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(_view, 0, 0);
    layout->addWidget(options, 0, 1);

    //Make the right column remain the same width
    layout->setColumnMinimumWidth(1, 300);
    layout->setColumnStretch(1, 0);

    setLayout(layout);
}

MapWidget::~MapWidget()
{
    delete(_view);
}

void MapWidget::setMapState(QMetaObject meta)
{
    qDebug() << "Set Map State";
    _view->setMapState(meta);

}
