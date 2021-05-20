#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <QString>
#include <QStringList>

/*! \class Collector
 * \brief The class will collect the nessesery info
 *
 * The info is copied from a path into another
 *
 * Includes: QString & QStringList
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-20
 * \date Last update: 2021-05-20
*/
class Collector
{
public:
    /*! Constructor
     * \param fromPath - The path to search for files
     * \param toPath - The output path
     * \param suffix - Suffixes to copy
     * \param createDirs - If dirs should be created inside the output path [Default: true]
    */
    Collector(QString fromPath,QString toPath,QStringList suffix,bool createDirs = true);
    /*! Deconstructor */
    ~Collector();

    /*! Checks if collection can be preformed
     * \returns bool
    */
    bool canCollect();

private:
    QString v_fromPath = "",v_toPath = "";
    bool v_createDirs;
    QStringList v_suffix;

};
#endif // COLLECTOR_H
