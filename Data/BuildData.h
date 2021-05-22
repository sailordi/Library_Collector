#ifndef BUILDDATA_H
#define BUILDDATA_H

#include <QObject>
#include <QString>
#include <QStringList>

/*! \class BuildData
 * \brief The class contains library build data [builds name, relese path and debug path]
 *
 * Incudes: QObject, QString & QStringList
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-22
 * \date Last update: 2021-05-22
*/
class BuildData : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit BuildData(QObject* parent = nullptr);
    /*! Constructor
     * \param data - The list of data
     * \param parent - The parent [Default: nullptr]
    */
    explicit BuildData(QStringList data,QObject *parent = nullptr);

    /*! Sets the build name
     * \param buildName - The build name
    */
    void setBuildName(QString buildName);
    /*! Sets the debug path
     * \param debugPath - The debug path
    */
    void setDebugPath(QString debugPath);

    /*! Returns the build name
     * \returns QString
    */
    QString buildName();
    /*! Return the debug path
     * \returns QString
    */
    QString debugPath();

private:
    QString v_buildName = "",v_debugPath = "",v_releasePath = "";

};
#endif // BUILDDATA_H
