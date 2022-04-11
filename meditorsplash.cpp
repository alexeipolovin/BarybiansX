//
// Created by Алексей Половин on 11.04.2022.
//

#include <QGuiApplication>
#include "meditorsplash.h"
#include "cwidgets/implfragmentfactory.h"
#include <QScreen>
MEditorSplash::MEditorSplash() : QMainWindow(){
    try {
        qDebug("create main window");
        container = new SlidingStackedWidget(this);
        container->setObjectName("ui");

        this->factory = new ImplFragmentFactory;
        this->navigator = new Router(
                this->container,
                this->factory,
                true
        );

        QString mainStyle = "QWidget#window {"
                            "background-color:black;"
                            "}";
        container->setStyleSheet(mainStyle);

        this->setWindowTitle("BarybiansX");
        this->setWindowIcon(QIcon(":/drawable/flex.png"));
        QScreen *screen = QGuiApplication::primaryScreen();
        this->resize(screen->availableGeometry().size() * 0.86);
        this->setCentralWidget(container);
    } catch (std::exception& e) {
        qDebug("%s", e.what());
    }
}