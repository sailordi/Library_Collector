#include "BuildData.h"

//Public functions
BuildData::BuildData(QObject *parent) : QObject(parent) {

}

BuildData::BuildData(QStringList data,QObject* parent) : QObject(parent) {
    this->v_buildName = data.takeFirst();

    this->v_debugPath = data.takeFirst();
    this->v_releasePath = data.takeFirst();
}

void BuildData::setBuildName(QString buildName) {
    this->v_buildName = buildName;
}

void BuildData::setDebugPath(QString debugPath) {
    this->v_debugPath = debugPath;
}

QString BuildData::buildName() {
    return this->v_buildName;
}

QString BuildData::debugPath() {
    return this->v_debugPath;
}
