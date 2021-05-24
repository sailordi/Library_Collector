#include "BuildDataViewWidget.h"

#include <QVBoxLayout>

#include "Adapter/BuildDataTreeViewAdapter.h"

//Public functions
BuildDataViewWidget::BuildDataViewWidget(QVBoxLayout* l,QWidget* parent) : SingleLayoutWidget(parent) {
    this->clearLayout(l);

    this->v_vLayout =  l;

}

BuildDataViewWidget::~BuildDataViewWidget() {
    this->v_view->clear();
    delete this->v_view;
}
