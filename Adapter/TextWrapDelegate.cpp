#include "TextWrapDelegate.h"

//Public functions
TextWrapDelegate::TextWrapDelegate(int extraWidth,int extraHeight,int role,QWidget* parent) : QStyledItemDelegate(parent) {
    this->v_extraWidth = extraWidth;
    this->v_extraHeight = extraHeight;
    this->v_role = role;
}
