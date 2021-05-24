#include "TextWrapDelegate.h"

#include <QApplication>
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QTextDocument>
#include <QPainter>
#include <QSize>

//Public functions
TextWrapDelegate::TextWrapDelegate(int extraWidth,int extraHeight,int role,QWidget* parent) : QStyledItemDelegate(parent) {
    this->v_extraWidth = extraWidth;
    this->v_extraHeight = extraHeight;
    this->v_role = role;
}

void TextWrapDelegate::paint(QPainter* painter,const QStyleOptionViewItem& option,const QModelIndex& index) const {
    QString text = index.model()->data(index,this->v_role).toString();
    QTextDocument doc;

        doc.setDefaultFont(QFont("Times New Roman",15) );
        doc.setHtml(text);
        doc.setTextWidth(option.rect.width() );

        QStyledItemDelegate::paint(painter,option,index);

        painter->save();

        painter->translate(option.rect.x(),option.rect.y() );

        doc.drawContents(painter);

        painter->restore();
}

QSize TextWrapDelegate::sizeHint(const QStyleOptionViewItem& option,const QModelIndex& index) const {
    QString text = index.model()->data(index,this->v_role).toString();
    QTextDocument doc;

        doc.setHtml(text);
        doc.setTextWidth(option.rect.width() );

        return QSize(doc.idealWidth()+this->v_extraWidth,doc.size().height()+this->v_extraHeight);
}
