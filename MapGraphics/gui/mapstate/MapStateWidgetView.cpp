#include "MapStateWidgetView.h"
#include "ui_MapStateWidgetView.h"

MapStateWidgetView::MapStateWidgetView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapStateWidgetView)
{
    ui->setupUi(this);
}

MapStateWidgetView::~MapStateWidgetView()
{
    delete ui;
}
