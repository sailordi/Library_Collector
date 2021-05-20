#include "Collector.h"

#include <QChar>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>

//Public functions
Collector::Collector(QString fromPath,QString toPath,QStringList suffix,bool createDirs) {
    this->v_fromPath = fromPath;
    this->v_toPath = toPath;
    this->v_suffix = suffix;
    this->v_createDirs = createDirs;
}

Collector::~Collector() {

}

bool Collector::canCollect() {
    if(this->v_fromPath.isEmpty() == true) {
        return false;
    }
    else if(this->v_fromPath.isEmpty() == false && QDir(this->v_fromPath).exists() == false) {
        return false;
    }

    if(this->v_toPath.isEmpty() == true) {
        return false;
    }
    if(this->v_toPath.compare("/") == 0) {
        return false;
    }

    return true;
}

QString Collector::formatOutPath(QString dirPath,QString dirName) {
    if(dirPath.isEmpty() == false && dirPath.at(dirPath.size()-1) == QChar('/') ) {
        dirPath.resize(dirPath.size()-1);
    }

    if(dirPath.isEmpty() == true) {
        return "";
    }
    if(dirName.isEmpty() == true) {
        return dirPath+"/";
    }

    return dirPath+"/"+dirName+"/";
}

void Collector::createPath(QString path) {
    QDir d(path);

        if(d.exists() == false) {
            d.mkdir(path);
        }

}

void Collector::collect() {
    QDir d(this->v_fromPath);
    QFileInfoList l = d.entryInfoList(QDir::AllEntries|QDir::NoDotAndDotDot);

        for(int i = 0; i < l.size(); i++) {
            QFileInfo fI = l.at(i);

            this->dir(fI);
            this->file(fI);
        }

}

//Private functions
void Collector::dir(QFileInfo i) {
    if(i.isDir() == false) {
        return;
    }

    QString n = (this->v_createDirs == false) ? "" : i.baseName();

    if(i.baseName().isEmpty() == true) {
        return;
    }

    QString toP = Collector::formatOutPath(this->v_toPath,n);
    QString fromP = i.absolutePath()+"/"+i.baseName()+"/";

    if(this->v_createDirs == true) {
        Collector::createPath(toP);
    }
    Collector c(fromP,toP,this->v_suffix,this->v_createDirs);

    c.collect();
}

void Collector::file(QFileInfo i) {
    if(i.isFile() == false || (i.isFile() == true && this->v_suffix.contains(i.suffix() ) == false) ) {
        return;
    }

    QString n = i.baseName()+"."+i.suffix();
    QFile* tF = new QFile(this->v_toPath+n);

    if(tF->exists() == true) {
        tF->remove();
    }

    delete tF;

    QFile fF(this->v_fromPath+n);

    fF.copy(this->v_toPath+n);
}
