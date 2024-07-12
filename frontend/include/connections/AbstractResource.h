#ifndef ABSTRACTRESOURCE_H
#define ABSTRACTRESOURCE_H

#include <QObject>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qnetworkrequestfactory.h>

#include <QFuture>
#include <QPromise>

#include <QtQml/qqml.h>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qnetworkrequestfactory.h>
#include <QtCore/qobject.h>

#include <QtNetwork/qhttpheaders.h>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qrestreply.h>

#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>

class AbstractResource : public QObject
{
    Q_OBJECT

protected:
    std::shared_ptr<QNetworkAccessManager> m_manager;
    std::shared_ptr<QNetworkRequestFactory> m_api;
    std::shared_ptr<QUrl> url;
    std::shared_ptr<QHttpHeaders> headers;

public:
    explicit AbstractResource(QObject *parent = nullptr) : QObject (parent)
    {
        url = std::make_shared<QUrl>();
        headers = std::make_shared<QHttpHeaders>();
        setAccessManager(std::make_shared<QNetworkAccessManager>());
        setServiceApi(std::make_shared<QNetworkRequestFactory>());
    }

    virtual ~AbstractResource() = default;

    void setAccessManager(std::shared_ptr<QNetworkAccessManager> manager)
    {
        m_manager = manager;
    }

    void setServiceApi(std::shared_ptr<QNetworkRequestFactory> serviceApi)
    {
        m_api = serviceApi;
    }


    std::unique_ptr<QByteArray> qVariantMapToQByteArray(const QVariantMap& data)
    {
        QJsonDocument doc = QJsonDocument::fromVariant(data);
        return std::make_unique<QByteArray>(doc.toJson());
    }

    QNetworkReply* postRequest(const QByteArray& data, const QNetworkRequest& request)
    {
        return m_manager->post(request, data);
    }

   QNetworkReply* getRequest(const QNetworkRequest& request)
    {
        return m_manager->get(request);
    }


};



#endif // ABSTRACTRESOURCE_H
