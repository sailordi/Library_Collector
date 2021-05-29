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
 * \date Last update: 2021-05-29
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

    /*! Checks if an exclud path can be added
     * \param l - List of excluded paths
     * \param headerPath - The header path
     * \param excludePath - The new exclude path
     * \throws QPair<Notice*,NoticeFlag>
    */
    void errorAddExcludePath(QList<QString> l,QString headerPath,QString excludePath);

    /*! Checks if selection can be done
     * \param size - The build data list size
     * \param selected - The amount of data selected
     * \param update - Fi the selection is for updating data
     * \throws QPair<Notice*,NoticeFlag>
    */
    void errorSelection(int size,int selected,bool update);

    /*! Checks if collection can be preformed
     * \param outpuPt - The output path
     * \param libraryBaseName - The library base name
     * \param headerP - The header path
     * \param builds - The build data list size
     * \throws QPair<Notice*,NoticeFlag>
    */
    void errorCanPreformeCollection(QString outputP,QString libraryBaseName,QString headerP,int builds);
    /*! Checks if the collection was preformed without anny errors/warnings
     * \param outputP - The output path
     * \param libraryBaseName - The library base name
     * \param headerP - The header path
     * \param data - The build data
     * \throws QPair<Notice*,NoticeFlag>
    */
    void errorCollectionPreformed(QString outputP,QString libraryBaseName,QString hederP,BuildDataP data);

    /*! Collection is done
     * \param outpuPt - The output path
     * \param libraryBaseName - The library base name
     * \param headerP - The header path
     * \param data - The build data
     * \returns Notice*
    */
    Notice* collection(QString outputP,QString libraryBaseName,QString hederP,BuildDataP data);

    /*! Data is saved / loaded
     * \param path - Path the data was saved to
     * \param fileName - The files name
     * \param save - If the message is for data being saved
     * \returns Notice*
    */
    Notice* saveLoadData(QString path,QString fileName,bool save);

};
#endif // MESSAGEHANDLER_H
