#include "implfragmentfactory.h"

#include <QString>

#include <fragmentts/loginfragment.h>
#include <fragmentts/splashfragment.h>
#include <fragmentts/userfragment.h>
#include <fragmentts/userpagefragment.h>



ImplFragmentFactory::ImplFragmentFactory() = default;
ImplFragmentFactory::~ImplFragmentFactory() = default;

BaseFragment* ImplFragmentFactory::create(SCREEN tag) {
    qDebug("ScreensFactory create");
    switch (tag) {
    case SPLASH:
        return new SplashFragment;
    case LOGIN:
        return new LoginFragment;
    case USER_PAGE:
        return new UserPageFragment;
    case DIALOG_WITH:
        break;
    }
    return nullptr;
}

SCREEN ImplFragmentFactory::createStart() {
    return SPLASH;
}
