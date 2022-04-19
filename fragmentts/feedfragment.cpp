//
// Created by Алексей Половин on 18.04.2022.
//

#include <QtWidgets/qscrollarea.h>
#include "feedfragment.h"
#include "cwidgets/addition/cardwidget.h"
#include <QScrollBar>
#include <QLabel>
#include <QPushButton>
#include <exception>

void FeedFragment::bindWebConnector(WebConnector *webConnectorCopy) {
    this->webConnector = webConnectorCopy;
    qDebug() << "Totoken:" << webConnector->token;
    downloadFeed();


}

void FeedFragment::downloadFeed() {
    QVector<Post*> *secVec = webConnector->getFeed();
       for(auto i : *secVec) {
           qDebug() << i->userId;
               qDebug() << "KEKEKEKEKE";
            auto *widget = new CardWidget(this);
            widget->setFixedWidth(1200);
            auto *layout = new QVBoxLayout(this);
            auto *title = new QLabel("<b>" + i->title + "</b>");
            title->setWordWrap(true);
            auto *text = new QLabel(i->text);
            text->setTextFormat(Qt::RichText);
            text->setWordWrap(true);
            layout->addWidget(title);
            layout->addWidget(text);
            widget->setLayout(layout);
            mainLayout->addWidget(widget);
       }
       mainLayout->setAlignment(Qt::AlignVCenter);
       scrollableArea->setLayout(mainLayout);
       scrollArea->setWidget(scrollableArea);
       anotherLay->addWidget(scrollArea);
       scrollArea->setMinimumSize(QSize(200, 200));
       this->setLayout(anotherLay);

//       delete secVec;
}

void FeedFragment::bindData(BaseModel *model) {
}
FeedFragment::FeedFragment() : BaseFragment()
{
    anotherLay = new QVBoxLayout();
    scrollArea = new QScrollArea(this);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainLayout = new QVBoxLayout(this);
    anotherLay->addWidget(scrollArea);
    scrollableArea = new QWidget();
}
