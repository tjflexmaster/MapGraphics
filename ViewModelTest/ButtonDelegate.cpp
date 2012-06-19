#include "ButtonDelegate.h"
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QImage>
#include <QSize>

ButtonDelegate::ButtonDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//    if ( !index.data(Qt::DisplayRole).isNull() ) {
        painter->save();

//        QStyleOptionViewItemV4 opt( option );
//        initStyleOption(&opt, index);

        QImage image(":/images/assets/ic_menu_globe.png");
        painter->drawImage(option.rect.topLeft(), image, QRect(0,0,72,72));

        painter->restore();
//    } else {
//        QStyledItemDelegate::paint(painter, option, index);
//    }
}

QSize ButtonDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(72, 72);
}
