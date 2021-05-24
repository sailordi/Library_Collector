#ifndef MAININFOWIDGET_H
#define MAININFOWIDGET_H

#include "Base/LayoutWidget/SingleLayoutWidget.h"

class QLineEdit;
class QTextEdit;
class QPushButton;

/*! \class MainInfoWidget
 * \brief The class contains widgets for the main info layout
 *
 * Incudes: SingleLayoutWidget
 *
 * Forward declarations: QLineEdit, QTextEdit & QPushButton
 *
 * Inherits: SingleLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-24
 * \date Last update: 2021-05-24
*/
class MainInfoWidget : public SingleLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param l - The layout for the main info widgets
     * \param parent - The parent [Default: nullptr]
    */
    MainInfoWidget(QGridLayout* l,QWidget* parent = nullptr);

private:
    QTextEdit* v_outputPathE = nullptr,*v_headerPathE = nullptr;
    QLineEdit* v_libraryBaseNameE = nullptr;
    QPushButton* v_outputPathB = nullptr,*v_headerPathB = nullptr;

};
#endif // MAININFOWIDGET_H
