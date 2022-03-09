#include "mainwindow.h"

#include <QDesktopWidget>
#include <cwidgets/implfragmentfactory.h>
#include <cwidgets/slidingstackedwidget.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    try {
        qDebug("create main window");
        container = new SlidingStackedWidget(this);
        container->setObjectName("ui");

        this->factory = new ImplFragmentFactory;
        this->navigator = new Router(
                    this->container,
                    this->factory
        );

        QString mainStyle = "QWidget#window {"
                            "background-color:white;"
                            "}";
        container->setStyleSheet(mainStyle);
        container->setObjectName("window");

        this->setWindowTitle("BarybiansX");
//        this->setWindowIcon(QIcon(":/resc/resc/splash.svg"));
        this->resize(QDesktopWidget().availableGeometry(this).size() * 0.86);
        this->setCentralWidget(container);
    } catch (std::exception& e) {
        qDebug("%s", e.what());
    }
}

MainWindow::~MainWindow() {
    delete container;
    delete navigator;

}

