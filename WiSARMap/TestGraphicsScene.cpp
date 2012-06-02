#include "TestGraphicsScene.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QDebug>
#include <cmath>

TestGraphicsScene::TestGraphicsScene(QGraphicsScene *parent) :
    QGraphicsScene(parent)
{

    _current_item = 0;
    _start_point = QPointF(0,0);
    _drawing = false;

    _zoom_level = 5;
    _tile_size = 256;

    long double tilecount = pow(4.0, _zoom_level);
    long double tiledepthcount = sqrt(tilecount);
    long double pixelcount = tiledepthcount * _tile_size;
    const QRectF scene_rect(0,0, pixelcount, pixelcount);
    this->setSceneRect(scene_rect);
}

void TestGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);

    if ( !event->isAccepted() ) {
        qDebug() << "Mouse Click2";
        if ( items().contains(_current_item) ) {
            removeItem(_current_item);
            delete(_current_item);
            _current_item = 0;
        }
        _start_point = event->scenePos();
        _current_item = new SearchArea();

        _current_item->setBrush(QBrush(Qt::blue));
        _current_item->setOpacity(0.25);
        addItem(_current_item);
        _drawing = true;
    }
}

void TestGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    if ( !event->isAccepted() ) {
        qDebug() << "Mouse Move";
        if ( _drawing ) {
            qDebug() << "Scene Mouse Move";
            QRectF rect(_start_point, event->scenePos());
            _current_item->setRect(rect.normalized());
        } else {
            event->setAccepted(false);
        }
    }
}

void TestGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
    if ( !event->isAccepted() ) {
        qDebug() << "Mouse Release";
        _start_point = QPointF(0,0);
        _drawing = false;
    }
}
