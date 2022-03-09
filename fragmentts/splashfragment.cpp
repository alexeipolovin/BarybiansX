#include "splashfragment.h"

#include <QDebug>
#include <QSvgWidget>
#include <QTimer>
using namespace screens;






SplashFragment::SplashFragment() {
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QSvgWidget *centerConainer = new QSvgWidget(":/drawable/splash.svg");


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
