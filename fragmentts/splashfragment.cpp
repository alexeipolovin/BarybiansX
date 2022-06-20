#include "splashfragment.h"

#include <QLabel>
#include <QTimer>
#include <base/data/constants.h>
#include <QMovie>




SplashFragment::SplashFragment() {
    auto *mainVLayout = new QVBoxLayout;
    auto *mainHLayout = new QHBoxLayout;
    this->setStyleSheet("QFrame {background-color:#1e2327;}");
//    QSvgWidget *centerConainer = new QSvgWidget(":/drawable/splash.svg");
    auto *centerConainer = new QLabel();
//    QPixmap pixmap(":/drawable/flex.png");
//    centerConainer->setPixmap(pixmap);

    QMovie *movie = new QMovie(":/drawable/resources/preloader.webp");
    centerConainer->setMovie(movie);
    movie->start();

//    centerConainer->setStyleSheet(SPLASH_ICON);

    mainHLayout->addWidget(centerConainer);
    mainHLayout->setAlignment(Qt::AlignCenter);
    mainVLayout->addLayout(mainHLayout);
    mainVLayout->setAlignment(Qt::AlignCenter);

    this->setObjectName("fragment");
    this->setLayout(mainVLayout);

    QTimer::singleShot(1000, this, SLOT(openStartScreen()));
}

SplashFragment::~SplashFragment() = default;

void SplashFragment::openStartScreen() {
    qDebug("open main menu");
    emit newRootScreen(LOGIN);

}
