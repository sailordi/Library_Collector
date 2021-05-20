#include "Collector.h"

//Public functions
Collector::Collector(QString fromPath,QString toPath,QStringList suffix,bool createDirs) {
    this->v_fromPath = fromPath;
    this->v_toPath = toPath;
    this->v_suffix = suffix;
    this->v_createDirs = createDirs;
}

Collector::~Collector() {

}
