#include "userfragment.h"

#include <base/data/data.h>

#include <cwidgets/cardview.h>
UserFragment::UserFragment()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
//    mainLayout->addWidget(new CardView());
    QLabel *mainLabel = new QLabel("Hello, world!");
    mainLabel->setStyleSheet("QLabel {color:black}");
    mainLayout->addWidget(mainLabel);

    setLayout(mainLayout);
}

void UserFragment::bindData(BaseModel *model) {
    User *mainUser = (User*) model;
}

