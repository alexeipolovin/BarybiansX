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
            auto *layout = new QVBoxLayout(this);
            auto *title = new QLabel("<b>" + i->title + "</b>");
            title->setWordWrap(true);
            auto *text = new QLabel(i->text);
            text->setTextFormat(Qt::RichText);
            text->setWordWrap(true);
            layout->addWidget(title);
            layout->addWidget(text);
            widget->setLayout(layout);
            menuContainer->addWidget(widget);
       }
       this->setLayout(scrollContainerLayout);

//       delete secVec;
}

void FeedFragment::bindData(BaseModel *model) {

}
FeedFragment::FeedFragment()
{
    // прокручивающийся контеинер
    scrollContainerLayout = new QVBoxLayout;
    scrollContainerLayout->setContentsMargins(0, 0, 0, 0);
    // зона прокрутки
    scrollArea = new QScrollArea();
    scrollArea->setStyleSheet("background-color:#1e2327;");
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setMinimumSize(QSize(200, 200));
    scrolConttent = new QWidget;
    scrolConttent->setObjectName("container");
//    scrollArea->setStyleSheet(SCROL_BAR);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrolConttent);
    scrollArea->horizontalScrollBar()->setEnabled(false);
    scrollArea->verticalScrollBar()->hide();
    scrollContainerLayout->addWidget(scrollArea);

    // главный контеинер
    mainContainerLaout = new QVBoxLayout;
    scrollArea->setLayout(mainContainerLaout);
    mainContainerFrame = new QFrame;
    mainContainerLaout->addWidget(mainContainerFrame);
    mainContainerLaout->setContentsMargins(0, 0, 0, 0);
    mainContainerLaout->setSpacing(0);
    mainContainerLaout->setAlignment(Qt::AlignTop);
    scrolConttent->setLayout(mainContainerLaout);

    // фон
    backContainerLaout = new QVBoxLayout;
    backContainerLaout->setAlignment(Qt::AlignTop);
    backContainerLaout->setContentsMargins(0, 0, 0, 0);
    mainContainerFrame->setLayout(backContainerLaout);
    // фоновый градиент
    backGradient = new QFrame;
    backGradient->setMinimumHeight(248);
    backGradient->setMaximumHeight(248);
    backGradient->setMidLineWidth(50);
    backGradient->setStyleSheet( "QFrame {"
                "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                "stop:0 #0596FF, stop:1 #8773FF);}"
    );
    profilelay = new QHBoxLayout();
    profilelay->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    namelay = new QVBoxLayout();
    namelay->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    fullName = new QLabel();
    status = new QLabel();
    picture = new QLabel();
    lastVisit = new QLabel();

    profilelay->addWidget(picture);

    namelay->addWidget(fullName);
    namelay->addWidget(status);

    profilelay->addLayout(namelay);

    auto *buttonLay = new QVBoxLayout();
    auto *sendMessageButton = new QPushButton("Dialog");
    auto *writePostButton = new QPushButton("Write post");
    auto goToFeed = new QPushButton("Feed");
    connect(sendMessageButton, &QPushButton::clicked, this, []() {
    });
    buttonLay->addLayout(profilelay);
    buttonLay->addWidget(writePostButton);
    buttonLay->addWidget(goToFeed);
    connect(goToFeed, &QPushButton::clicked, this, [this]() {
        emit replaceWithDataAndWebConnector(FEED, this->webConnector->mainUser, webConnector);
    });

    writePostButton->setStyleSheet("QPushButton{"
                                   "background-color: #1e2327;"
                                   "border-style: solid;"
                                   "border-color: #1e2327;"
                                   "font-size:14px;"
                                   "border-width: 5px;"
                                   "border-radius: 10px;"
                                   "}"
    );
    goToFeed->setStyleSheet("QPushButton{"
                            "background-color: #1e2327;"
                            "border-style: solid;"
                            "border-color: #1e2327;"
                            "font-size:14px;"
                            "border-width: 5px;"
                            "border-radius: 10px;"
                            "}");
    sendMessageButton->setFixedWidth(120);
    sendMessageButton->setStyleSheet(" QPushButton { border-radius: 20; color:white; background-color:black; }");
    connect(sendMessageButton, &QPushButton::clicked, this, [this]() {
       emit replaceWithDataAndWebConnector(DIALOG_WITH, this->webConnector->mainUser, webConnector);
    });

    lastVisit->setAlignment(Qt::AlignLeft);
    menuContainer = new QVBoxLayout;
    menuContainer->setAlignment(Qt::AlignHCenter);
    menuContainer->setContentsMargins(0, 16, 0, 0);
    menuContainer->setSpacing(16);

    // карточка заголовка
    auto *menuHeaderCard = new CardWidget(this);
    menuHeaderCard->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    menuHeaderCard->setMaximumWidth(952);
    menuHeaderCard->setMinimumWidth(952);
    menuContainer->addWidget(menuHeaderCard);
    headerLayout = new QVBoxLayout;
    headerLayout->setAlignment(Qt::AlignLeft);
    headerLayout->setContentsMargins(20, 20, 20, 20);

    backGradient->setLayout(buttonLay);
    backContainerLaout->addWidget(backGradient);


    mainContainerLaout->addLayout(menuContainer);
//    mainContainerLaout->addLayout(headerLayout);

}
