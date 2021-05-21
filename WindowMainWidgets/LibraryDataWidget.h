#ifndef LIBRARYDATAWIDGET_H
#define LIBRARYDATAWIDGET_H

#include "Base/LayoutWidget/SingleLayoutWidget.h"

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

/*! \class LibraryDataWidget
 * \brief The class contains library data and handles the widgets
 *
 * Incudes: SingleLayoutWidget
 *
 * Forward declarations: QLabel,QLineEdit,QTextEdit & QPushButton
 *
 * Inherits: SingleLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-21
 * \date Last update: 2021-05-21
*/
class LibraryDataWidget : public SingleLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param l - The layout
     * \param dataStr - The data label string
     * \param fileD - File dialog string
     * \param name - If name field is needed
     * \param parent - The parent to be used [Default: nullptr]
    */
    LibraryDataWidget(QGridLayout* l,QString dataStr,bool name,QWidget *parent = nullptr);

    /*! Sets the path data
     * \param str - Path string
    */
    void setPath(QString str);
    /*! Sets the name data if field is needed
     * \param str - Name string
    */
    void setName(QString str);

private:
    QLabel* v_dataL = nullptr,*v_pathL = nullptr,*v_nameL = nullptr;
    QTextEdit* v_pathE = nullptr;
    QLineEdit* v_nameE = nullptr;
    QPushButton* v_selBtn = nullptr;

    bool v_name;

    /*! Initializes widgets that are used */
    void init(QString dataStr);

};
#endif // LIBRARYDATAWIDGET_H
