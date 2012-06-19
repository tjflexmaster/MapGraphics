#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "ButtonDelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel* model = new QStandardItemModel();

    int total = 7;
    int row = 0;
    for ( int i=0; i < total; i++ ) {
        int col = i%3;
        if ( i%3 == 0 && i > 1 ) {
            row++;
        }
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        item->setToolTip("TEst");
        model->setItem(row, col, item);
    }



    QTableView* table = new QTableView();
    table->setItemDelegate(new ButtonDelegate);
    table->setModel(model);
    table->setHorizontalHeader(NULL);
    table->horizontalHeader()->hide();
    table->verticalHeader()->hide();
    table->setEditTriggers(0);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->resizeColumnsToContents();
    table->resizeRowsToContents();


    this->setCentralWidget(table);
}

MainWindow::~MainWindow()
{
    delete ui;
}
