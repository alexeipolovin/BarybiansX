#ifndef WEBCONNECTORX_H
#define WEBCONNECTORX_H

#include "requestx.h"

#include <QNetworkAccessManager>
#include <base/data/constants.h>

class WebConnectorX
{
public:
    WebConnectorX(bool showDebug = false);

    void sendAuth(QString login, QString password);

    RequestX *createRequest(REQUEST_TYPE type);
    void sendRequest(RequestX *requester);
private:
    QNetworkAccessManager *manager;

    bool showDebug;

    QString login;
    QString password;

    QString token;
};

#endif // WEBCONNECTORX_H
