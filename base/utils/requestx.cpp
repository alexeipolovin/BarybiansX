#include "requestx.h"


RequestX::RequestX(QString url, WebConnectorX::REQUEST_TYPE type)
{
    this->url = url;
    this->setUrl(this->url);
    this->type = type;
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

WebConnectorX::REQUEST_TYPE RequestX::getType() const
{
    return type;
}

void RequestX::setType(WebConnectorX::REQUEST_TYPE newType)
{
    type = newType;
}
