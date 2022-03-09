#ifndef SEARCHGROUPFRAGMENT_H
#define SEARCHGROUPFRAGMENT_H

#include <base/basefragment.h>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QSettings>
#include <QVBoxLayout>
#include <QWidget>




class LoginFragment: public BaseFragment {
    Q_OBJECT

private:
    QVBoxLayout *mainVLayout;

public:
//    void resizeEvent(QResizeEvent *event) override;

    LoginFragment();

    void checkMainWindow();

    QLabel *passwordLabel;
    QLabel *loginLabel;

    QSettings *settings;

    QLineEdit *loginEdit;
    QLineEdit *passwordEdit;

    QPushButton *loginButton;

    QString username;
    QString password;


    bool tokenStatus;

    bool ifExist{};
public slots:

//    void openMainWindow();

};

#endif // SEARCHGROUPFRAGMENT_H
