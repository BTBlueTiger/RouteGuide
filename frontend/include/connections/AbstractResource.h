#ifndef ABSTRACTRESOURCE_H
#define ABSTRACTRESOURCE_H

#include <QObject>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qnetworkrequestfactory.h>

#include <QtQml/qqml.h>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qnetworkrequestfactory.h>
#include <QtCore/qobject.h>

class AbstractResource : public QObject
{
    Q_OBJECT

public:
    explicit AbstractResource(QObject *parent = nullptr) : QObject (parent)
    {}

    virtual ~AbstractResource() = default;

    void setAccessManager(std::shared_ptr<QRestAccessManager> manager)
    {
        m_manager = manager;
    }

    void setServiceApi(std::shared_ptr<QNetworkRequestFactory> serviceApi)
    {
        m_api = serviceApi;
    }

protected:
    std::shared_ptr<QRestAccessManager> m_manager;
    std::shared_ptr<QNetworkRequestFactory> m_api;
};



#endif // ABSTRACTRESOURCE_H
