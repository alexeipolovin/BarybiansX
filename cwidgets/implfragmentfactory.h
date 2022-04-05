#ifndef IMPLFRAGMENTFACTORY_H
#define IMPLFRAGMENTFACTORY_H

#include <QString>


#include <base/basefragmentfactory.h>

class ImplFragmentFactory: public BaseFragmentFactory {
public:
    ImplFragmentFactory();
    ~ImplFragmentFactory();

//    BaseFragment* create(QString tag) override;
    SCREEN createStart() override;
    BaseFragment *create(SCREEN tag) override;
};

#endif // IMPLFRAGMENTFACTORY_H
