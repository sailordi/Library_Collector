#include "WindowMain.h"
#include "ui_WindowMain.h"

#include <QFileDialog>

#include "Base/Settings/Settings.h"

#include "MessageHandler.h"
#include "Adapter/NoticeAdapter.h"
#include "Data/BuildData.h"
#include "Data/Collector.h"
#include "WindowMainWidgets/BuildDataViewWidget.h"
#include "WindowMainWidgets/BuildDataWidget.h"
#include "WindowMainWidgets/ExcludePathsViewWidget.h"
#include "WindowMainWidgets/MainInfoWidget.h"

//Public functions
WindowMain::WindowMain(QWidget *parent) : QMainWindow(parent), v_ui(new Ui::WindowMain) {
    this->v_ui->setupUi(this);

    this->v_noticeA = new NoticeAdapter(this);

    this->v_mainInfoW = new MainInfoWidget(this->v_ui->mainInfo_layout);
    this->v_buildDataViewW = new BuildDataViewWidget(this->v_ui->buildView_layout);
    this->v_buildDataW = new BuildDataWidget(this->v_ui->buildData_layout);
    this->v_excludedPathsW = new ExcludePathsViewWidget(this->v_ui->exludedPaths_layout);

    connect(this->v_mainInfoW->outputPathButton(),&QPushButton::clicked,this,&WindowMain::libraryOutPathBtnClicked);

    connect(this->v_mainInfoW->headerPathButton(),&QPushButton::clicked,this,&WindowMain::libraryHeaderPathBtnClicked);

    connect(this->v_buildDataW->releasePathButton(),&QPushButton::clicked,this,&WindowMain::libraryReleasePathBtnClicked);
    connect(this->v_buildDataW->debugPathButton(),&QPushButton::clicked,this,&WindowMain::libraryDebugPathBtnClicked);

    connect(this->v_ui->addUpdateBuildData_btn,&QPushButton::clicked,this,&WindowMain::addUpdateBtnClicked);
    connect(this->v_ui->cancelBuildDataUpdate_btn,&QPushButton::clicked,this,&WindowMain::cancelUpdateBtnClicked);

    connect(this->v_ui->preformCollection_btn,&QPushButton::clicked,this,&WindowMain::preformCollectionBtnClicked);

    connect(this->v_ui->actionSaveData,&QAction::triggered,this,&WindowMain::saveProgramData);
    connect(this->v_ui->actionLoadData,&QAction::triggered,this,&WindowMain::loadProgramData);

    QActionGroup* collectOptions = new QActionGroup(this);

    collectOptions->addAction(this->v_ui->actionCollectAllBuildDataSameFolder);
    collectOptions->addAction(this->v_ui->actionCollectAllBuildDataDifferentFolders);

    this->v_ui->tabWidget->setCurrentIndex(0);

    this->prepareBuildDataTab();

    this->setTabsPalett();
    this->loadWindowSettings();
}

WindowMain::~WindowMain() {
    this->saveWindowSettings();

    delete this->v_noticeA;

    delete this->v_buildDataW;
    delete this->v_buildDataViewW;
    delete this->v_mainInfoW;
    delete  this->v_excludedPathsW;

    delete this->v_ui;
}

void WindowMain::prepareBuildDataTab(int oldDataPosition,BuildDataP data) {
    this->v_buildDataW->clear(false);

    if(data.isNull() == true) {
        this->v_ui->addUpdateBuildData_btn->setText("Add");
        this->v_buildDataW->hideResetButtons(true);

        this->v_ui->cancelBuildDataUpdate_btn->setHidden(true);

        this->v_ui->buildDataBtn_spacer2->changeSize(0,0,QSizePolicy::Ignored,QSizePolicy::Ignored);

        this->v_ui->tabWidget->setCurrentIndex(0);
    }
    else {
        this->v_ui->addUpdateBuildData_btn->setText("Update");
        this->v_buildDataW->hideResetButtons(false);

        this->v_ui->cancelBuildDataUpdate_btn->setHidden(false);

        this->v_ui->buildDataBtn_spacer2->changeSize(40,20,QSizePolicy::Expanding,QSizePolicy::Expanding);

        this->v_buildDataW->setOldData(oldDataPosition,data);

        this->v_ui->tabWidget->setCurrentIndex(1);
    }

}

//Private slots
void WindowMain::libraryOutPathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library output path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_mainInfoW->setOutputPath(str);
}

void WindowMain::libraryHeaderPathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library header path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_mainInfoW->setHeaderPath(str);
}

void WindowMain::libraryDebugPathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library debug path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_buildDataW->setDebugPath(str);
}

void WindowMain::libraryReleasePathBtnClicked() {
    QString str = QFileDialog::getExistingDirectory(nullptr,"Select library release path...","");

        if(str.isEmpty() == true) {
            return;
        }

        this->v_buildDataW->setReleasePath(str);
}

void WindowMain::addUpdateBtnClicked() {
    try {
        if(this->v_ui->addUpdateBuildData_btn->text().compare("Add") == 0) {
            this->addData();
        }
        else {
            this->updateData();
        }
        this->v_buildDataViewW->updateView();
        this->prepareBuildDataTab();
    }catch(NoticePair p) {
        this->v_noticeA->add(p.first,p.second);
    }

    this->v_noticeA->show();
}

void WindowMain::cancelUpdateBtnClicked() {
    this->prepareBuildDataTab();
}

void WindowMain::updateSelectedBuildData() {
    int size = this->v_buildDataViewW->buildDataList().size(),selected = this->v_buildDataViewW->numberOfSelectedRows();

        this->v_noticeA->reset("Update build data");

        try {
            MessageHandler::errorSelection(size,selected,true);
            QList<int> l = this->v_buildDataViewW->selectedRowsPosition();
            int index = l.first();

            this->prepareBuildDataTab(index,this->v_buildDataViewW->buildDataList().at(index) );
        }catch(NoticePair p) {
            this->v_noticeA->add(p.first,p.second);
            this->v_noticeA->show();
        }

}

void WindowMain::removeSelectedBuildData() {
    int size = this->v_buildDataViewW->buildDataList().size(),selected = this->v_buildDataViewW->numberOfSelectedRows();

        this->v_noticeA->reset("Remove build data");

        try {
            MessageHandler::errorSelection(size,selected,false);
        }catch(NoticePair p) {
            this->v_noticeA->add(p.first,p.second);
            this->v_noticeA->show();
            return;
        }

        QList<int> selectedNumbers = this->v_buildDataViewW->selectedRowsPosition();
        QList<BuildDataP>* dataL = this->v_buildDataViewW->buildDataListP();

        for(int i = selected -1; i >= 0; i--) {
            BuildDataP d = dataL->takeAt(selectedNumbers.at(i) );

            this->v_noticeA->add(MessageHandler::removeBuildData(d),NoticeFlag::MESSAGE);
        }
        this->v_buildDataViewW->updateView();

        this->v_noticeA->show();
}

void WindowMain::preformCollectionBtnClicked() {
    QString outP = this->v_mainInfoW->outputPath();
       QString libraryBaseName = this->v_mainInfoW->libraryBaseName();
       QString headerP = this->v_mainInfoW->headerPath();
       QList<BuildDataP> l = this->v_buildDataViewW->buildDataList();

           this->v_noticeA->reset("Preform collection");

           try {
               MessageHandler::errorCanPreformeCollection(outP,libraryBaseName,headerP,l.size() );
           }catch(QPair<Notice*,NoticeFlag> p) {
               this->v_noticeA->add(p.first,p.second);
               this->v_noticeA->show();
               return;
           }

           for(int i = 0; i < l.size(); i++) {
               BuildDataP b = this->v_buildDataViewW->buildDataList().at(i);
               bool w = false;

               try {
                   MessageHandler::errorCollectionPreformed(outP,libraryBaseName,headerP,b);
               }catch(QPair<Notice*,NoticeFlag> p) {
                   this->v_noticeA->add(p.first,p.second);

                   if(p.second == NoticeFlag::ERROR) {
                       continue;
                   }
                   else {
                       w = true;
                   }
               }
               QString destP  = Collector::formatOutPath(outP,libraryBaseName+b->buildName() );
               QString in = Collector::formatOutPath(destP,"includes");
               QString lib = Collector::formatOutPath(destP,"libs");

               Collector::createPath(destP);
               Collector::createPath(in);
               Collector::createPath(lib);

               Collector cH(headerP+"/",in,{"h"},true);
               Collector cD(b->debugPath()+"/",lib,{"a","dll","lib","pdb"},false);
               Collector cR(b->releasePath()+"/",lib,{"a","dll","lib","pdb"},false);

               cH.collect();

               if(cD.canCollect() == true) {
                   cD.collect();
               }
               if(cR.canCollect() == true) {
                   cR.collect();
               }

               if(w == false) {
                   this->v_noticeA->add(MessageHandler::collection(outP,libraryBaseName,headerP,b),NoticeFlag::MESSAGE);
               }

           }

           this->v_noticeA->show();
}

void WindowMain::saveProgramData() {
    QString str = QFileDialog::getSaveFileName(nullptr,"Save Library collect..",QString(),"Library collector Data(*.LibColDataV2)");

    if(str.isEmpty() == true) {
        return;
    }

    this->v_noticeA->reset("Library collector data saved");

    Settings* s = new Settings(str);

    s->startGroup("Data");

    s->addBlockData("OutputPath",this->v_mainInfoW->outputPath() );
    s->addBlockData("LibraryBaseName",this->v_mainInfoW->libraryBaseName() );
    s->addBlockData("HeaderPath",this->v_mainInfoW->headerPath() );

    QList<BuildDataP> l = this->v_buildDataViewW->buildDataList();
    s->startArray("Builds");
    s->clearArray(false);

    for(int i = 0; i < l.size(); i++) {
        BuildDataP b = l.at(i);
        QList<QString> k = {"BuildName","DebugPath","RelesePath"};
        QList<QVariant> v = {b->buildName(),b->debugPath(),b->releasePath()};

        s->addArrayData(k,v);
    }

    s->endArray();

    QList<QString> l2 = this->v_excludedPathsW->excludedPathsList();
    s->startArray("ExcludedPaths");
    s->clearArray(false);

    for(int i = 0; i < l2.size(); i++) {
        QList<QString> k = {"Path"};
        QList<QVariant> v = {l2.at(i)};

        s->addArrayData(k,v);
    }

    s->endArray();
    s->endGroup();

    delete s;

    QFileInfo f(str);

    this->v_noticeA->add(MessageHandler::saveLoadData(f.path(),f.fileName(),true),NoticeFlag::MESSAGE);
    this->v_noticeA->show();
}

void WindowMain::loadProgramData() {
    QString str = QFileDialog::getOpenFileName(nullptr,"Load Library collect..",QString(),"Library collector Data(*.LibColDataV2)");

    if(str.isEmpty() == true) {
        return;
    }

    this->v_noticeA->reset("Library collector data loaded");

    Settings* s = new Settings(str,false);

    s->startGroup("Data");

    this->v_mainInfoW->setOutputPath(s->getBlockData("OutputPath","").toString() );
    this->v_mainInfoW->setLibraryBaseName(s->getBlockData("LibraryBaseName","").toString() );
    this->v_mainInfoW->setHeaderPath(s->getBlockData("HeaderPath","").toString() );

    s->startArray("Builds");
    this->v_buildDataW->clear(false);
    this->v_buildDataViewW->clear();
    QList<BuildDataP>* l = this->v_buildDataViewW->buildDataListP();

    int size = 0;

    try {
        size = s->arraySize();
    } catch (QString e) {
        //The array did not exist / other error occured
        size = 0;
    }

    for(int i = 0; i < size; i++) {
        QList<QString> k = {"BuildName","DebugPath","RelesePath"};
        QList<QVariant> v = {"","",""};
        QList<QVariant> d = s->getArrayData(i,k,v);

        l->push_back(BuildDataP(new BuildData({d.at(0).toString(),d.at(1).toString(),d.at(2).toString()}) ) );
    }

    s->endArray();

    this->v_excludedPathsW->clear();
    QList<QString>* l2 = this->v_excludedPathsW->excludedPathsListP();
    s->startArray("ExcludedPaths");

    try {
        size = s->arraySize();
    } catch (QString e) {
        //The array did not exist / other error ocured
        size = 0;
    }

    for(int i = 0; i < size; i++) {
        QList<QString> k = {"Path"};
        QList<QVariant> v = {""};
        QList<QVariant> d = s->getArrayData(i,k,v);

        l2->push_back(d.first().toString() );
    }

    s->endArray();
    s->endGroup();

    delete s;

    this->v_buildDataViewW->updateView();
    this->v_excludedPathsW->updateView();

    QFileInfo f(str);

    this->v_noticeA->add(MessageHandler::saveLoadData(f.path(),f.fileName(),false),NoticeFlag::MESSAGE);
    this->v_noticeA->show();
}

//Private functions
void WindowMain::setTabsPalett() {
    QPalette p;

        p.setColor(QPalette::Background,Qt::lightGray);

        this->v_ui->mainInfo_tab->setPalette(p);
        this->v_ui->buildData_tab->setPalette(p);
        this->v_ui->exlcludedPaths_tab->setPalette(p);
}

void WindowMain::addData() {
    BuildDataP d(new BuildData({this->v_buildDataW->buildName(),this->v_buildDataW->debugPath(),this->v_buildDataW->releasePath()}) );

        this->v_noticeA->reset("Add build data");

        MessageHandler::errorAddBuldData(this->v_buildDataViewW->buildDataList(),this->v_mainInfoW->libraryBaseName(),d);

        this->v_buildDataViewW->buildDataListP()->push_back(d);

        this->v_noticeA->add(MessageHandler::addBuildData(d),NoticeFlag::MESSAGE);
}

void WindowMain::updateData() {
    BuildDataP nD(new BuildData({this->v_buildDataW->buildName(),this->v_buildDataW->debugPath(),this->v_buildDataW->releasePath()}) );
    BuildDataP oD = this->v_buildDataW->oldData();
    int oldDataPosition = this->v_buildDataW->oldDataPosition();

        this->v_noticeA->reset("Update build data");

        MessageHandler::errorUpdateBuildData(this->v_buildDataViewW->buildDataList(),this->v_mainInfoW->libraryBaseName(),
                                             oldDataPosition,oD,nD);

        this->v_noticeA->add(MessageHandler::updateBuildData(oD,nD),NoticeFlag::MESSAGE);

        this->v_buildDataW->updateOldData();
}

void WindowMain::saveWindowSettings() {
    Settings s("./Settings/LibraryColectorData.libColSet");

        s.startGroup("WindowMain");

        QPoint pos = this->pos();

        s.addBlockData("Pos",pos);
        s.addBlockData("SameFolder",this->v_ui->actionCollectAllBuildDataSameFolder->isChecked() );
        s.addBlockData("KeepAddingData",this->v_ui->actionKeepAddingBuildData->isChecked() );

        s.endGroup();

        this->v_noticeA->saveLoadSettings(&s,true);
}

void WindowMain::loadWindowSettings() {
    Settings s("./Settings/LibraryColectorData.libColSet",false);

        s.startGroup("WindowMain");

        QPoint pos = s.getBlockData("Pos",QPoint(100,100) ).toPoint();
        bool sA = s.getBlockData("SameFolder",false).toBool();
        bool kA = s.getBlockData("KeepAddingdata",false).toBool();

        this->move(pos);
        this->v_ui->actionCollectAllBuildDataDifferentFolders->setChecked(!sA);
        this->v_ui->actionKeepAddingBuildData->setChecked(kA);

        s.endGroup();

        this->v_noticeA->saveLoadSettings(&s,false);
}
