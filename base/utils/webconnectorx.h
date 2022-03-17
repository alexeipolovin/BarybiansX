#ifndef WEBCONNECTORX_H
#define WEBCONNECTORX_H

#include "requestx.h"

#include <QNetworkAccessManager>



class WebConnectorX
{
public:
    enum REQUEST_TYPE {
        AUTH,
    };
    WebConnectorX(bool showDebug = false);

    void sendAuth(QString login, QString password);

    RequestX *createRequest(WebConnectorX::REQUEST_TYPE type);
    void sendRequest(RequestX *requester);
private:
    QNetworkAccessManager *manager;

    bool showDebug;

    QString login;
    QString password;

    QString token;
};

#endif // WEBCONNECTORX_H
