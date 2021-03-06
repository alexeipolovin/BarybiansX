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
#include <base/utils/webconnector.h>




class LoginFragment: public BaseFragment {
    Q_OBJECT

private:
    QVBoxLayout *mainVLayout;
    WebConnector *webConnector;

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
    void saveToSettings() const;
//    void resize(QResizeEvent *event) override;
public slots:
    void sendAuthRequest();
    void openMainWindow();
    void showTokenError();

};

#endif // SEARCHGROUPFRAGMENT_H
