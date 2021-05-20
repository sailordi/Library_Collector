#include "WindowMain.h"
#include "ui_WindowMain.h"

#include <QFileDialog>

//Public functions
WindowMain::WindowMain(QWidget *parent) : QMainWindow(parent), v_ui(new Ui::WindowMain) {
    this->v_ui->setupUi(this);

    connect(this->v_ui->libraryOutPath_btn,&QPushButton::clicked,this,&WindowMain::libraryOutPathBtnClicked);
}

WindowMain::~WindowMain() {
    delete this->v_ui;
}

//Private slots
void WindowMain::libraryOutPathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library output path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_ui->libraryOutPath_edit->setText(str);
}
