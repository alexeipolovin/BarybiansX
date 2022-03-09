#include "loginfragment.h"

#include <QGraphicsOpacityEffect>
#include <QLineEdit>
#include <QPalette>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QResizeEvent>
#include <QSvgWidget>
#include <qfont.h>
#include <qlabel.h>
#include <qpushbutton.h>

#include "cwidgets/implfragmentfactory.h"
#include <QCoreApplication>
#include <QDateTime>



using namespace screens;

const QString FONT_SIZE = "font-size: 15px;";
const int STANDART_ANIMATION_DURATION = 1500;
const float STANDART_START_ANIMATION_VALUE = 0.0;
const float STANDART_END_ANIMATION_VALUE = 1.0;
const QString DB_NAME = "sqlite.db";

/**
  * @brief LoginFragment::LoginFragment
  *
  * @param *parent
  *
  * Класс, который выполняет все основные действия для построения разметки окна входа и реализующий все функции входа, в том числе и автоподключение к бд;
  *
  * @author Polovin Alexei (alexeipolovin@gmail.com)
  *
*/

LoginFragment::LoginFragment() {
    this->setStyleSheet("QFrame {background-color:#1e2327;}");
    ifExist = false;

    settings = new QSettings("settings.ini", QSettings::IniFormat); // создаётся/открывается файл настроек

    if (settings->value("login").toString() != "" and settings->value("passwd").toString() != "") // если в файле настроек находятся переменные отвечающие за логин, то они считываются
    {
        this->username = settings->value("login").toString();
        this->password = settings->value("passwd").toString();

        tokenStatus = true;

//        this->openMainWindow(); // сразу идёт переход к главному окну

        hide();
    }
//    setWindowIcon(QIcon(":/static/images/flex.png"));

    auto *centerContainer = new QFrame();

    QPixmap logo(":/drawable/flex.png");


    auto *mainHLayout = new QHBoxLayout();
    auto *buttonContainer = new QHBoxLayout();

    auto *mainLayout = new QVBoxLayout();
    auto *centerLayout = new QVBoxLayout();

    loginEdit = new QLineEdit();
    passwordEdit = new QLineEdit();

    auto *logoIcon = new QLabel();
    auto *loginTextLabel = new QLabel("<span style = 'font-size: 20px; color: black;'>LOGIN</span>");
    passwordLabel = new QLabel("<span style='font-size:15px; color: black;'>Password</span>");
    loginLabel = new QLabel("<span style='font-size:15px; color: black;'>Username</span>");

    loginButton = new QPushButton("Login");

    QLinearGradient buttonGradient(0,0,0,loginButton->height());
    buttonGradient.setColorAt(0, QColor("#FF512F"));
    buttonGradient.setColorAt(1, QColor("#DD2476"));

    QPalette buttonPalette;

    buttonPalette.setBrush(QPalette::Background, buttonGradient);
    loginButton->setPalette(buttonPalette);

    QString centerQSS = "QFrame "
                        "{"
                        "background-color: white;"
                        "border-radius: 30px;"
                        "height: 1000px;"
                        "width: 1000px;"
                        "}";

    QString editTextStyle = "QLineEdit "
                            "{"
                            "border: 1px solid #282830;"
                            "color: white;"
                            "font-size: 15px;"
                            "height:17px;"
                            "width:400px;"
                            "margin-left:20px;"
                            "margin-right:20px;"
                            "border-radius:10px;"
                            "padding:5px;"
                            "background-color:#1e2327;"
                            "}";

    QString buttonStyle = "QPushButton"
                          "{"
                          "color: white;"
                          "background-color: black;"
                          "margin-bottom:20px;"
                          "margin-top:20px;"
                          "border:none;"
                          "height:20px;"
                          "width:100px;"
                          "padding:5px;"
                          "border-radius: 10px;"
                          "}";
    QString labelStyle = "QLabel "
                         "{"
                         "color: black;"
                         "margin-left:20px;"
                         "margin-right:20px;"
                         "}";

    logoIcon->setPixmap(logo);
    logoIcon->setAlignment(Qt::AlignCenter);

    loginTextLabel->setAlignment(Qt::AlignCenter);
    loginTextLabel->setStyleSheet(labelStyle + "margin-top: 20px");

    loginEdit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    loginEdit->setFont(QFont("Arial"));
    passwordEdit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    loginLabel->setStyleSheet(labelStyle + "margin-top: 20px");
    loginLabel->setAlignment(Qt::AlignCenter);
    loginLabel->setFont(QFont("Arial", 12));

    passwordLabel->setStyleSheet(labelStyle + "margin-top: 20px");
    passwordLabel->setAlignment(Qt::AlignCenter);
    passwordLabel->setFont(QFont("JetBrains Mono", 12));

    loginEdit->setStyleSheet(editTextStyle);
    passwordEdit->setStyleSheet(editTextStyle);
    passwordEdit->setEchoMode(QLineEdit::Password);

    buttonContainer->addWidget(loginButton);
    buttonContainer->setAlignment(Qt::AlignCenter);

    loginButton->setStyleSheet(buttonStyle);
    loginButton->setFont(QFont("Arial", 12));

    centerLayout->addWidget(logoIcon);
    centerLayout->addWidget(loginLabel);
    centerLayout->addWidget(loginEdit);
    centerLayout->addWidget(passwordLabel);
    centerLayout->addWidget(passwordEdit);
    centerLayout->addLayout(buttonContainer);
    centerLayout->setAlignment(Qt::AlignCenter);

    centerContainer->setStyleSheet(centerQSS);
    centerContainer->setLayout(centerLayout);
    mainHLayout->addWidget(centerContainer);
    mainHLayout->setAlignment(Qt::AlignCenter);

    mainLayout->addLayout(mainHLayout);
    mainLayout->setAlignment(Qt::AlignCenter);

    this->setLayout(mainLayout);


//    connect(loginButton, SIGNAL(clicked()), SLOT(openMainWindow()));
}



/**
  * @brief LoginFragment::resizeEvent
  *
  * @param event
  *
  * Функция вызывается каждый раз при изменении размера онка. Создаёт и запускает все анимации
  *
  * @author Polovin Alexei (alexeipolovin@gmail.com)
*/

//void LoginFragment::resizeEvent(QResizeEvent *event) {
//    auto *eEffect = new QGraphicsColorizeEffect(loginButton);

//    auto *loginFadeEffect = new QGraphicsOpacityEffect(loginEdit);
//    auto *passwordFadeEffect = new QGraphicsOpacityEffect(passwordEdit);
//    auto *loginLabelFadeEffect = new QGraphicsOpacityEffect(loginLabel);
//    auto *passwordLabelFadeEffect = new QGraphicsOpacityEffect(passwordLabel);

//    loginEdit->setGraphicsEffect(loginFadeEffect);
//    passwordEdit->setGraphicsEffect(passwordFadeEffect);
//    loginLabel->setGraphicsEffect(loginLabelFadeEffect);
//    passwordLabel->setGraphicsEffect(passwordLabelFadeEffect);

//    auto *loginAnimation = new QPropertyAnimation(loginFadeEffect, "opacity");
//    auto *passwordAnimation = new QPropertyAnimation(passwordFadeEffect, "opacity");
//    auto *loginLabelAnimation = new QPropertyAnimation(loginLabelFadeEffect, "opacity");
//    auto *passwordLabelAnimation = new QPropertyAnimation(passwordLabelFadeEffect, "opacity");

//    loginAnimation->setEasingCurve(QEasingCurve::InOutQuad);
//    passwordAnimation->setEasingCurve(QEasingCurve::InOutQuad);
//    loginLabelAnimation->setEasingCurve(QEasingCurve::InOutQuad);
//    passwordLabelAnimation->setEasingCurve(QEasingCurve::InOutQuad);

//    loginAnimation->setDuration(STANDART_ANIMATION_DURATION);
//    passwordAnimation->setDuration(STANDART_ANIMATION_DURATION);
//    loginLabelAnimation->setDuration(STANDART_ANIMATION_DURATION);
//    passwordLabelAnimation->setDuration(STANDART_ANIMATION_DURATION);

//    loginAnimation->setStartValue(STANDART_START_ANIMATION_VALUE);
//    passwordAnimation->setStartValue(STANDART_START_ANIMATION_VALUE);
//    loginLabelAnimation->setStartValue(STANDART_START_ANIMATION_VALUE);
//    passwordLabelAnimation->setStartValue(STANDART_START_ANIMATION_VALUE);

//    loginAnimation->setEndValue(STANDART_END_ANIMATION_VALUE);
//    passwordAnimation->setEndValue(STANDART_END_ANIMATION_VALUE);
//    loginLabelAnimation->setEndValue(STANDART_END_ANIMATION_VALUE);
//    passwordLabelAnimation->setEndValue(STANDART_END_ANIMATION_VALUE);

//    passwordAnimation->start();
//    loginAnimation->start();
//    loginLabelAnimation->start();
//    passwordLabelAnimation->start();

//    QPalette pallete;

//    QLinearGradient gradient(0,0,0, 1280);

//    gradient.setColorAt(0, QColor("#AA076B"));
//    gradient.setColorAt(1, QColor("#61045F"));

//    pallete.setBrush(QPalette::Background, gradient);
//    setPalette(pallete);

//    this->resizeEvent(event);
//}

