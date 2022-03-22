#include "requestx.h"
#include "webconnectorx.h"

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

}

void WebConnectorX::sendRequest(RequestX *requester)
{
    qDebug()<< "oskdflk";
}


