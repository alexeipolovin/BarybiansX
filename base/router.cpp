#include "router.h"

#include <QLinkedList>

Router::Router(
        SlidingStackedWidget *container,
        BaseFragmentFactory *screensFactory
) {
    qDebug("create navigator");
    this->screensFactory = screensFactory;
    this->currentContainer = container;
    qDebug("create start fragment");
    BaseFragment* startFragment = getStartScreen();
    qDebug("append start fragment");
    this->stack.append(startFragment);

    qDebug("add widget");
    currentContainer->addWidget(stack.last());
    currentContainer->setCurrentIndex(0);
}

Router::~Router() {
}

void Router::navigateTo(QString tag) {
    qDebug("Navigator navigateTo");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    stack.last()->onPause();
    disconnectFragment(stack.last());
    connectFragment(newFragment);
    stack.append(newFragment);
    currentContainer->addWidget(newFragment);
    currentContainer->slideInIdx(stack.size()-1);
}

void Router::back() {
    qDebug("Navigator back");
    currentContainer->slideInIdx(stack.size()-2);
    connect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Router::removeOnFinishLast);
}

void Router::removeOnFinishLast() {
    disconnect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Router::removeOnFinishLast);
    currentContainer->removeWidget(stack.last());
    delete stack.last();
    stack.removeLast();
    connectFragment(stack.last());
    stack.last()->onResume();
}

void Router::replace(QString tag) {
    qDebug("Navigator replace");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    connect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Router::removeOnReplace);
    disconnectFragment(stack.last());
    stack.append(newFragment);
    currentContainer->addWidget(newFragment);
    currentContainer->slideInIdx(stack.size()-1);
}

void Router::removeOnReplace() {
    disconnect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Router::removeOnReplace);
    connectFragment(stack.last());
    BaseFragment* last = stack.last();
    stack.removeLast();
    currentContainer->removeWidget(stack.last());
    stack.removeLast();
    stack.append(last);
}

void Router::newRootScreen(QString tag) {
    qDebug("Navigator newRootScreen");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    connect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Router::removeOnRoot);
    disconnectFragment(stack.last());
    stack.append(newFragment);
    connectFragment(newFragment);
    currentContainer->addWidget(newFragment);
    currentContainer->slideInIdx(stack.size()-1);
}

void Router::removeOnRoot() {
    disconnect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Router::removeOnRoot);
    BaseFragment* last = stack.last();
    stack.clear();
    for(int i = 0; i <= currentContainer->count()-1; i++)
    {
        QWidget* widget = currentContainer->widget(i);
        currentContainer->removeWidget(widget);
        widget->deleteLater();
    }
    stack.append(last);
}

void Router::backWhithData(BaseModel* model) {
    stack[stack.size()-2]->bindData(model);
    back();
}

void Router::navigateWhithData(QString tag, BaseModel* model) {
    navigateTo(tag);
    stack.last()->bindData(model);
}


void Router::replaceWhithData(QString tag, BaseModel* model) {
    replace(tag);
    stack.last()->bindData(model);
}

BaseFragment* Router::getStartScreen() {
    return createAndConnect(this->screensFactory->createStart());
}

void Router::connectFragment(BaseFragment *fragment) {
    qDebug("Navigator connect slots");
    connect(fragment, &BaseFragment::back, this, &Router::back);
    connect(fragment, &BaseFragment::replace, this, &Router::replace);
    connect(fragment, &BaseFragment::navigateTo, this, &Router::navigateTo);
    connect(fragment, &BaseFragment::newRootScreen, this, &Router::newRootScreen);
    connect(fragment, &BaseFragment::backWhithData, this, &Router::backWhithData);
    connect(fragment, &BaseFragment::navigateWhithData, this, &Router::navigateWhithData);
    connect(fragment, &BaseFragment::replaceWhithData, this, &Router::replaceWhithData);
}

void Router::disconnectFragment(BaseFragment *fragment) {
    qDebug("Navigator disconnect slots");
    disconnect(fragment, &BaseFragment::back, this, &Router::back);
    disconnect(fragment, &BaseFragment::replace, this, &Router::replace);
    disconnect(fragment, &BaseFragment::navigateTo, this, &Router::navigateTo);
    disconnect(fragment, &BaseFragment::newRootScreen, this, &Router::newRootScreen);
    disconnect(fragment, &BaseFragment::backWhithData, this, &Router::backWhithData);
    disconnect(fragment, &BaseFragment::navigateWhithData, this, &Router::navigateWhithData);
    disconnect(fragment, &BaseFragment::replaceWhithData, this, &Router::replaceWhithData);
}

BaseFragment* Router::createAndConnect(QString tag) {
    BaseFragment *fragment = this->screensFactory->create(tag);
    qDebug("Navigator create screen");
    connectFragment(fragment);
    return fragment;
}
