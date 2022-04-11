//
// Created by Алексей Половин on 11.04.2022.
//

#ifndef BARYBIANSX_MEDITORSPLASH_H
#define BARYBIANSX_MEDITORSPLASH_H


#include <QtCore>
#include <QMainWindow>
#include "cwidgets/slidingstackedwidget.h"
#include "base/router.h"
#include "base/basefragmentfactory.h"

class MEditorSplash : public QMainWindow {
    Q_OBJECT
public:
    MEditorSplash();
private:
    SlidingStackedWidget *container;
    Router *navigator;
    BaseFragmentFactory *factory;
};


#endif //BARYBIANSX_MEDITORSPLASH_H
