#ifndef PATHITEMCREATOR_H
#define PATHITEMCREATOR_H

#include "Base/Adapter/StandardItemCreator.h"

/*! \class PathItemCreator
 * \brief The class is used for creating QStandardItems specific for path data
 *
 * Incudes: StandardItemCreator
 *
 * Inherits: StandardItemCreator
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-24
 * \date Last update: 2021-05-24
*/
class PathItemCreator : public StandardItemCreator
{
public:
    /*! Constructor */
    PathItemCreator();

    /*! Creates a non editable standard item
     * \param data - The data for the column
     * \param aligment - The text aligment
     * \returns QStandardItem*
    */
    QStandardItem* nonEditable(QVariant data, Qt::AlignmentFlag aligment) override;

};
#endif // PATHITEMCREATOR_H
