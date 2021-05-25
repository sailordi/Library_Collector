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
     * \param d - The build data
     * \returns Notice*
    */
    Notice* addBuildData(BuildDataP d);

    /*! Checks if build data can be updated
     * \param l - List with build data
     * \param libraryBaseName - The library base name
     * \param oldDataPos - The old data position in the data list
     * \param oD - The old build data
     * \param nD - The updated build data to check
     * \throws QPair<Notice*,NoticeFlag>
    */
    void errorUpdateBuildData(QList<BuildDataP> l,QString libraryBaseName,int oldDataPos,BuildDataP oD,BuildDataP nD);
    /*! Returns a message for build data being updated
     * \param oD - The old build data
     * \param nD - The new build data
     * \returns Notice*
    */
    Notice* updateBuildData(BuildDataP oD,BuildDataP nD);

    /*! Returns a message for build data being removed
     * \param d - The build data
     * \returns Notice*
    */
    Notice* removeBuildData(BuildDataP d);

    /*! Checks if selection can be done
     * \param size - The build data list size
     * \param selected - The amount of data selected
     * \param update - Fi the selection is for updating data
     * \throws QPair<Notice*,NoticeFlag>
    */
    void errorSelection(int size,int selected,bool update);

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
