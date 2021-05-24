#include "BuildDataWidget.h"

#include <QHBoxLayout>
#include <QGridLayout>

enum HLAYOUT{BUILD_NAMEL,DEBUG_PathL,RELEASE_PATHL,SIZEL};

//Public functions
BuildDataWidget::BuildDataWidget(QGridLayout* l,QWidget* parent) : MultiLayoutWidget(parent) {
    this->clearLayout(l);

    this->v_gLayouts.push_back(l);

    for(int i = 0; i < SIZEL; i++) {
        this->v_hLayouts.push_back(new QHBoxLayout() );
    }

}
