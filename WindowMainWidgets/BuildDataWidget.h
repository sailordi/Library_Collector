#ifndef BUILDDATAWIDGET_H
#define BUILDDATAWIDGET_H

#include "Base/LayoutWidget/MultiLayoutWidget.h"

#include "Data/BuildDataTypedefs.h"

class QLineEdit;
class QTextEdit;
class QPushButton;

class BuildData;

/*! \class BuildDataWidget
 * \brief The class contains widgets for adding/updating the build data
 *
 * Incudes: MultiLayoutWidget & BuildDataTypedefs.h
 *
 * Forward declarations: QLineEdit, QTextEdit & QPushButton
 *
 * Inherits: MultiLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-24
 * \date Last update: 2021-05-29
*/
class BuildDataWidget : public MultiLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param l - The layout for the build data widgets
     * \param parent - The parent [Default: nullptr]
    */
    explicit BuildDataWidget(QGridLayout* l,QWidget *parent = nullptr);

    /*! Sets the old data
     * \param oldDataPosition - The old datas position in the data list
     * \param data - The pointer to the data
    */
    void setOldData(int oldDataPosition,BuildDataP data);
    /*! Setes the build name
     * \param buildName - The build name
    */
    void setBuildName(QString buildName);
    /*! Sets the debug path
     * \param debugPath
    */
    void setDebugPath(QString debugPath);
    /*! Sets the release path
     * \param releasePath
    */
    void setReleasePath(QString releasePath);

    /*! Updates the old data with the new data */
    void updateOldData();

    /*! Returns the old data position
     * \returns int
    */
    int oldDataPosition();
    /*! Returns the old data
     * \returns BuildDataP
    */
    BuildDataP oldData();

    /*! Returns the build name
     * \returns QString
    */
    QString buildName();
    /*! Returns the debug path
     * \returns QString
    */
    QString debugPath();
    /*! Returns the release path
     * \returns QString
    */
    QString releasePath();

    /*! Returns the debug path selection button
     * \returns QPushButton*
    */
    QPushButton* debugPathButton();
    /*! Returns the release path selection button
     * \returns QPushButton*
    */
    QPushButton* releasePathButton();

    /*! Hides/shows the reset buttons
     * \param hide - If the buttuns should be hidden
    */
    void hideResetButtons(bool hide);

    /*! Clears all the data
     * \param onlyText - If only the text should be cleared
    */
    void clear(bool onlyText);

private slots:
    /*! Resets the build name */
    void resetBuildName_clicked();

    /*! Resets the debug path */
    void resetDebugPath_clicked();
    /*! Resets the release path */
    void resetReleasePath_clicked();

private:
    QLineEdit* v_buildNameE = nullptr;
    QTextEdit* v_debugPathE = nullptr,*v_releasePathE = nullptr;
    QPushButton* v_debugPathB = nullptr,*v_releasePathB = nullptr;
    QPushButton* v_resetBuildNameB = nullptr,*v_resetDebugPathB = nullptr,*v_resetReleasePathB = nullptr;

    int v_oldDataPosition = -1;
    BuildDataP v_oldBuildData;

    /*! Initializes widgets that are used */
    void init();

};
#endif // BUILDDATAWIDGET_H
