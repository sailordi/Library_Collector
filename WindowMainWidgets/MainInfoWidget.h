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
 * \date Last update: 2022-10-18
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

    /*! Sets the output path
     * \param outputPath - The outputh path
    */
    void setOutputPath(QString outputPath);
    /*! Sets the header path
     * \param headerPath - The header path
    */
    void setHeaderPath(QString headerPath);
    /*! Sets the library base name
     * \param libraryBaseName - The library base name
    */
    void setLibraryBaseName(QString libraryBaseName);
    /*! Sets the library base build name separator
     * \param baseBuildNameSeparator - The library base build name separator
    */
    void setBaseBuildNameSeparator(QString baseBuildNameSeparator);

    /*! Returns the output path
     * \returns QString
    */
    QString outputPath();
    /*! Returns the header path
     * \returns QString
    */
    QString headerPath();
    /*! Returns the library base name
     * \returns QString
    */
    QString libraryBaseName();
    /*! Returns the library Base build name separator
     * \returns QString
    */
    QString baseBuildNameSeparator();

    /*! Returns the output path selection button
     * \returns QPushButton*
    */
    QPushButton* outputPathButton();
    /*! Returns the header path selection button
     * \returns QPushButton*
    */
    QPushButton* headerPathButton();

private:
    QTextEdit* v_outputPathE = nullptr,*v_headerPathE = nullptr;
    QLineEdit* v_libraryBaseNameE = nullptr,*v_baseBuildNameSeparatorE = nullptr;
    QPushButton* v_outputPathB = nullptr,*v_headerPathB = nullptr;

    /*! Initializes widgets that are used */
    void init();

};
#endif // MAININFOWIDGET_H
