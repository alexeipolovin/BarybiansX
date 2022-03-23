#include "implfragmentfactory.h"

#include <QString>

#include <fragmentts/loginfragment.h>
#include <fragmentts/splashfragment.h>
#include <fragmentts/userfragment.h>
#include <fragmentts/userpagefragment.h>



ImplFragmentFactory::ImplFragmentFactory(){}
ImplFragmentFactory::~ImplFragmentFactory(){}

BaseFragment* ImplFragmentFactory::create(SCREEN tag) {
    qDebug("ScreensFactory create");
    switch (tag) {
    case SPLASH:
        return new SplashFragment;
        break;
    case LOGIN:
        return new LoginFragment;
        break;
    case USER_PAGE:
        return new UserPageFragment;
        break;
    }
}

SCREEN ImplFragmentFactory::createStart() {
    return SPLASH;
}
