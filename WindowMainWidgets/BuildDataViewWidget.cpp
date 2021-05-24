#include "BuildDataViewWidget.h"

#include <QLabel>
#include <QVBoxLayout>

#include "Adapter/BuildDataTreeViewAdapter.h"

//Public functions
BuildDataViewWidget::BuildDataViewWidget(QVBoxLayout* l,QWidget* parent) : SingleLayoutWidget(parent) {
    this->clearLayout(l);

    this->v_vLayout =  l;

    this->init();
}

BuildDataViewWidget::~BuildDataViewWidget() {
    this->v_view->clear();
    delete this->v_view;
}

//Private functions
void BuildDataViewWidget::init() {
    this->v_buildInfoL = new QLabel("Build info [0]",this->v_p);
    this->v_view = new BuildDataTreeViewAdapter();

    this->v_buildInfoL->setAlignment(Qt::AlignCenter);

    this->v_vLayout->addWidget(this->v_buildInfoL);
    this->v_vLayout->addWidget(this->v_view->view() );
}
