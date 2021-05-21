#ifndef NOTICEADAPTER_H
#define NOTICEADAPTER_H

#include <QWidget>
#include <QSharedPointer>

class NoticePage;
class WindowNotice;

/*! \class NoticeAdapter
 * \brief The class is an adapter against a NoticePage and the WindowNotice
 *
 * Incudes: QWidget & QSharedPointer
 *
 * Forward declarations: NoticePage & WindowNotice
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

private:
    WindowNotice* v_windowN = nullptr;
    QSharedPointer<NoticePage> v_page;

};
#endif // NOTICEADAPTER_H
