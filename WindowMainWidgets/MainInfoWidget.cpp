#include "MainInfoWidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QTextBlockFormat>
#include <QTextCursor>
#include <QTextEdit>
#include <QSpacerItem>
#include <QPushButton>

const int MAX_EDIT_HEIGHT = 80;

//Public functions
MainInfoWidget::MainInfoWidget(QGridLayout* l,QWidget* parent) : SingleLayoutWidget(parent) {
    this->clearLayout(l);
    this->v_gLayout = l;

    this->init();
}

void MainInfoWidget::setOutputPath(QString outputPath) {
    this->v_outputPathE->setText(outputPath);

    QTextCursor cu = this->v_outputPathE->textCursor();

    cu.movePosition(QTextCursor::Start);

    while(cu.atEnd() == false) {
        QTextBlockFormat text = cu.blockFormat();

        text.setAlignment(Qt::AlignCenter);
        cu.mergeBlockFormat(text);

        if(cu.movePosition(QTextCursor::NextBlock) == false) {
            break;
        }
    }

    this->v_outputPathE->setTextCursor(cu);
}

void MainInfoWidget::setHeaderPath(QString headerPath) {
    this->v_headerPathE->setText(headerPath);

    QTextCursor cu = this->v_headerPathE->textCursor();

    cu.movePosition(QTextCursor::Start);

    while(cu.atEnd() == false) {
        QTextBlockFormat text = cu.blockFormat();

        text.setAlignment(Qt::AlignCenter);
        cu.mergeBlockFormat(text);

        if(cu.movePosition(QTextCursor::NextBlock) == false) {
            break;
        }
    }

    this->v_headerPathE->setTextCursor(cu);
}

void MainInfoWidget::setLibraryBaseName(QString libraryBaseName) {
    this->v_libraryBaseNameE->setText(libraryBaseName);
}

void MainInfoWidget::setBaseBuildNameSeparator(QString baseBuildNameSeparator) {
    this->v_baseBuildNameSeparatorE->setText(baseBuildNameSeparator);
}

QString MainInfoWidget::outputPath() {
    return this->v_outputPathE->toPlainText();
}

QString MainInfoWidget::headerPath() {
    return this->v_headerPathE->toPlainText();
}

QString MainInfoWidget::libraryBaseName() {
    return this->v_libraryBaseNameE->text();
}

QString MainInfoWidget::baseBuildNameSeparator() {
    return this->v_baseBuildNameSeparatorE->text();
}

QPushButton* MainInfoWidget::outputPathButton() {
    return this->v_outputPathB;
}

QPushButton* MainInfoWidget::headerPathButton() {
    return this->v_headerPathB;
}

//Private functions
void MainInfoWidget::init() {
    QLabel* outputPathL = new QLabel("Library output path",this->v_p);
    QLabel* headerPathL = new QLabel("Library header path",this->v_p);
    QLabel* libraryBaseNameL = new QLabel("Library base name: ",this->v_p);
    QLabel* baseBuildNameSeparatorL = new QLabel("Base build name separator: ",this->v_p);


    this->v_outputPathE = new QTextEdit(this->v_p);
    this->v_headerPathE = new QTextEdit(this->v_p);
    this->v_libraryBaseNameE = new QLineEdit(this->v_p);
    this->v_baseBuildNameSeparatorE = new QLineEdit(this->v_p);

    this->v_outputPathB = new QPushButton("Select output path",this->v_p);
    this->v_headerPathB = new QPushButton("Select header path",this->v_p);

    outputPathL->setAlignment(Qt::AlignCenter);
    headerPathL->setAlignment(Qt::AlignCenter);
    libraryBaseNameL->setAlignment(Qt::AlignCenter);
    baseBuildNameSeparatorL->setAlignment(Qt::AlignCenter);

    this->v_outputPathE->setMaximumHeight(MAX_EDIT_HEIGHT);
    this->v_outputPathE->setLineWrapMode(QTextEdit::WidgetWidth);

    this->v_headerPathE->setMaximumHeight(MAX_EDIT_HEIGHT);
    this->v_headerPathE->setLineWrapMode(QTextEdit::WidgetWidth);

    this->v_headerPathE->setReadOnly(true);
    this->v_outputPathE->setReadOnly(true);

    this->v_libraryBaseNameE->setAlignment(Qt::AlignCenter);
    this->v_baseBuildNameSeparatorE->setAlignment(Qt::AlignCenter);

    int row = 0;

    this->v_gLayout->addWidget(outputPathL,row++,0,1,2);
    this->v_gLayout->addWidget(this->v_outputPathE,row++,0,1,2);
    this->v_gLayout->addWidget(this->v_outputPathB,row++,0,1,2);
    this->v_gLayout->addItem(new QSpacerItem(5,5,QSizePolicy::Fixed,QSizePolicy::Fixed),row++,0,1,2);
    this->v_gLayout->addWidget(headerPathL,row++,0,1,2);
    this->v_gLayout->addWidget(this->v_headerPathE,row++,0,1,2);
    this->v_gLayout->addWidget(this->v_headerPathB,row++,0,1,2);
    this->v_gLayout->addItem(new QSpacerItem(5,5,QSizePolicy::Fixed,QSizePolicy::Fixed),row++,0,1,2);
    this->v_gLayout->addWidget(libraryBaseNameL,row,0,1,1);
    this->v_gLayout->addWidget(this->v_libraryBaseNameE,row,1,1,1);
    this->v_gLayout->addItem(new QSpacerItem(5,5,QSizePolicy::Fixed,QSizePolicy::Fixed),row++,0,1,2);
    this->v_gLayout->addWidget(baseBuildNameSeparatorL,row,0,1,1);
    this->v_gLayout->addWidget(this->v_baseBuildNameSeparatorE,row,1,1,1);
}
