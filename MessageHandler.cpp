#include "MessageHandler.h"

#include <QDir>

#include "Base/Other/Helper.h"

//Public functions
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
