#include "MainWindow.h"
#include "MapWidget.h"
#include "DrawMapState.h"
#include "SearchArea.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "TestGraphicsScene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

//    MapWidget* map = new MapWidget();
//    map->setMapState(DrawMapState::staticMetaObject);

//    QGraphicsScene* scene = new QGraphicsScene(0,0,500,500);

//    SearchArea* area = new SearchArea();
//    area->setRect(10,10,30,30);
//    scene->addItem( area );

//    QGraphicsView* view = new QGraphicsView(scene);

    SearchArea* area = new SearchArea();
    area->setRect( 10, 10, 30, 30);
//    MapGraphicsScene* _scene = new MapGraphicsScene();
    TestGraphicsScene* _scene = new TestGraphicsScene();
    _scene->addItem(area);
    QGraphicsView* view = new QGraphicsView(_scene);

    this->setCentralWidget(view);
    this->show();
}

MainWindow::~MainWindow()
{
    
}
