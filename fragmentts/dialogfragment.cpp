//
// Created by Алексей Половин on 08.04.2022.
//

#include "dialogfragment.h"
#include "cwidgets/addition/cardwidget.h"

DialogFragment::DialogFragment() {
    auto *mainLayout = new QVBoxLayout();
    CardWidget *cardWidget = new CardWidget();
    mainLayout->addWidget(cardWidget);
    this->setLayout(mainLayout);
}

DialogFragment::~DialogFragment() = default;