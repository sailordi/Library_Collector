#include "NoticeAdapter.h"

#include "Message/Notice/NoticeList.h"
#include "Message/Notice/NoticeFlag.h"
#include "Message/Notice/NoticePage.h"
#include "Message/WindowNotice.h"

//Public functions
NoticeAdapter::NoticeAdapter(QWidget* parent) {
    this->v_windowN = new WindowNotice(parent);
    this->v_page = QSharedPointer<NoticePage>(new NoticePage() );

    this->v_windowN->setWindowModality(Qt::WindowModal);

    this->v_windowN->add(this->v_page);
}

NoticeAdapter::~NoticeAdapter() {
    delete this->v_windowN;
}

void NoticeAdapter::add(Notice* n,NoticeFlag f) {
    this->list()->add(n,f);
}

QSharedPointer<NoticeList> NoticeAdapter::list() {
    if(this->v_page->size() <= 0) {
        this->v_page->add(new NoticeList() );
    }

    return this->v_page->list(0);
}

void NoticeAdapter::reset(QString title) {
    this->v_windowN->setWindowTitle(title);

    if(this->v_page->size() > 0) {
        this->v_page->list(0)->clear();
    }

}
