#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowMain; }
QT_END_NAMESPACE

/*! \class WindowMain
 * \brief The class is the main ui for the ptogram
 *
 * Incudes: QMainWindow
 *
 * Inherits: QMainWindow
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-20
 * \date Last update: 2021-05-20
*/
class WindowMain : public QMainWindow
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The windows parent [Default: nullptr]
    */
    WindowMain(QWidget *parent = nullptr);
    /*! Deconstructor */
    ~WindowMain();

private slots:
    /*! Slot that is activated when output path selection button is clicked */
    void libraryOutPathBtnClicked();

    /*! Slot that is activated when header path selection button is clicked */
    void libraryHeaderPathBtnClicked();

    /*! Slot that is activated when debug build path selection button is clicked */
    void libraryDebugPathBtnClicked();
    /*! Slot that is activated when releas build path selection button is clicked */
    void libraryReleasePathBtnClicked();

    /*! Slot that is activated when preform collection button is clicked */
    void preformCollectionBtnClicked();

private:
    Ui::WindowMain* v_ui = nullptr;

};
#endif // WINDOWMAIN_H
