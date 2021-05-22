#include "BuildData.h"

//Public functions
BuildData::BuildData(QObject *parent) : QObject(parent) {

}

BuildData::BuildData(QStringList data,QObject* parent) : QObject(parent) {
    this->v_buildName = data.takeFirst();

    this->v_debugPath = data.takeFirst();
    this->v_releasePath = data.takeFirst();
}
