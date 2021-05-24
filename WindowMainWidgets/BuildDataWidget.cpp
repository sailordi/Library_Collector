#include "BuildDataWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QTextEdit>
#include <QSpacerItem>
#include <QPushButton>

enum HLAYOUT{BUILD_NAMEL,DEBUG_PathL,RELEASE_PATHL,SIZEL};

const int MAX_EDIT_HEIGHT = 80;

//Public functions
BuildDataWidget::BuildDataWidget(QGridLayout* l,QWidget* parent) : MultiLayoutWidget(parent) {
    this->clearLayout(l);

    this->v_gLayouts.push_back(l);

    for(int i = 0; i < SIZEL; i++) {
        this->v_hLayouts.push_back(new QHBoxLayout() );
    }

    this->init();
}

//Private functions
void BuildDataWidget::init() {
    QLabel* buildNameL = new QLabel("Build name",this->v_p);
    QLabel* debugPathL = new QLabel("Debug path",this->v_p);
    QLabel* releasePathL = new QLabel("Release path",this->v_p);

    this->v_buildNameE = new QLineEdit(this->v_p);
    this->v_debugPathE = new QTextEdit(this->v_p);
    this->v_releasePathE = new QTextEdit(this->v_p);

    this->v_debugPathB = new QPushButton("Select debug path",this->v_p);
    this->v_releasePathB = new QPushButton("Select release path",this->v_p);

    this->v_resetBuildNameB  = new QPushButton("Reset",this->v_p);
    this->v_resetDebugPathB = new QPushButton("Reset",this->v_p);
    this->v_resetReleasePathB = new QPushButton("Reset",this->v_p);

    buildNameL->setAlignment(Qt::AlignCenter);
    debugPathL->setAlignment(Qt::AlignCenter);
    releasePathL->setAlignment(Qt::AlignCenter);

    this->v_buildNameE->setAlignment(Qt::AlignCenter);

    this->v_debugPathE->setLineWrapMode(QTextEdit::WidgetWidth);
    this->v_debugPathE->setMaximumHeight(MAX_EDIT_HEIGHT);

    this->v_releasePathE->setLineWrapMode(QTextEdit::WidgetWidth);
    this->v_releasePathE->setMaximumHeight(MAX_EDIT_HEIGHT);

    this->v_hLayouts[BUILD_NAMEL]->addWidget(this->v_buildNameE);
    this->v_hLayouts[BUILD_NAMEL]->addWidget(this->v_resetBuildNameB);
    this->v_hLayouts[DEBUG_PathL]->addWidget(this->v_debugPathB);
    this->v_hLayouts[DEBUG_PathL]->addWidget(this->v_resetDebugPathB);
    this->v_hLayouts[RELEASE_PATHL]->addWidget(this->v_releasePathB);
    this->v_hLayouts[RELEASE_PATHL]->addWidget(this->v_resetReleasePathB);

    int row = 0;

    this->v_gLayouts[0]->addWidget(buildNameL,row++,0,1,1);
    this->v_gLayouts[0]->addLayout(this->v_hLayouts[BUILD_NAMEL],row++,0,1,1);
    this->v_gLayouts[0]->addItem(new QSpacerItem(10,20,QSizePolicy::Expanding,QSizePolicy::Expanding),row++,0,1,1);
    this->v_gLayouts[0]->addWidget(debugPathL,row++,0,1,1);
    this->v_gLayouts[0]->addWidget(this->v_debugPathE,row++,0,1,1);
    this->v_gLayouts[0]->addLayout(this->v_hLayouts[DEBUG_PathL],row++,0,1,1);
    this->v_gLayouts[0]->addItem(new QSpacerItem(10,20,QSizePolicy::Expanding,QSizePolicy::Expanding),row++,0,1,1);
    this->v_gLayouts[0]->addWidget(releasePathL,row++,0,1,1);
    this->v_gLayouts[0]->addWidget(this->v_releasePathE,row++,0,1,1);
    this->v_gLayouts[0]->addLayout(this->v_hLayouts[RELEASE_PATHL],row++,0,1,1);
}
