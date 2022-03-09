#include "loginfragment.h"

#include <QSvgWidget>
#include <qlabel.h>
#include <qpushbutton.h>

#include "cwidgets/implfragmentfactory.h"
#include <QCoreApplication>
#include <QDateTime>



using namespace screens;

LoginFragment::LoginFragment() {

    // главный контейнер
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    mainVLayout->setAlignment(Qt::AlignCenter);
    mainHLayout->setAlignment(Qt::AlignHCenter);

    // отображение исходного кода
    auto label = new QLabel("Test");
    label->setStyleSheet("QLabel { color:black;"
                         "}");
    mainVLayout->addWidget(label);
    mainHLayout->addLayout(mainVLayout);

    this->setLayout(mainHLayout);
    this->setObjectName("fragment");
}


