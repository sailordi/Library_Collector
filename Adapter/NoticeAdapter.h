#ifndef NOTICEADAPTER_H
#define NOTICEADAPTER_H

#include <QWidget>
#include <QSharedPointer>

class Notice;
class NoticeList;
class NoticePage;
class Settings;
class WindowNotice;

enum class NoticeFlag;

/*! \class NoticeAdapter
 * \brief The class is an adapter against a NoticePage and the WindowNotice
 *
 * Incudes: QWidget & QSharedPointer
 *
 * Forward declarations: Notice, NoticeFlag.h ,NoticeList, NoticePage, Settings & WindowNotice
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-21
 * \date Last update: 2021-05-21
*/
class NoticeAdapter
{
public:
    /*! Constructor
     * \param parent - The WindowNotice parent [Default: nullptr]
    */
    explicit NoticeAdapter(QWidget *parent = nullptr);
    /*! Deconstructor */
    ~NoticeAdapter();

    /*! Adds a Notice to the NoticeList the program uses
     * \param n - The Notice
     * \param f - The NoticeFlag [ERROR, WARNING, MESSAGE]
    */
    void add(Notice* n,NoticeFlag f);

    /*! Returns the NoticeList the program uses
     * \returns QSharedPointer<NoticeList>
    */
    QSharedPointer<NoticeList> list();

    /*! Resets the data and sets the WindowNotice title
     * \param title - The WindowNotice title
    */
    void reset(QString title);

    /*! Prepares and shows the WindowNotice */
    void show();

    /*! Saves or loads the windows settings
     * \param s - The settings handle
     * \param save - If settings should be saved
    */
    void saveLoadSettings(Settings* s,bool save);

private:
    WindowNotice* v_windowN = nullptr;
    QSharedPointer<NoticePage> v_page;

};
#endif // NOTICEADAPTER_H
