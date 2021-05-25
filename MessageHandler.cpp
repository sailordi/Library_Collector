#include "MessageHandler.h"

#include <QDir>

#include "Base/Other/Helper.h"

#include "Data/BuildData.h"

//Public functions
void MessageHandler::errorAddBuldData(QList<BuildDataP> l, QString libraryBaseName, BuildDataP nD) {
    QString str = "";

        if(nD->buildName().isEmpty() == true) {
            str.append("Build name is empty"+Helper::newRow() );
        }
        else if(nD->buildName().isEmpty() == false && nD->buildName().compare(libraryBaseName) == 0) {
            str.append("Build name is the same as library base name"+Helper::newRow() );
        }
        if(nD->debugPath().isEmpty() == true && nD->releasePath().isEmpty() == true) {
            str.append("Debug & release path is empty"+Helper::newRow() );
        }

        if(nD->debugPath().isEmpty() == false && nD->releasePath().isEmpty() == false
                && nD->debugPath().compare(nD->releasePath() ) == 0 ) {
                str.append("Debug and relese path are the same"+Helper::newRow() );
        }

        if(str.isEmpty() == true) {
            bool f = false,d = false,r = false,b  = false;

            for(int i = 0; i < l.size(); i++) {
                BuildDataP bD = l.at(i);

                if(bD->buildName().compare(nD->buildName() ) == 0) {
                    b = true;
                    f = true;
                }
                if(bD->debugPath().compare(nD->debugPath() ) == 0) {
                    d = true;
                    f = true;
                }
                if(bD->releasePath().compare(nD->releasePath() ) == 0) {
                    r = true;
                    f = true;
                }

                if(f == true) {
                    i  = l.size();
                }

            }

            if(b == true) {
                str.append("Build name already exists in the build data list"+Helper::newRow() );
            }
            if(d == true) {
                str.append("Debug path already exists in the build data list"+Helper::newRow() );
            }
            if(r == true) {
                str.append("Release path already exists in the build data list"+Helper::newRow() );
            }

        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }

}

Notice* MessageHandler::addBuildData(BuildDataP d) {
    QString str = "";

        str.append("Build name: "+d->buildName()+Helper::newRow(2) );

        if(d->debugPath().isEmpty() == false) {
            str.append("Debug path: "+Helper::newRow()+d->debugPath()+Helper::newRow() );
        }
        else {
            str.append("Debug path is empty"+Helper::newRow() );
        }

        if(d->releasePath().isEmpty() == false) {
            str.append("Release path: "+Helper::newRow()+d->releasePath()+Helper::newRow(2) );
        }
        else {
            str.append("Release path is empty"+Helper::newRow(2) );
        }

        str.append("Was added to build data list"+Helper::newRow() );

        return new Notice(str);
}

void MessageHandler::errorUpdateBuildData(QList<BuildDataP> l,QString libraryBaseName,int oldDataPos,BuildDataP oD,BuildDataP nD) {
    QString str = "";
    QStringList oL = {oD->buildName(),oD->debugPath(),oD->releasePath()};
    QStringList nL = {nD->buildName(),nD->debugPath(),nD->releasePath()};
    bool empty = true,same = true;

        for(int i = 0; i < oL.size(); i++) {
            if(nL.at(i).isEmpty() == false) {
                empty = false;
            }
            else {
                nL.replace(i,oL.at(i) );
            }
            if(nL.at(i).compare(oL.at(i) ) != 0) {
                same = false;
            }

        }

        if(empty == true) {
            str.append("No data has been entered"+Helper::newRow() );
        }
        if(same == true) {
            str.append("No data has changed"+Helper::newRow() );
        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }

        if(nD->buildName().compare(libraryBaseName) == 0) {
            str.append("Build name is the same as library base name"+Helper::newRow() );
        }
        if(nD->debugPath().isEmpty() == false && nD->releasePath().isEmpty() == false
                && nD->debugPath().compare(nD->releasePath() ) == 0 ) {
                str.append("Debug and relese path are the same"+Helper::newRow() );
        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }
        bool f = false,d = false,r = false,b  = false;
        l.removeAt(oldDataPos);

        for(int i = 0; i < l.size(); i++) {
            BuildDataP bD = l.at(i);

            if(bD->buildName().compare(nD->buildName() ) == 0) {
                b = true;
                f = true;
            }
            if(bD->debugPath().compare(nD->debugPath() ) == 0) {
                d = true;
                f = true;
            }
            if(bD->releasePath().compare(nD->releasePath() ) == 0) {
                r = true;
                f = true;
            }

            if(f == true) {
                i  = l.size();
            }

        }

        if(b == true) {
            str.append("Build name already exists in the build data list"+Helper::newRow() );
        }
        if(d == true) {
            str.append("Debug path already exists in the build data list"+Helper::newRow() );
        }
        if(r == true) {
            str.append("Release path already exists in the build data list"+Helper::newRow() );
        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }

}

Notice* MessageHandler::updateBuildData(BuildDataP oD,BuildDataP nD) {
    QString str = "";

    if(oD->buildName().compare(nD->buildName() ) != 0 && oD->buildName().isEmpty() == true) {
        str.append("Build name was empty is now ");
        str.append(nD->buildName()+Helper::newRow(2) );
    }
    else if(oD->buildName().compare(nD->buildName() ) != 0 && oD->buildName().isEmpty() == false) {
        str.append("Build name was "+oD->buildName()+" is now ");
        str.append(nD->buildName()+Helper::newRow(2) );
    }
    else {
        str.append("Build name has not been changed"+Helper::newRow(2) );
    }

    if(oD->debugPath().compare(nD->debugPath() ) != 0 && oD->debugPath().isEmpty() == true) {
        str.append("Debug path was empty"+Helper::newRow()+"  is now "+Helper::newRow() );
        str.append(nD->debugPath()+Helper::newRow() );
    }
    else if(oD->debugPath().compare(nD->debugPath() ) != 0 && oD->debugPath().isEmpty() == false) {
        str.append("Debug path was "+Helper::newRow()+oD->debugPath()+Helper::newRow()+" is now "+Helper::newRow() );
        str.append(nD->debugPath()+Helper::newRow() );
    }
    else {
        str.append("Debug path has not been changed"+Helper::newRow() );
    }

    if(oD->releasePath().compare(nD->releasePath() ) != 0 && oD->releasePath().isEmpty() == true) {
        str.append("Release path was empty"+Helper::newRow()+"  is now "+Helper::newRow() );
        str.append(nD->releasePath()+Helper::newRow(2) );
    }
    else if(oD->releasePath().compare(nD->releasePath() ) != 0 && oD->releasePath().isEmpty() == false) {
        str.append("Release path was "+Helper::newRow()+oD->releasePath()+Helper::newRow()+" is now "+Helper::newRow() );
        str.append(nD->releasePath()+Helper::newRow(2) );
    }
    else {
        str.append("Release path has not been changed"+Helper::newRow(2) );
    }

    return new Notice(str);
}

Notice* MessageHandler::removeBuildData(BuildDataP d) {
    QString str = "";

        str.append("Build name: "+d->buildName()+Helper::newRow(2) );

        if(d->debugPath().isEmpty() == false) {
            str.append("Debug path: "+Helper::newRow()+d->debugPath()+Helper::newRow() );
        }
        else {
            str.append("Debug path is empty"+Helper::newRow() );
        }

        if(d->releasePath().isEmpty() == false) {
            str.append("Release path: "+Helper::newRow()+d->releasePath()+Helper::newRow(2) );
        }
        else {
            str.append("Release path is empty"+Helper::newRow(2) );
        }

        str.append("Was removed from build data list"+Helper::newRow() );

        return new Notice(str);
}

void MessageHandler::errorSelection(int size,int selected,bool update) {
    QString str;

        if(size < 0) {
            str = "No build data in list"+Helper::newRow();
        }

        if(str.isEmpty() == true && selected <= 0) {
            str = "No build data has been selected"+Helper::newRow();
        }
        if(str.isEmpty() == true && selected > 1 && update == true) {
            str = "Multiple build data entries has been selected"+Helper::newRow();
        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }

}

void MessageHandler::collectionCheck(QString outP,QString outN,QString headerP,QString releaseP,QString debugP) {
    QString tmp = "";

        if(outP.isEmpty() == true) {
            tmp.append("Output path is missing");
            tmp.append(Helper::newRow(2) );
        }
        if(outN.isEmpty() == true) {
            tmp.append("Output name is missing");
            tmp.append(Helper::newRow(2) );
        }

        if(headerP.isEmpty() == true) {
            tmp.append("Header path is missing");
            tmp.append(Helper::newRow(2) );
        }
        else if(headerP.isEmpty() == false && QDir(headerP).exists() == false) {
            tmp.append("Header path no longer exist");
            tmp.append(Helper::newRow(2) );
        }

        if(releaseP.isEmpty() == true && debugP.isEmpty() == true) {
            tmp.append("Release and debug path is missing, only one can be missing");
            tmp.append(Helper::newRow(2) );
        }

        if(tmp.isEmpty() == false) {
            throw NoticePair(new Notice(tmp),NoticeFlag::ERROR);
        }
        bool rP = false,dP = false;

        if(releaseP.isEmpty() == false && QDir(releaseP).exists() == false) {
            tmp.append("Release path no longer exist");
            tmp.append(Helper::newRow(2) );
            rP = true;
        }
        if(debugP.isEmpty() == false && QDir(debugP).exists() == false) {
            tmp.append("Debug path no longer exist");
            tmp.append(Helper::newRow(2) );
            dP = true;
        }

        if(rP == true && dP == true) {
            throw NoticePair(new Notice(tmp),NoticeFlag::ERROR);
        }
        else {
            throw NoticePair(new Notice(tmp),NoticeFlag::WARNING);
        }

}

Notice* MessageHandler::collection() {
    return new Notice("The collection has been performed");
}

Notice* MessageHandler::saveLoadData(QString path,QString fileName,bool save) {
    QString str = Helper::newRow(2)+"Path: "+path+Helper::newRow(2)+"File name: "+fileName+Helper::newRow(2);

        if(save == true) {
            return new Notice("Data has been saved"+str);
        }
        return new Notice("Data has been loaded"+str);

}

