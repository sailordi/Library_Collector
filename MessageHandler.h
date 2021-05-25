#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QPair>

#include "Message/Notice/Notice.h"
#include "Message/Notice/NoticeFlag.h"

typedef QPair<Notice*,NoticeFlag> NoticePair;

#include "Data/BuildDataTypedefs.h"

/*!
 * \brief The namespace handle all of the messages
 *
 * Incudes: BuildDataTypedefs.h, QPair ,Notice & NoticeFlag.h
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-21
 * \date Last update: 2021-05-25
*/
namespace MessageHandler {
    /*! Checks if build data can be added
     * \param l - List with build data
     * \param libraryName - The library base name
     * \param nD - The new buld data to ckeck
     * \throws QPair<Notice*,NoticeFlag>
    */
    void errorAddBuldData(QList<BuildDataP> l,QString libraryBaseName,BuildDataP nD);
    /*! Returns a message for build data being added
     *  \param d - The build data
     * \returns Notice*
    */
    Notice* addBuildData(BuildDataP d);

    /*! Checks if collection can be done
     * \param outP - The output path
     * \param outN - The output name
     * \param headerP - The header path
     * \param releseP - The relese path
     * \param debugP - The debug path
     * \throws QPair<Notice*,NoticeFlag>
    */
    void collectionCheck(QString outP,QString outN,QString headerP,QString releaseP,QString debugP);

    /*! Collection is done
     * \returns Notice*
    */
    Notice* collection();

    /*! Data is saved / loaded
     * \param path - Path the data was saved to
     * \param fileName - The files name
     * \param save - If the message is for data being saved
     * \returns Notice*
    */
    Notice* saveLoadData(QString path,QString fileName,bool save);

};
#endif // MESSAGEHANDLER_H
