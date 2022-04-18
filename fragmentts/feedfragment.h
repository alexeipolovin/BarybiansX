//
// Created by Алексей Половин on 18.04.2022.
//

#ifndef BARYBIANSX_FEEDFRAGMENT_H
#define BARYBIANSX_FEEDFRAGMENT_H

#include "base/basefragment.h"

#include <QScrollArea>
#include <qlabel.h>

class FeedFragment: public BaseFragment {
public:
    FeedFragment();
    void bindData(BaseModel *model) override;

    void bindWebConnector(WebConnector *webConnector) override;

    WebConnector *webConnector;
    QVBoxLayout *menuContainer;
    QVBoxLayout *scrollContainerLayout;
    QScrollArea *scrollArea;
    QWidget *scrolConttent;
    QVBoxLayout *mainContainerLaout;
    QFrame *mainContainerFrame;
    QVBoxLayout *backContainerLaout;
    QFrame *backGradient;
    QHBoxLayout *profilelay;
    QVBoxLayout *namelay;
    QVBoxLayout *headerLayout;
    QLabel *status;
    QLabel *fullName;
    QLabel *lastVisit;
    QLabel *picture;
    void downloadFeed();
};


#endif //BARYBIANSX_FEEDFRAGMENT_H
