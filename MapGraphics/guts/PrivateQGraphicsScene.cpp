#include "PrivateQGraphicsScene.h"

#include <QtDebug>
#include <QSet>

#include "MapGraphicsScene.h"
#include "IMapState.h"
#include <QSharedPointer>

PrivateQGraphicsScene::PrivateQGraphicsScene(MapGraphicsScene * mgScene,
                                             PrivateQGraphicsInfoSource *infoSource,
                                             QObject *parent) :
    QGraphicsScene(parent), _infoSource(infoSource)
{
    this->setMapGraphicsScene(mgScene);

    connect(this,
            SIGNAL(selectionChanged()),
            this,
            SLOT(handleSelectionChanged()));
}

//private slot
void PrivateQGraphicsScene::handleMGObjectAdded(MapGraphicsObject * added)
{
    PrivateQGraphicsObject * qgObj = new PrivateQGraphicsObject(added,_infoSource);
    this->addItem(qgObj);

    //We need a mapping of MapGraphicsObject : QGraphicsObject, so put this in the map
    _mgToqg.insert(added,qgObj);
}

//private slot
void PrivateQGraphicsScene::handleMGObjectRemoved(MapGraphicsObject * removed)
{
    if (!_mgToqg.contains(removed))
    {
        qWarning() << "There is no QGraphicsObject in the scene for" << removed;
        return;
    }

    QGraphicsObject * qgObj = _mgToqg.take(removed);
    delete qgObj;

    /*
      It turns out that removing or "deleting later" the PrivateQGraphicsObjects here was causing crashes.
      Instead, the PrivateQGraphicsObject watches the MapGraphicsObject's destroyed signal to
      delete itself. QGraphicsScene is smart enough to remove deleted objects in this case.
    /*
    if (!this->items().contains(qgObj))
    {
        qWarning() << this << "does not contain PrivateQGraphicsObject" << qgObj;
        return;
    }
    //qgObj->deleteLater();
    //this->removeItem(qgObj);
    */
}

void PrivateQGraphicsScene::handleZoomLevelChanged()
{
    foreach(PrivateQGraphicsObject * obj, _mgToqg.values())
        obj->handleZoomLevelChanged();
}

void PrivateQGraphicsScene::handleSelectionChanged()
{
    QList<QGraphicsItem *> selectedList = this->selectedItems();
    QSet<QGraphicsItem *> selected;
    foreach(QGraphicsItem * item, selectedList)
        selected.insert(item);

    foreach(PrivateQGraphicsObject * obj, _mgToqg.values())
    {
        QGraphicsItem * casted = (QGraphicsItem *) obj;
        obj->setSelected(selected.contains(casted));
    }

}

void PrivateQGraphicsScene::handleMapStateChanged(QSharedPointer<IMapState> state)
{
    setMapState(state);
}

//private
void PrivateQGraphicsScene::setMapGraphicsScene(MapGraphicsScene *mgScene)
{
    _mgScene = mgScene;

    if (_mgScene.isNull())
    {
        qWarning() << this << "got a null MapGraphicsScene";
        return;
    }

    connect(_mgScene.data(),
            SIGNAL(objectAdded(MapGraphicsObject*)),
            this,
            SLOT(handleMGObjectAdded(MapGraphicsObject*)));
    connect(_mgScene.data(),
            SIGNAL(objectRemoved(MapGraphicsObject*)),
            this,
            SLOT(handleMGObjectRemoved(MapGraphicsObject*)));

}

//private
void PrivateQGraphicsScene::setMapState(QSharedPointer<IMapState> state)
{
    //First remove the old state
    if ( !_mapState.isNull() )
        _mapState.clear();

    //Now set the new state
    _mapState = state;

}

//protected
void PrivateQGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "scene mouse double click";

    if (_mapState.isNull())
        return;

    _mapState->mouseDoubleClickEvent(event, this);


    if (!event->isAccepted())
        QGraphicsScene::mouseDoubleClickEvent(event);
}

//protected
void PrivateQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "scene mouse press";
    if (_mapState.isNull())
        return;

    _mapState->mousePressEvent(event, this);

    //Default Mouse Event if it is ignored by the State
    if (!event->isAccepted())
        QGraphicsScene::mousePressEvent(event);
}



//protected
void PrivateQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "scene move";

    if (_mapState.isNull())
        return;

    _mapState->mouseMoveEvent(event, this);


    if (!event->isAccepted())
        QGraphicsScene::mouseMoveEvent(event);
}

//protected
void PrivateQGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "mouse release";

    if (_mapState.isNull())
        return;

    _mapState->mouseReleaseEvent(event, this);


    if (!event->isAccepted())
        QGraphicsScene::mouseReleaseEvent(event);
}

//protected
void PrivateQGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "scene key press";
    if (_mapState.isNull())
        return;

    _mapState->keyPressEvent(event, this);

    if (!event->isAccepted())
        QGraphicsScene::keyPressEvent(event);
}

//protected
void PrivateQGraphicsScene::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "key release";
    if (_mapState.isNull())
        return;

    _mapState->keyReleaseEvent(event, this);

    if (!event->isAccepted())
        QGraphicsScene::keyReleaseEvent(event);
}

