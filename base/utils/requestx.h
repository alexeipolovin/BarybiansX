#ifndef REQUESTX_H
#define REQUESTX_H

#include <QNetworkRequest>
#include "base/data/constants.h"


class RequestX : public QNetworkRequest
{
public:
    RequestX(QString url, REQUEST_TYPE type);

    const QByteArray &getData() const;
    void setData(const QByteArray &newData);

    const QString &getUrl() const;
    void setUrl(const QString &newUrl);

    int getId() const;
    void setId(int newId);

    REQUEST_TYPE getType() const;
    void setType(REQUEST_TYPE newType);

private:
    QString url;
    QByteArray data = nullptr;

    REQUEST_TYPE type;

    int id = -1;


};

#endif // REQUESTX_H
