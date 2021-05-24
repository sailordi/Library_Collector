#include "BuildDataWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QTextEdit>
#include <QSpacerItem>
#include <QPushButton>

#include "Data/BuildData.h"

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

void BuildDataWidget::setOldData(int oldDataPosition,BuildDataP data) {
    this->v_oldDataPosition = oldDataPosition;
    this->v_oldBuildData = data;

    this->v_buildNameE->setText(data->buildName() );
    this->v_debugPathE->setText(data->debugPath() );
    this->v_releasePathE->setText(data->releasePath() );
}

void BuildDataWidget::setBuildName(QString buildName) {
    this->v_buildNameE->setText(buildName);
}

void BuildDataWidget::setDebugPath(QString debugPath) {
    this->v_debugPathE->setText(debugPath);
}

void BuildDataWidget::setReleasePath(QString releasePath) {
    this->v_releasePathE->setText(releasePath);
}

void BuildDataWidget::updateOldData() {
    if(this->v_oldBuildData.isNull() == true) {
        return;
    }
    QString bN = this->v_buildNameE->text();
    QString dP = this->v_debugPathE->toPlainText();
    QString rP = this->v_releasePathE->toPlainText();

    if(bN.isEmpty() == false) {
        this->v_oldBuildData->setBuildName(bN);
    }
    if(dP.isEmpty() == false) {
        this->v_oldBuildData->setDebugPath(dP);
    }
    if(rP.isEmpty() == false) {
        this->v_oldBuildData->setReleasePath(rP);
    }

}

int BuildDataWidget::oldDataPosition() {
    return this->v_oldDataPosition;
}

BuildDataP BuildDataWidget::oldData() {
    return this->v_oldBuildData;
}

QString BuildDataWidget::buildName() {
    return this->v_buildNameE->text();
}

QString BuildDataWidget::debugPath() {
    return this->v_debugPathE->toPlainText();
}

QString BuildDataWidget::releasePath() {
    return this->v_releasePathE->toPlainText();
}

QPushButton* BuildDataWidget::debugPathButton() {
    return this->v_debugPathB;
}

QPushButton* BuildDataWidget::releasePathButton() {
    return this->v_releasePathB;
}

void BuildDataWidget::clear(bool onlyText) {
    this->v_buildNameE->setText("");
    this->v_debugPathE->setText("");
    this->v_releasePathE->setText("");

    if(onlyText == false) {
        this->v_oldBuildData = nullptr;
        this->v_oldDataPosition = -1;
    }

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
