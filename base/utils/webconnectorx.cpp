#include "requestx.h"
#include "webconnectorx.h"

#include <QNetworkReply>
#include <QSettings>
#include <QObject>

WebConnectorX::WebConnectorX(bool showDebug)
{
    manager = new QNetworkAccessManager();

    this->showDebug = showDebug;

}

void WebConnectorX::sendAuth(QString login, QString password) {
    this->login = qMove(login);
    this->password = qMove(password);

    RequestX *requester = createRequest(AUTH);
    sendRequest(requester);
}


RequestX *WebConnectorX::createRequest(REQUEST_TYPE type) {
    RequestX *request;
    switch(type) {
    case AUTH:
        request = new RequestX("https://api.barybians.ru/v2/auth", AUTH);
        break;
    }
    return request;
}

void WebConnectorX::checkSettingsLoginPass() {
    QSettings *settings = new QSettings();
    this->login = settings->value("LOGIN").toString();
    this->password = settings->value("PASSWORD").toString();
    if(login == "" and password == "") {
        return;
    }
    this->sendAuth(this->login, this->password);
}

const QString &WebConnectorX::getToken() const
{
    return token;
}

void WebConnectorX::setToken(const QString &newToken)
{
    token = newToken;
}

void WebConnectorX::sendRequest(RequestX *requester)
{
    QNetworkReply *reply;
    switch(requester->getType()) {
        case AUTH:
            reply = manager->get(*requester->request);
            break;
    }

    connect(reply, &QNetworkReply::finished, this, [reply]() {
        qDebug() << reply->readAll();
        reply->deleteLater();
    });
}


