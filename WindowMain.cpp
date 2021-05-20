#include "WindowMain.h"
#include "ui_WindowMain.h"

#include <QFileDialog>

#include "Data/Collector.h"

//Public functions
WindowMain::WindowMain(QWidget *parent) : QMainWindow(parent), v_ui(new Ui::WindowMain) {
    this->v_ui->setupUi(this);

    connect(this->v_ui->libraryOutPath_btn,&QPushButton::clicked,this,&WindowMain::libraryOutPathBtnClicked);

    connect(this->v_ui->libraryHeaderPath_btn,&QPushButton::clicked,this,&WindowMain::libraryHeaderPathBtnClicked);

    connect(this->v_ui->libraryDebugPath_btn,&QPushButton::clicked,this,&WindowMain::libraryDebugPathBtnClicked);
    connect(this->v_ui->libraryReleasePath_btn,&QPushButton::clicked,this,&WindowMain::libraryReleasePathBtnClicked);

    connect(this->v_ui->preformCollection_btn,&QPushButton::clicked,this,&WindowMain::preformCollectionBtnClicked);
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

void WindowMain::preformCollectionBtnClicked() {
    QString outP = this->v_ui->libraryOutPath_edit->toPlainText();
    QString outN = this->v_ui->libraryOutName_edit->text();

        if(outP.isEmpty() == true) {
            return;
        }
        else if(outN.isEmpty() == true) {
            return;
        }

        QString outPut = Collector::formatOutPath(outP,outN);
        QString in = Collector::formatOutPath(outPut,"includes");
        QString lib = Collector::formatOutPath(outPut,"libs");

        Collector::createPath(outPut);
        Collector::createPath(in);
        Collector::createPath(lib);

        Collector hR(this->v_ui->libraryHeaderPath_edit->toPlainText()+"/",in,
        {"h"},true);
        Collector bD(this->v_ui->libraryDebugPath_edit->toPlainText()+"/",lib,
        {"a","dll","lib","pdb"},false);
        Collector bR(this->v_ui->libraryReleasePath_edit->toPlainText()+"/",lib,
        {"a","dll","lib","pdb"},false);

        if(hR.canCollect() == false) {
            return;
        }

        hR.collect();

        if(bD.canCollect() == true) {
            bD.collect();
        }

        if(bR.canCollect() == true) {
            bR.collect();
        }

}
