#include "Collector.h"

#include <QChar>
#include <QDir>

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
