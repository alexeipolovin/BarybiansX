#include "implfragmentfactory.h"

#include <QString>

#include <fragmentts/loginfragment.h>
#include <fragmentts/splashfragment.h>



using namespace screens;

ImplFragmentFactory::ImplFragmentFactory(){}
ImplFragmentFactory::~ImplFragmentFactory(){}

BaseFragment* ImplFragmentFactory::create(QString tag) {
    qDebug("ScreensFactory create");
    if (tag == SPLASH_TAG) {
        return new SplashFragment;
    } else if (tag == LOGIN) {
        return new LoginFragment;
    } else {
        return nullptr;
    }
}

QString ImplFragmentFactory::createStart() {
    return SPLASH_TAG;
}
