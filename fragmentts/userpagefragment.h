#ifndef USERPAGEFRAGMENT_H
#define USERPAGEFRAGMENT_H

#include <base/basefragment.h>

#include <QLabel>
#include <QScrollArea>



class UserPageFragment:public BaseFragment
{
public:
    UserPageFragment();
    void bindData(BaseModel *model);

    void downloadFeed();
private:
    QVBoxLayout *headerLayout;
    QScrollArea *scrollArea;
    QVBoxLayout *scrollContainerLayout;
    QWidget *scrolConttent;
    QVBoxLayout *mainContainerLaout;
    QFrame *mainContainerFrame;
    QVBoxLayout *backContainerLaout;
    QFrame *backGradient;
    QHBoxLayout *profilelay;
    QVBoxLayout *menuContainer;
    QVBoxLayout *namelay;

    QLabel *fullName;
    QLabel *status;
    QLabel *picture;
    QLabel *lastVisit;
};

#endif // USERPAGEFRAGMENT_H
