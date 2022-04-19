#ifndef IMPLFRAGMENTFACTORY_H
#define IMPLFRAGMENTFACTORY_H

#include <QString>


#include <base/basefragmentfactory.h>

class ImplFragmentFactory: public BaseFragmentFactory {
public:
    ImplFragmentFactory();
    ~ImplFragmentFactory();

    int id = 4;

//    BaseFragment* create(QString tag) override;
    SCREEN createStart() override;
    BaseFragment *create(SCREEN tag) override;

    void setDialogId(int id);
};

#endif // IMPLFRAGMENTFACTORY_H
