#include "BuildDataViewWidget.h"

#include <QLabel>
#include <QString>
#include <QVariant>
#include <QVBoxLayout>

#include "Adapter/BuildDataTreeViewAdapter.h"
#include "Data/BuildData.h"

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

void BuildDataViewWidget::updateView() {
    this->v_view->clear();

    for(int i = 0; i < this->v_buildDataList.size(); i++) {
        BuildDataP d = this->v_buildDataList.at(i);

        this->v_view->addData(i,{QVariant(d->buildName() ),QVariant(d->debugPath() ),QVariant(d->releasePath() )});
    }

    this->v_view->resize();

    this->v_buildInfoL->setText("Build info ["+QString::number(this->v_buildDataList.size() )+"]");
}

QList<BuildDataP> BuildDataViewWidget::buildDataList() {
    return this->v_buildDataList;
}

QList<BuildDataP>* BuildDataViewWidget::buildDataListP() {
    return &this->v_buildDataList;
}

int BuildDataViewWidget::numberOfSelectedRows() {
    return this->v_view->numberOfSelectedRows();
}

QList<int> BuildDataViewWidget::selectedRowsPosition() {
    return this->v_view->selectedRowsPosition();
}

//Private functions
void BuildDataViewWidget::init() {
    this->v_buildInfoL = new QLabel("Build info [0]",this->v_p);
    this->v_view = new BuildDataTreeViewAdapter();

    this->v_buildInfoL->setAlignment(Qt::AlignCenter);

    this->v_vLayout->addWidget(this->v_buildInfoL);
    this->v_vLayout->addWidget(this->v_view->view() );

    this->updateView();
}
