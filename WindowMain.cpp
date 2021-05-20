#include "WindowMain.h"
#include "ui_WindowMain.h"

#include <QFileDialog>

//Public functions
WindowMain::WindowMain(QWidget *parent) : QMainWindow(parent), v_ui(new Ui::WindowMain) {
    this->v_ui->setupUi(this);

    connect(this->v_ui->libraryOutPath_btn,&QPushButton::clicked,this,&WindowMain::libraryOutPathBtnClicked);

    connect(this->v_ui->libraryHeaderPath_btn,&QPushButton::clicked,this,&WindowMain::libraryHeaderPathBtnClicked);

    connect(this->v_ui->libraryDebugPath_btn,&QPushButton::clicked,this,&WindowMain::libraryDebugPathBtnClicked);
    connect(this->v_ui->libraryReleasePath_btn,&QPushButton::clicked,this,&WindowMain::libraryReleasePathBtnClicked);
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

void WindowMain::libraryHeaderPathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library header path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_ui->libraryHeaderPath_edit->setText(str);
}

void WindowMain::libraryDebugPathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library debug path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_ui->libraryDebugPath_edit->setText(str);
}

void WindowMain::libraryReleasePathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library release path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_ui->libraryReleasePath_edit->setText(str);
}
