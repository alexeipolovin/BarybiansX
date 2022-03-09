#ifndef IMPLFRAGMENTFACTORY_H
#define IMPLFRAGMENTFACTORY_H

#include <QString>


#include <base/basefragmentfactory.h>


namespace screens {
    static const QString SERVER_URL = "https://jutter.online/mai_v2";
    //static const QString SERVER_URL = "http://localhost:8080";

    static const QString SPLASH_TAG = "splash";
    static const QString SEARCH_GROUP = "search_group";
    static const QString LOGIN = "login";
};

class ImplFragmentFactory: public BaseFragmentFactory {
public:
    ImplFragmentFactory();
    ~ImplFragmentFactory();

    BaseFragment* create(QString tag) override;
    QString createStart() override;
};

#endif // IMPLFRAGMENTFACTORY_H
