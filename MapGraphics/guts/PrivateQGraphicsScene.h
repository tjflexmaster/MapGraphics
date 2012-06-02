#ifndef PRIVATEQGRAPHICSSCENE_H
#define PRIVATEQGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QHash>
#include <QPointer>
#include <QWeakPointer>
#include <QSharedPointer>

#include "MapGraphicsScene.h"
#include "MapGraphicsObject.h"
#include "PrivateQGraphicsObject.h"
#include "guts/PrivateQGraphicsInfoSource.h"
#include "ISceneState.h"

class PrivateQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PrivateQGraphicsScene(MapGraphicsScene * mgScene,
                                   PrivateQGraphicsInfoSource * infoSource,
                                   QObject *parent = 0);
    /**
     * @brief Set the state of the scene to control what the mouse does inside of the view.
     *
     * @param state
     */
    void setSceneState(QSharedPointer<ISceneState> state);

protected:
    void keyPressEvent( QKeyEvent* event );
    void keyReleaseEvent( QKeyEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
    
public slots:

private slots:
    void handleMGObjectAdded(MapGraphicsObject *);
    void handleMGObjectRemoved(MapGraphicsObject *);
    void handleZoomLevelChanged();
    void handleSceneStateChanged(QSharedPointer<ISceneState>);
    void handleSelectionChanged();

private:
    void setMapGraphicsScene(MapGraphicsScene * mgScene);


    QPointer<MapGraphicsScene> _mgScene;
    PrivateQGraphicsInfoSource * _infoSource;

    QHash<MapGraphicsObject *,PrivateQGraphicsObject *> _mgToqg;
    QSharedPointer<ISceneState> _sceneState;
    
};

#endif // PRIVATEQGRAPHICSSCENE_H
