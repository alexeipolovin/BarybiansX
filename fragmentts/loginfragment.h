#ifndef SEARCHGROUPFRAGMENT_H
#define SEARCHGROUPFRAGMENT_H

#include <base/basefragment.h>
#include <QObject>
#include <QVBoxLayout>




class LoginFragment: public BaseFragment {
    Q_OBJECT

private:
    QVBoxLayout *mainVLayout;

public:
    LoginFragment();

};

#endif // SEARCHGROUPFRAGMENT_H
