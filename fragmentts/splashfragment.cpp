#include "splashfragment.h"

#include <QDebug>
#include <QLabel>
#include <QSvgWidget>
#include <QTimer>
using namespace screens;






SplashFragment::SplashFragment() {
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    this->setStyleSheet("QFrame {background-color:#1e2327;}");
//    QSvgWidget *centerConainer = new QSvgWidget(":/drawable/splash.svg");
    QLabel *centerConainer = new QLabel();
    QPixmap pixmap(":/drawable/flex.png");
    centerConainer->setPixmap(pixmap);


//    centerConainer->setStyleSheet(SPLASH_ICON);

    mainHLayout->addWidget(centerConainer);
    mainHLayout->setAlignment(Qt::AlignCenter);
    mainVLayout->addLayout(mainHLayout);
    mainVLayout->setAlignment(Qt::AlignCenter);

    this->setObjectName("fragment");
    this->setLayout(mainVLayout);

    QTimer::singleShot(1000, this, SLOT(openStartScreen()));
}

SplashFragment::~SplashFragment() {

}

void SplashFragment::openStartScreen() {
    qDebug("open main menu");
    emit newRootScreen(LOGIN);

}
