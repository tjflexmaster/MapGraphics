#ifndef MAPSTATEWIDGETCONTROLLER_H
#define MAPSTATEWIDGETCONTROLLER_H

#include <QObject>
#include "gui/mapstate/IMapStateWidgetController.h"

class MapStateWidgetController : public QObject, public IMapStateWidgetController
{
    Q_OBJECT
public:
    explicit MapStateWidgetController(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MAPSTATEWIDGETCONTROLLER_H
