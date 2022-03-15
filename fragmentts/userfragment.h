#ifndef USERFRAGMENT_H
#define USERFRAGMENT_H

#include <base/basefragment.h>

#include <QLabel>



class UserFragment : public BaseFragment
{
private:
    QVBoxLayout *mainLay;
    QVBoxLayout *nameStatLay;

    QHBoxLayout *userInfoLay;

    QLabel userPhoto;
    QLabel userName;
    QLabel status;

public:
    UserFragment();
    void bindData(BaseModel *model);
};

#endif // USERFRAGMENT_H
