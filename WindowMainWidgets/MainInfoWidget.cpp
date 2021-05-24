#include "MainInfoWidget.h"

//Public functions
MainInfoWidget::MainInfoWidget(QGridLayout* l,QWidget* parent) : SingleLayoutWidget(parent) {
    this->clearLayout(l);
    this->v_gLayout = l;

}
