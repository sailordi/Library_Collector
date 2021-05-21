#include "LibraryDataWidget.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextBlockFormat>
#include <QTextCursor>
#include <QTextEdit>
#include <QPushButton>
#include <QSpacerItem>

//Public functions
LibraryDataWidget::LibraryDataWidget(QGridLayout* l,QString dataStr,bool name,QWidget* parent) : SingleLayoutWidget(parent) {
    this->v_gLayout = l;
    this->v_name = name;

    this->clearLayout(l);

    this->init(dataStr);
}

//Private functions
void LibraryDataWidget::init(QString dataStr) {
    this->v_dataL = new QLabel(dataStr,this->v_p);
    this->v_pathL = new QLabel("Path: ",this->v_p);
    this->v_pathE = new QTextEdit(this->v_p);
    this->v_selBtn = new QPushButton("Select path",this->v_p);

    this->v_dataL->setAlignment(Qt::AlignCenter);

    this->v_pathE->setLineWrapMode(QTextEdit::WidgetWidth);
    this->v_pathE->setMaximumHeight(50);

    int row = 0;

    this->v_gLayout->addWidget(this->v_dataL,row++,0,1,2);

    this->v_gLayout->addItem(new QSpacerItem(0,5,QSizePolicy::Fixed,QSizePolicy::Fixed),row++,0,1,2);

    this->v_gLayout->addWidget(this->v_pathL,row,0,1,1);
    this->v_gLayout->addWidget(this->v_pathE,row++,1,1,1);

    this->v_gLayout->addWidget(this->v_selBtn,row++,0,1,2);

    if(this->v_name == true) {
      this->v_nameL = new QLabel("Name: ",this->v_p);
      this->v_nameE = new QLineEdit(this->v_p);

      this->v_nameE->setAlignment(Qt::AlignCenter);

      this->v_gLayout->addItem(new QSpacerItem(0,5,QSizePolicy::Fixed,QSizePolicy::Fixed),row++,0,1,2);
      this->v_gLayout->addWidget(this->v_nameL,row,0,1,1);
      this->v_gLayout->addWidget(this->v_nameE,row,1,1,1);
    }

}
