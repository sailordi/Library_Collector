#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowMain; }
QT_END_NAMESPACE

class BuildDataViewWidget;
class BuildDataWidget;
class MainInfoWidget;
class NoticeAdapter;

#include "Data/BuildDataTypedefs.h"

/*! \class WindowMain
 * \brief The class is the main ui for the ptogram
 *
 * Incudes: QMainWindow
 *
 * Inherits: QMainWindow
 *
 * Forward declarations: BuildDataViewWidget, BuildDataWidget, BuildDataTypedefs.h, MainInfoWidget & NoticeAdapter
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-20
 * \date Last update: 2021-05-26
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

    /*! Preperes the build data tab for adding / updating data
     * \param oldDataPosition - The old datas position in the data list [Default: -1]
     * \param data - The pointer to the data [Default: BuildDataP()]
    */
    void prepareBuildDataTab(int oldDataPosition = -1,BuildDataP data = BuildDataP() );

private slots:
    /*! Slot that is activated when output path selection button is clicked */
    void libraryOutPathBtnClicked();

    /*! Slot that is activated when header path selection button is clicked */
    void libraryHeaderPathBtnClicked();

    /*! Slot that is activated when debug build path selection button is clicked */
    void libraryDebugPathBtnClicked();
    /*! Slot that is activated when releas build path selection button is clicked */
    void libraryReleasePathBtnClicked();

    /*! Stot that is activated when the add/update button is clicked */
    void addUpdateBtnClicked();
    /*! Slot that is activated when the cancel update button is clicked */
    void cancelUpdateBtnClicked();

    /*! Slot that is activated when update selected build data menu item is clicked */
    void updateSelectedBuildData();
    /*! Slot that is activated when remove selected build data menu item is clicked */
    void removeSelectedBuildData();

    /*! Slot that is activated when preform collection button is clicked */
    void preformCollectionBtnClicked();

    /*! Saves the program data */
    void saveProgramData();
    /*! Loads the program data */
    void loadProgramData();

private:
    Ui::WindowMain* v_ui = nullptr;

    MainInfoWidget* v_mainInfoW = nullptr;
    BuildDataViewWidget* v_buildDataViewW = nullptr;
    BuildDataWidget* v_buildDataW = nullptr;

    NoticeAdapter* v_noticeA = nullptr;

    /*! Sets the all the tabs palett */
    void setTabsPalett();

    /*! Adds data to the build data list */
    void addData();
    /*! Updates the selected build data */
    void updateData();

    /*! Saves the windows settings */
    void saveWindowSettings();
    /*! Loads the windows settings */
    void loadWindowSettings();

};
#endif // WINDOWMAIN_H
