#ifndef REQUESTX_H
#define REQUESTX_H

#include "webconnectorx.h"

#include <QNetworkRequest>



class RequestX : public QNetworkRequest
{
public:
    RequestX(QString url, WebConnectorX::REQUEST_TYPE type);

    const QByteArray &getData() const;
    void setData(const QByteArray &newData);

    const QString &getUrl() const;
    void setUrl(const QString &newUrl);

    int getId() const;
    void setId(int newId);

    WebConnectorX::REQUEST_TYPE getType() const;
    void setType(WebConnectorX::REQUEST_TYPE newType);

private:
    QString url;
    QByteArray data = nullptr;

    WebConnectorX::REQUEST_TYPE type;

    int id = -1;


};

#endif // REQUESTX_H
