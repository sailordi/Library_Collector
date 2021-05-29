#include "ExcludePathsViewWidget.h"

#include <QHeaderView>
#include <QLabel>
#include <QVBoxLayout>

#include "Base/Adapter/TreeViewAdapterNoChildRows.h"

//Public functions
ExcludePathsViewWidget::ExcludePathsViewWidget(QVBoxLayout* l,QWidget* parent) : SingleLayoutWidget(parent) {
    this->clearLayout(l);
    this->v_vLayout = l;

    this->init();
}

ExcludePathsViewWidget::~ExcludePathsViewWidget() {
    this->v_excludedPathList.clear();
    delete this->v_view;
}

QList<QString> ExcludePathsViewWidget::excludedPathsList() {
    return this->v_excludedPathList;
}

QList<QString>* ExcludePathsViewWidget::excludedPathsListP() {
    return &this->v_excludedPathList;
}

//Private functions
void ExcludePathsViewWidget::init() {
    this->v_excludedPathsL = new QLabel(this->v_p);
    this->v_view = new TreeViewAdapterNoChildRows(new QTreeView(),true);

    this->v_view->setHeaders({Qt::AlignCenter},{"Path"});

    QString str = "QTreeView{outline:0;}";
    str.append("QTreeView::item:selected{background-color: #D5E9F8;color: black;}");
    str.append("QTreeView::item{padding:2px;font: 16pt Times New Roman;border: 1px solid rgb(0,0,0);}");
    str.append("QTreeView::item:has-children{border: 1px solid rgb(0,0,0);}");

    this->v_view->view()->setStyleSheet(str);
    this->v_view->view()->header()->setFont(QFont("Times New Roman",16) );
    this->v_view->view()->setFont(QFont("Times New Roman",16) );

    this->v_excludedPathsL->setAlignment(Qt::AlignCenter);

    this->v_vLayout->addWidget(this->v_excludedPathsL);
    this->v_vLayout->addWidget(this->v_view->view() );

}

