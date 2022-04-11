//
// Created by Алексей Половин on 11.04.2022.
//

#include <QVBoxLayout>
#include <QLabel>
#include "editorsplashfragment.h"
#include "base/data/constants.h"
#include <QMovie>
#include <QTimer>

EditorSplashFragment::EditorSplashFragment() {
    auto *mainVLayout = new QVBoxLayout;
    auto *mainHLayout = new QHBoxLayout;
    this->setStyleSheet("QFrame {background-color:#1e2327;}");
//    QSvgWidget *centerConainer = new QSvgWidget(":/drawable/splash.svg");
        auto *centerConainer = new QLabel();
        QMovie *movie = new QMovie(":/drawable/resources/editorsplash.gif");
//        QPixmap pixmap(":/drawable/flex.png");
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
    void EditorSplashFragment::openStartScreen() {
        qDebug("open main menu");
        emit replace(EDITOR_WINDOW);
    }

