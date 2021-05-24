#ifndef BUILDDATAVIEWWIDGET_H
#define BUILDDATAVIEWWIDGET_H

#include "Base/LayoutWidget/SingleLayoutWidget.h"

#include <QList>
#include <QString>

#include "Data/BuildDataTypedefs.h"

class QLabel;

class BuildDataTreeViewAdapter;

/*! \class BuildDataViewWidget
 * \brief The class contains widgets for the build data view
 *
 * Incudes: QList, QString, BuildDataTypedefs.h & SingleLayoutWidget
 *
 * Forward declarations: QLabel & BuildDataTreeViewAdapter
 *
 * Inherits: SingleLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-24
 * \date Last update: 2021-05-24
*/
class BuildDataViewWidget : public SingleLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param l - The layout for the build data view widgets
     * \param parent - The parent [Default: nullptr]
    */
    explicit BuildDataViewWidget(QVBoxLayout* l,QWidget *parent = nullptr);
    /*! Deconstructor */
    ~BuildDataViewWidget();

private:
    QLabel* v_buildInfoL = nullptr;

    QList<BuildDataP> v_buildDataList;

    BuildDataTreeViewAdapter* v_view = nullptr;

};
#endif // BUILDDATAVIEWWIDGET_H
