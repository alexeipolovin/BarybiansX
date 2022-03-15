#include "implfragmentfactory.h"

#include <QString>

#include <fragmentts/loginfragment.h>
#include <fragmentts/splashfragment.h>
#include <fragmentts/userfragment.h>
#include <fragmentts/userpagefragment.h>



using namespace screens;

ImplFragmentFactory::ImplFragmentFactory(){}
ImplFragmentFactory::~ImplFragmentFactory(){}

BaseFragment* ImplFragmentFactory::create(QString tag) {
    qDebug("ScreensFactory create");
    if (tag == SPLASH_TAG) {
        return new SplashFragment;
    } else if (tag == LOGIN) {
        return new LoginFragment;
    } else if(tag == USER_PAGE){
        return new UserPageFragment;
    } else {
        return nullptr;
    }
}

QString ImplFragmentFactory::createStart() {
    return SPLASH_TAG;
}
