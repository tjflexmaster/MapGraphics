#ifndef MAPSTATEWIDGETVIEW_H
#define MAPSTATEWIDGETVIEW_H

#include <QWidget>

namespace Ui {
class MapStateWidgetView;
}

class MapStateWidgetView : public QWidget
{
    Q_OBJECT
    
public:
    explicit MapStateWidgetView(QWidget *parent = 0);
    ~MapStateWidgetView();
    
private:
    Ui::MapStateWidgetView *ui;
};

#endif // MAPSTATEWIDGETVIEW_H
