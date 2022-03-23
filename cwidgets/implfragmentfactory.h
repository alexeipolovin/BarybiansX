#ifndef IMPLFRAGMENTFACTORY_H
#define IMPLFRAGMENTFACTORY_H

#include <QString>


#include <base/basefragmentfactory.h>

    //static const QString SERVER_URL = "http://localhost:8080";

//    static const QString SPLASH_TAG = "splash";
//    static const QString SEARCH_GROUP = "search_group";
//    static const QString LOGIN = "login";
//    static const QString USER_PAGE = "user_page";

class ImplFragmentFactory: public BaseFragmentFactory {
public:
    ImplFragmentFactory();
    ~ImplFragmentFactory();

//    BaseFragment* create(QString tag) override;
    SCREEN createStart() override;
    BaseFragment *create(SCREEN tag) override;
};

#endif // IMPLFRAGMENTFACTORY_H
