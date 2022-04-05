#include "userpagefragment.h"
#include <QWidget>
#include <QFrame>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QSettings>
#include <QSvgWidget>
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonArray>
#include <QScrollArea>
#include <QScrollBar>
#include <QNetworkReply>
#include <QColor>

#include <QFile>
#include <QPixmap>
#include <QSizePolicy>
#include <QVector>

#include <base/data/data.h>

#include <cwidgets/addition/cardwidget.h>

#include <base/utils/webconnector.h>
UserPageFragment::UserPageFragment()
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

    QVBoxLayout *buttonLay = new QVBoxLayout();
    QPushButton *sendMessageButton = new QPushButton();
    connect(sendMessageButton, &QPushButton::clicked, this, [this]() {
    });
    buttonLay->addLayout(profilelay);
    buttonLay->addWidget(sendMessageButton);

    lastVisit->setAlignment(Qt::AlignLeft);
    menuContainer = new QVBoxLayout;
    menuContainer->setAlignment(Qt::AlignHCenter);
    menuContainer->setContentsMargins(0, 16, 0, 0);
    menuContainer->setSpacing(16);

    // карточка заголовка
    CardWidget *menuHeaderCard = new CardWidget(this);
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


    downloadFeed();
}

void UserPageFragment::downloadFeed() {
    QSettings *settings = new QSettings();
    webConnector->setLoginAndPassword(settings->value("LOGIN").toString(), settings->value("PASSWORD").toString());
    connect(webConnector, &WebConnector::valueChanged, this, [this]() {
        QNetworkRequest request = webConnector->createRequest("https://api.barybians.ru​​/v2/posts", WebConnector::GET_FEED);
    webConnector->sendRequest(request, WebConnector::GET_FEED);
    connect(webConnector, &WebConnector::feedOk, this, [this]() {
       QVector<Post*> *secVec = webConnector->getFeed();

       for(auto i : *secVec) {
           qDebug() << i->userId;
           if(i->userId == webConnector->mainUser->id) {
               qDebug() << "KEKEKEKEKE";
            CardWidget *widget = new CardWidget(this);
            QVBoxLayout *layout = new QVBoxLayout(this);
            QLabel *title = new QLabel("<b>" + i->title + "</b>");
            title->setWordWrap(true);
            QLabel *text = new QLabel(i->text);
            text->setTextFormat(Qt::RichText);
            text->setWordWrap(true);
            layout->addWidget(title);
            layout->addWidget(text);
            widget->setLayout(layout);
            menuContainer->addWidget(widget);
           }
       }
       this->setLayout(scrollContainerLayout);
    });
});
    delete settings;
}


void UserPageFragment::bindWebConnector(WebConnector *webConnector) {
    this->webConnector = webConnector;
    this->webConnector->getAllUsers();


}
void UserPageFragment::bindData(BaseModel *model) {
    User *mainUser = (User *) model;

    this->fullName->setText(mainUser->name + " " + mainUser->lastName);
    qDebug() << "main_user_name:" << mainUser->name;
    this->fullName->setStyleSheet("background:none");
//    this->picture->setPixmap(QPixmap(mainUser->photoName));
    QFile fileName(":/drawable/main_user_photo.png");
    if(fileName.open(QFile::ReadOnly)) {
        QPixmap pixMap;
        pixMap.loadFromData(fileName.readAll());

        this->picture->setPixmap(pixMap);
    }
    this->picture->setAlignment(Qt::AlignCenter);
    this->picture->setStyleSheet("background:none");

    this->status->setText(mainUser->status);
    this->status->setStyleSheet("background:none");

    this->lastVisit->setText(mainUser->lastVisit);
    this->lastVisit->setStyleSheet("background:none");
}

