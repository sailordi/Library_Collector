#include "WindowMain.h"
#include "ui_WindowMain.h"

#include <QFileDialog>

#include "Base/Settings/Settings.h"

#include "MessageHandler.h"
#include "Adapter/NoticeAdapter.h"
#include "Data/Collector.h"
#include "WindowMainWidgets/LibraryDataWidget.h"

//Public functions
WindowMain::WindowMain(QWidget *parent) : QMainWindow(parent), v_ui(new Ui::WindowMain) {
    this->v_ui->setupUi(this);

    this->v_outDataW = new LibraryDataWidget(this->v_ui->libraryOut_layout,"Library output",true);
    this->v_headerDataW = new LibraryDataWidget(this->v_ui->libraryHeader_layout,"Library headers",false);
    this->v_releaseDataW = new LibraryDataWidget(this->v_ui->libraryRelease_layout,"Library release",false);
    this->v_debugDataW = new LibraryDataWidget(this->v_ui->libraryDebug_layout,"Library debug",false);

    this->v_noticeA = new NoticeAdapter(this);

    connect(this->v_outDataW->selectPathBtn(),&QPushButton::clicked,this,&WindowMain::libraryOutPathBtnClicked);

    connect(this->v_headerDataW->selectPathBtn(),&QPushButton::clicked,this,&WindowMain::libraryHeaderPathBtnClicked);

    connect(this->v_debugDataW->selectPathBtn(),&QPushButton::clicked,this,&WindowMain::libraryDebugPathBtnClicked);
    connect(this->v_releaseDataW->selectPathBtn(),&QPushButton::clicked,this,&WindowMain::libraryReleasePathBtnClicked);

    connect(this->v_ui->preformCollection_btn,&QPushButton::clicked,this,&WindowMain::preformCollectionBtnClicked);
}

WindowMain::~WindowMain() {
    this->saveWindowSettings();

    delete this->v_noticeA;

    delete this->v_outDataW;
    delete this->v_headerDataW;
    delete this->v_releaseDataW;
    delete this->v_debugDataW;

    delete this->v_ui;
}

//Private slots
void WindowMain::libraryOutPathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library output path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_outDataW->setPath(str);
}

void WindowMain::libraryHeaderPathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library header path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_headerDataW->setPath(str);
}

void WindowMain::libraryDebugPathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library debug path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_debugDataW->setPath(str);
}

void WindowMain::libraryReleasePathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library release path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_releaseDataW->setPath(str);
}

void WindowMain::preformCollectionBtnClicked() {
    QString outP = this->v_outDataW->path(), outN = this->v_outDataW->name();
    QString hP = this->v_headerDataW->path(), dP = this->v_debugDataW->path(), rP = this->v_releaseDataW->path();

        this->v_noticeA->reset("Preform collection");

        try {
            MessageHandler::collectionCheck(outP,outN,hP,rP,dP);
        }catch(NoticePair p) {
            this->v_noticeA->add(p.first,p.second);

            if(p.second == NoticeFlag::ERROR) {
                this->v_noticeA->show();
                return;
            }

        }

        QString outPut = Collector::formatOutPath(outP,outN);
        QString in = Collector::formatOutPath(outPut,"includes");
        QString lib = Collector::formatOutPath(outPut,"libs");

        Collector::createPath(outPut);
        Collector::createPath(in);
        Collector::createPath(lib);

        Collector hR(hP+"/",in,{"h"},true);
        Collector bD(dP+"/",lib,{"a","dll","lib","pdb"},false);
        Collector bR(rP+"/",lib,{"a","dll","lib","pdb"},false);

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
        this->v_noticeA->add(MessageHandler::collection(),NoticeFlag::MESSAGE);

        this->v_noticeA->show();

}

//Private functions
void WindowMain::saveWindowSettings() {
    Settings s("./Settings/LibraryColectorData.libColSet");

        s.startGroup("WindowMain");

        QPoint pos = this->pos();

        s.addBlockData("Pos",pos);

        s.endGroup();

        this->v_noticeA->saveLoadSettings(&s,true);
}
