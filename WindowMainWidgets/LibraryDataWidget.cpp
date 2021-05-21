#include "LibraryDataWidget.h"

//Public functions
LibraryDataWidget::LibraryDataWidget(QGridLayout* l,QString dataStr,bool name,QWidget* parent) : SingleLayoutWidget(parent) {
    this->v_gLayout = l;
    this->v_name = name;

    this->clearLayout(l);

}
