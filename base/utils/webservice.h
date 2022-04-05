#ifndef WEBSERVICE_H
#define WEBSERVICE_H

#include "webconnectorx.h"

#include <QObject>

class WebService : public QObject
{
public:
    WebService();
    void makeAuth();
    void getFeed();
    void createRequest();
public slots:
    void getToken();
private:
    QString token;
    WebConnectorX *webConnector;


};

#endif // WEBSERVICE_H
