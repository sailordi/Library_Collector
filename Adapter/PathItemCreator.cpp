#include "PathItemCreator.h"

//Public functions
PathItemCreator::PathItemCreator() : StandardItemCreator() {

}

QStandardItem* PathItemCreator::nonEditable(QVariant data,Qt::AlignmentFlag aligment) {
    QStandardItem* it = new QStandardItem();

        it->setData(data,Qt::UserRole+1);
        it->setData(QColor("black"),Qt::TextColorRole);
        it->setData(aligment,Qt::TextAlignmentRole);

        it->setFlags(it->flags() | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        it->setFlags(it->flags() ^ Qt::ItemIsEditable);

        return it;
}
