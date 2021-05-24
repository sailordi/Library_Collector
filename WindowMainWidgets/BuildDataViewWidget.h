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

    /*! Returns the list of build data
     * \returns QList<BuildDataP>
    */
    QList<BuildDataP> buildDataList();
    /*! Returns a pointer the list of build data
     * \returns QList<BuildDataP>*
    */
    QList<BuildDataP>* buildDataListP();

    /*! Returns the number of selected rows
     * \returns int
    */
    int numberOfSelectedRows();
    /*! Returns a list with the positions of the slected rows
     * \returns QList<int>
    */
    QList<int> selectedRowsPosition();

private:
    QLabel* v_buildInfoL = nullptr;

    QList<BuildDataP> v_buildDataList;

    BuildDataTreeViewAdapter* v_view = nullptr;

    /*! Initializes widgets that are used */
    void init();

};
#endif // BUILDDATAVIEWWIDGET_H
