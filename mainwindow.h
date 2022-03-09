#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "basefragmentfactory.h"

#include <QMainWindow>
#include <QStackedWidget>

#include <cwidgets/slidingstackedwidget.h>

#include <base/router.h>



class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    SlidingStackedWidget *container;
    Router *navigator;
    BaseFragmentFactory *factory;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
