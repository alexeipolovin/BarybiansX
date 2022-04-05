#include "webservice.h"

WebService::WebService()
{
    webConnector = new WebConnectorX(true);
}

void WebService::makeAuth() {
    webConnector->sendAuth("Test", "TEST");
//    connect(webConnector, &WebConnectorX::tokenApproved, this, &WebService::getToken);
}

void WebService::getToken() {
    this->token = webConnector->getToken();
    qDebug() << "This token";
//    emit changeRootScreen();
}
