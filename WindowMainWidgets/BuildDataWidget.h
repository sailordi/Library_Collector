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
 * \date Last update: 2021-05-24
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

    /*! Clears all the data
     * \param onlyText - If only the text should be cleared
    */
    void clear(bool onlyText);

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
