#include "ExcludePathsViewWidget.h"

#include <QVBoxLayout>

#include "Base/Adapter/TreeViewAdapterNoChildRows.h"

//Public functions
ExcludePathsViewWidget::ExcludePathsViewWidget(QVBoxLayout* l,QWidget* parent) : SingleLayoutWidget(parent) {
    this->clearLayout(l);
    this->v_vLayout = l;


}

ExcludePathsViewWidget::~ExcludePathsViewWidget() {
    this->v_excludedPathList.clear();
    delete this->v_view;
}

