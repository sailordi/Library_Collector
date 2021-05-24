#ifndef BUILDDATATREEVIEWADAPTER_H
#define BUILDDATATREEVIEWADAPTER_H

#include "Base/Adapter/TreeViewAdapterNoChildRows.h"

/*! \class BuildDataTreeViewAdapter
 * \brief The class is an adapter against a QTreeView without child rows for the build data
 *
 * Incudes: TreeViewAdapterNoChildRows
 *
 * Inherits: TreeViewAdapterNoChildRows
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-24
 * \date Last update: 2021-05-24
*/
class BuildDataTreeViewAdapter : public TreeViewAdapterNoChildRows
{
public:
    /*! Constructor */
    BuildDataTreeViewAdapter();

private:
    /*! Generates the columns the view needs
     * \param l - Column item list
     * \param data - The data to turn into columns
    */
    void generateColumns(QList<QStandardItem*>& l, QList<QVariant> data) override;

};
#endif // BUILDDATATREEVIEWADAPTER_H
