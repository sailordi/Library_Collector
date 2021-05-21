#include "NoticeAdapter.h"

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
