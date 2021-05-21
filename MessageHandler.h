#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QPair>

#include "Message/Notice/Notice.h"
#include "Message/Notice/NoticeFlag.h"

typedef QPair<Notice*,NoticeFlag> NoticePair;

/*!
 * \brief The namespace handle all of the messages
 *
 * Incudes: QPair ,Notice & NoticeFlag.h
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-21
 * \date Last update: 2021-05-21
*/
namespace MessageHandler {
    /*! Checks if collection can be done
     * \param outP - The output path
     * \param outN - The output name
     * \param headerP - The header path
     * \param releseP - The relese path
     * \param debugP - The debug path
     * \throws QPair<Notice*,NoticeFlag>
    */
    void collectionCheck(QString outP,QString outN,QString headerP,QString releaseP,QString debugP);

};
#endif // MESSAGEHANDLER_H
