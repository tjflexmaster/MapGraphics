#include "PrivateQGraphicsScene.h"

#include <QtDebug>
#include <QSet>

#include "MapGraphicsScene.h"
#include "ISceneState.h"
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

void PrivateQGraphicsScene::handleSceneStateChanged(QSharedPointer<ISceneState> state)
{
    _sceneState = state;
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
void PrivateQGraphicsScene::setSceneState(QSharedPointer<ISceneState> state)
{
    //First remove the old state
    if ( !_sceneState.isNull() )
        _sceneState.clear();

    //Now set the new state
    _sceneState = state;

//    if ( _sceneState.isNull() ) {
//        qWarning() << this << "got a null State";
//        return;
//    }
}


//protected
void PrivateQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "scene mouse press";
    if (_sceneState.isNull())
        return;

    _sceneState->mousePressEvent(event);



    if (!event->isAccepted())
        QGraphicsScene::mousePressEvent(event);
}

//protected
void PrivateQGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "scene mouse double click";

    if (_sceneState.isNull())
        return;

    _sceneState->mouseDoubleClickEvent(event);


    if (!event->isAccepted())
        QGraphicsScene::mouseDoubleClickEvent(event);
}

//protected
void PrivateQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "scene move";

    if (_sceneState.isNull())
        return;

    _sceneState->mouseMoveEvent(event);


    if (!event->isAccepted())
        QGraphicsScene::mouseMoveEvent(event);
}

//protected
void PrivateQGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "mouse release";

    if (_sceneState.isNull())
        return;

    _sceneState->mouseReleaseEvent(event);


    if (!event->isAccepted())
        QGraphicsScene::mouseReleaseEvent(event);
}

//protected
void PrivateQGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    if (_sceneState.isNull())
        return;

    _sceneState->keyPressEvent(event);

    qDebug() << "key press" <<  event->isAccepted();

    if (!event->isAccepted())
        QGraphicsScene::keyPressEvent(event);
}

//protected
void PrivateQGraphicsScene::keyReleaseEvent(QKeyEvent *event)
{
    if (_sceneState.isNull())
        return;

    _sceneState->keyReleaseEvent(event);

    qDebug() << "key release" <<  event->isAccepted();

    if (!event->isAccepted())
        QGraphicsScene::keyReleaseEvent(event);
}

