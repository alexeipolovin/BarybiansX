#include "requestx.h"


RequestX::RequestX(QString url, REQUEST_TYPE type)
{
    this->url = url;
    this->setUrl(this->url);
    this->type = type;
    request = new QNetworkRequest(url);
}

const QByteArray &RequestX::getData() const
{
    return data;
}

void RequestX::setData(const QByteArray &newData)
{
    data = newData;
}

const QString &RequestX::getUrl() const
{
    return url;
}

void RequestX::setUrl(const QString &newUrl)
{
    url = newUrl;
}

int RequestX::getId() const
{
    return id;
}

void RequestX::setId(int newId)
{
    id = newId;
}

REQUEST_TYPE RequestX::getType() const
{
    return type;
}

void RequestX::setType(REQUEST_TYPE newType)
{
    type = newType;
}
